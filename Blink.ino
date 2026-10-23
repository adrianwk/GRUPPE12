#define FWD 2
#define BCK 4
#define SPD 3
void setup() {
    pinMode(FWD, OUTPUT);
    pinMode(BCK, OUTPUT);
}

void loop() {
    delay(100);
    digtalWrite(FWD, HIGH);
    analogWrite(SPD, 50);
}
//Tester GitHub repository for gruppe 12
