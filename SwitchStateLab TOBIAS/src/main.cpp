#include <Arduino.h>

const int trigA_pin = 9;
const int trigB_pin = 11;
const int echoA_pin = 10;
const int echoB_pin = 12;

int SensorA_data;
int SensorA_pin = A0;
int SensorB_data;
int SensorB_pin = A1;


void setup() {
Serial.begin(9600);
}

void loop() {
SensorA(); //legges i if sløyfe
SensorB(); //legges i if sløyfe

}
void SensorA() {
    SensorA_data = analogRead(SensorA_pin);
    Serial.println(SensorA_data);
}

void SensorB() {
    SensorB_data = analogRead(SensorB_pin);
    Serial.println(SensorB_data);
}

