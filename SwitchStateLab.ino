int SensorA_data;
int SensorA_pin = A0;
int SensorB_data;
int SensorB_pin = A1;


void setup() {
Serial.begin(9600);
}

void loop() {
SensorA();
SensorB();


}
void SensorA() {
    SensorA_data = analogRead(SensorA_pin);
    Serial.println(SensorA_data);
}

void SensorB() {
    SensorB_data = analogRead(SensorB_pin);
    Serial.println(SensorB_pin);
}
//Tester GitHub repository for gruppe 12


//For å git commite;
// start med git add .
// got commit -m "kommentar"
// git push -u origin main
