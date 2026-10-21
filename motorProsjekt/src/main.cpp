#include <Arduino.h>

#define FWD 2
#define BCK 4
#define SPD 3
void setup() {
    pinMode(FWD, OUTPUT);
    pinMode(BCK, OUTPUT);
}

void loop() {
    delay(1000);
    digitalWrite(FWD, HIGH);
    analogWrite(SPD, 50);
}