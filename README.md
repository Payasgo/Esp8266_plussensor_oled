💓 ESP8266_PlusSensor_OLED

A simple IoT-based health monitoring project that uses an ESP8266 NodeMCU, Pulse Sensor, and OLED Display to measure and display the user's heart rate (BPM) in real-time.

🚀 Project Overview

This project reads heartbeats from a pulse sensor and displays the BPM (Beats Per Minute) on a 0.96" I2C OLED screen. The data is processed in real-time using the ESP8266 board (NodeMCU), which also powers the display and sensor.
🔧 Components Used
Component	Description
ESP8266 (NodeMCU)	Wi-Fi microcontroller board
Pulse Sensor	Heart rate sensor (analog output)
OLED Display	0.96" I2C OLED (SSD1306)
Breadboard	For easy prototyping
Jumper Wires	For connections
USB Cable	To power the ESP8266 and upload code
🔌 Circuit Connections
1. Pulse Sensor to ESP8266
Pulse Sensor Pin	ESP8266 Pin
VCC	3.3V
GND	GND
Signal (OUT)	A0
2. OLED Display to ESP8266
OLED Pin	ESP8266 Pin
VCC	3.3V
GND	GND
SDA	D2 (GPIO4)
SCL	D1 (GPIO5)
📟 Output Display

The OLED display shows:

    A heartbeat waveform (based on analog input)

    Real-time BPM value (e.g., BPM: 75)

🧠 Code Logic

    Initialize OLED display using Adafruit libraries.

    Continuously read analog values from the pulse sensor.

    Calculate BPM using peak detection logic.

    Update OLED display with waveform and BPM.

📦 Arduino Libraries Required

Make sure to install the following libraries via Library Manager:

    Adafruit GFX

    Adafruit SSD1306

    ESP8266WiFi (pre-installed with board)

    TimerOne (optional depending on logic)

💡 Applications

    Basic health monitoring

    DIY fitness gadgets

    IoT-based health dashboards (can integrate Wi-Fi later)

    Educational electronics project for beginners

🔄 Future Enhancements

    Send BPM data to a cloud platform (ThingSpeak, Firebase)

    Add alerts for abnormal BPM

    Display additional vitals (like temperature with a DHT11 sensor)
