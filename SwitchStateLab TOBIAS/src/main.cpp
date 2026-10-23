#include <Arduino.h>
//headers
//Sensor Trig og Echo pins
const int trigA_pin = 9;
const int trigB_pin = 11;
const int echoA_pin = 10;
const int echoB_pin = 12;
//Lengde og avstandsvariabler
float durationA, distanceA;
float durationB, distanceB;

//Gjennomsnittsmålinger
float gjennomsnittA;
float gjennomsnittB;



//Knapper 
const int knappEn = 8;
  const int knappTo = 7;
  int toggleEn = 0; 
  int toggleTo = 0;
    
  unsigned long startMillis;
  unsigned long currentMillis;
  const unsigned long period = 500;
///
void setup() {
  Serial.begin(9600);
  pinMode(trigA_pin,OUTPUT);
  pinMode(echoA_pin,INPUT);
  pinMode(knappEn, INPUT_PULLUP);
  pinMode(knappTo, INPUT_PULLUP);
  startMillis = millis();  

}
void loop() {
    currentMillis = millis();
    if (digitalRead(knappEn) == LOW && currentMillis - startMillis >= period){
        toggleEn ++;
        if (toggleEn == 2){
            toggleEn = 0;
        }
        startMillis = currentMillis;
    }
    if (toggleTo == 0 || toggleTo == 1){
        switch(toggleEn) {
            case 0:
                Serial.println("sensor modus 1");
                break;
            case 1:
                Serial.println("sensor modus 2");
                break;
        }
    }  
    if (toggleTo == 2){
        switch(toggleEn) {
            case 0:
                Serial.println("Motor FRAM");
                break;
            case 1:
                Serial.println("Motor BAK");
                break;
        }
    }  
    if (digitalRead(knappTo) == LOW && currentMillis - startMillis >= period){
        toggleTo ++;
        if (toggleTo == 3){
            toggleTo = 0;
        }
        startMillis = currentMillis;
    }
    switch(toggleTo) {
        case 0:
            Serial.print("case 1");
            SensorA_bootup();
            break;
        case 1:
            Serial.print("case 2");
            SensorB_bootup();
            break;
        case 2:
            Serial.print("case 3");
            break;
    }
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

