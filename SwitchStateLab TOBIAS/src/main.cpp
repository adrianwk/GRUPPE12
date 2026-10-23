#include <Arduino.h>

const int trigA_pin = 9;
const int trigB_pin = 11;
const int echoA_pin = 10;
const int echoB_pin = 12;

float durationA, distanceA;
float durationB, distanceB;

int SensorA_data;
int SensorA_pin = A0;
int SensorB_data;
int SensorB_pin = A1;
///
void setup() {
  Serial.begin(9600);
  pinMode(trigA_pin,OUTPUT);
  pinMode(echoA_pin,INPUT);

}

void loop() {
  SensorA_bootup(); //legges i if sløyfe
  SensorB_bootup(); //legges i if sløyfe
}
void SensorA_bootup()
  digitalWrite(trigA_pin,LOW);
  delay(20);
  digitalWrite(trigA_pin,HIGH);
  delay(10)
  digitalWrite(trigA_pin,LOW);
  SensorA();

void SensorA() {
  digitalWrite(trigA_pin,LOW);
  delay(20);
  digitalWrite(trigA_pin,HIGH);
  delay(10);
  digitalWrite(trigA_pin,LOW);

  durationA = pulseIn(echoA_pin,HIGH);
  distanceA = (durationA * 0.0343) / 2;
  Serial.println("Avstand:");
  Serial.println(distanceA);
  delay(100);
}

void SensorB_bootup() {
  digitalWrite(trigB_pin,LOW);
  delay(20);
  digitalWrite(trigB_pin,HIGH);
  delay(10)
  digitalWrite(trigB_pin,LOW);

  SensorB();
}

void SensorB() {
   durationB = pulseIn(echoB_pin,HIGH);
   distanceB = (duration * 0.0343) / 2;
   Serial.println("Avstand:");
  Serial.println(distanceB);
  delay(100);
}

