"IoT-Based Load Sensing Device for Goods Train"

This project is an IoT-based load sensing system designed to monitor the weight of goods on freight trains in real-time. By integrating load sensors, a GPS module, and Wi-Fi communication using the ESP8266 module, the system continuously tracks cargo weight, detects overload conditions, and alerts operators. The data is transmitted to the cloud using Adafruit IO for remote monitoring and real-time analysis.

The primary goal of this system is to enhance safety, prevent accidents caused by overloaded freight, and optimize logistics by providing real-time weight and location data.

Features:
Real-time Load Monitoring – Measures cargo weight using load sensors.
GPS Tracking – Logs the train's location for logistics optimization.
Wi-Fi Connectivity (ESP8266) – Sends data to the cloud for remote access.
Cloud Storage & Dashboard – Displays data on Adafruit IO in real time.
Overload Alerts – Notifies operators in case of excessive weight.

Components Used:
Microcontroller: Arduino Uno 
Load Sensor + HX711 Module: For weight measurement
GPS Module (NEO-6M): For location tracking
ESP8266 Wi-Fi Module: For cloud communication
Adafruit IO: Cloud platform for data visualization
Buzzer/LED: For overload alerts
Power Supply: 9V or 12V battery
