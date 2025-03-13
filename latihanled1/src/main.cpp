#include <Arduino.h>

int LED = 17;      // LED merah
int LED2 = 4;     // LED kuning
int LED3 = 2;    // LED hijau

void setup() {
    Serial.begin(115200);
    Serial.println("ESP32 Blinking LED");


    pinMode(LED, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
}

void loop() {
    // Nyala merah selama 5 detik
    digitalWrite(LED, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    Serial.println("LED RED ON");

    delay(5000);
    
    // Nyala kuning selama 2 detik
    digitalWrite(LED, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    Serial.println("LED YELLOW ON");

    delay(2000);
    
    // Nyala hijau selama 5 detik
    digitalWrite(LED, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    Serial.println("LED GREEN ON");

    delay(5000);
}