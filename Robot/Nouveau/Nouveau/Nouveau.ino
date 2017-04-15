#include <Arduino.h>
#include <SPI.h>
#include <Pixy.h>

#define distanceCalibree 30
int largeurCalibree = 38;
int hauteurCalibree = 24;

int largeurPixel;
int distanceLargeur;
float largeurDeObjet = 6;
int largeurDistanceFocale;

// Moteur gauche
int moteurG = 10;
int MGR = 9;
int MGN = 8;

// Moteur droite
int moteurD = 5;
int MDR = 7;
int MDN = 6;

void setup() {

    largeurDistanceFocale = (largeurCalibree * distanceCalibree) / largeurDeObjet;

    // Moteur
    pinMode(moteurG, OUTPUT);
    pinMode(moteurD, OUTPUT);
    pinMode(MGR, OUTPUT);
    pinMode(MGN, OUTPUT);
    pinMode(MDR, OUTPUT);
    pinMode(MDN, OUTPUT);

}

void avancer() {

    digitalWrite(MGR, HIGH);
    digitalWrite(MGN, LOW);
    digitalWrite(MDR, HIGH);
    digitalWrite(MDN, LOW);

    analogWrite(moteurG, 100);
    analogWrite(moteurD, 130);

    delay(1000);

}

void loop {

    avancer();

}
