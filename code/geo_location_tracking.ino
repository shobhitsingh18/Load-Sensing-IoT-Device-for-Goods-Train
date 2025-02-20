#include <AltSoftSerial.h>

AltSoftSerial gpsSerial;

void setup() {
    Serial.begin(115200); 
    gpsSerial.begin(9600);  
}

void loop() {
    while (gpsSerial.available()) {
        char c = gpsSerial.read();
        Serial.write(c);
    }
}
