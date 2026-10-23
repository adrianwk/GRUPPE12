    #include <Arduino.h>
    const int knappEn = 8;
    const int knappTo = 7;
    int toggleEn = 0;
    int toggleTo = 0;
    
    unsigned long startMillis;
    unsigned long currentMillis;
    const unsigned long period = 500;
    
    void setup() {
        pinMode(knappEn, INPUT_PULLUP);
        pinMode(knappTo, INPUT_PULLUP);
        Serial.begin(9600);
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
                break;
            case 1:
                Serial.print("case 2");
                break;
            case 2:
                Serial.print("case 3");
                break;
        }
    }