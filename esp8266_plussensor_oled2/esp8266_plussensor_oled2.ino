#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define OLED_Address 0x3C // I2C address of OLED display
Adafruit_SSD1306 oled(128, 64, &Wire, -1); // Create OLED display object

int a = 0;
int lasta = 0;
int lastb = 0;
int LastTime = 0;
int ThisTime;
bool BPMTiming = false;
bool BeatComplete = false;
int BPM = 0;

#define UpperThreshold 560
#define LowerThreshold 530

void setup() {
    Serial.begin(115200);

    // Initialize the OLED display
    if (!oled.begin(SSD1306_SWITCHCAPVCC, OLED_Address)) { // Corrected initialization
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);
    }

    oled.clearDisplay();
    oled.setTextSize(2);
    oled.setTextColor(WHITE);
    oled.display();
}

void loop() {
    if (a > 127) {
        oled.clearDisplay();
        a = 0;
        lasta = a;
    }

    ThisTime = millis();
    int value = analogRead(A0); // Ensure this matches your wiring

    // Draw line
    int b = 60 - (value / 16);
    oled.drawLine(lasta, lastb, a, b, WHITE);
    lastb = b;
    lasta = a;

    // BPM calculation logic
    if (value > UpperThreshold) {
        if (BeatComplete) {
            BPM = ThisTime - LastTime;
            BPM = int(60 / (float(BPM) / 1000));
            BPMTiming = false;
            BeatComplete = false;
            tone(5, 1000, 250); // Change 8 to a valid GPIO pin like 5 (D1)
        }
        if (BPMTiming == false) {
            LastTime = millis();
            BPMTiming = true;
        }
    }
    if ((value < LowerThreshold) && BPMTiming) {
        BeatComplete = true;
    }

    // Display BPM
    oled.fillRect(0, 50, 128, 16, BLACK); // Clear the BPM area
    oled.setCursor(0, 50);
    oled.print(F("BPM: "));
    oled.print(BPM);

    oled.display(); // Update the display
    a++;
}
