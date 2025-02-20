#include <Wire.h>
#include <HX711.h>
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#define WIFI_SSID "your_wifi_name"
#define WIFI_PASS "your_wifi_password"

#define AIO_SERVER "io.adafruit.com"
#define AIO_USERNAME "your_adafruit_username"
#define AIO_KEY "your_adafruit_key"

#define LOADCELL_DOUT 2
#define LOADCELL_SCK 3

HX711 scale;
WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, 1883, AIO_USERNAME, AIO_KEY);
Adafruit_MQTT_Publish weight_feed = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/weight");

void setup() {
    Serial.begin(115200);
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("WiFi Connected!");

    scale.begin(LOADCELL_DOUT, LOADCELL_SCK);
    scale.set_scale(2280.f); 
    scale.tare();
}

void loop() {
    float weight = scale.get_units(10);
    Serial.print("Weight: ");
    Serial.print(weight);
    Serial.println(" kg");

    if (!mqtt.connected()) {
        if (mqtt.connect()) {
            Serial.println("Connected to Adafruit IO");
        } else {
            Serial.println("MQTT Connection Failed!");
        }
    }

    weight_feed.publish(weight);
    delay(5000);
}
