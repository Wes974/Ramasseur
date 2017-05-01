#include <Arduino.h>

//Moteur gauche
int moteurG = 10;
int MGR = 9;
int MGN = 8;

//Moteur droite
int moteurD = 5;
int MDR = 7;
int MDN = 6;

void setup() {
    // Moteur
    pinMode(moteurG, OUTPUT);
    pinMode(moteurD, OUTPUT);
    pinMode(MGR, OUTPUT);
    pinMode(MGN, OUTPUT);
    pinMode(MDR, OUTPUT);
    pinMode(MDN, OUTPUT);
}

void loop() {
    // Sens
    digitalWrite(MGR, HIGH);
    digitalWrite(MGN, LOW);
    digitalWrite(MDR, HIGH);
    digitalWrite(MDN, LOW);

    // Vitesse
    analogWrite(moteurG, 255);
    analogWrite(moteurD, 255);
}
