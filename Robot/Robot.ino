#include <Arduino.h>
#include <SPI.h>
#include <Pixy.h>

/// Pour la distance
/*
// A CALIBRER !!!
#define distanceCalibree 11 // en cm

// A CALIBRER !!!
int largeurCalibree = 21; // largeur lue
int hauteurCalibree = 21; // hauteur lue

int largeurPixel; // lue par la caméra
int hauteurPixel; // lue par la caméra
float distanceLargeur; // distance calculée basée sur la largeurPixel
float distanceHauteur; // distance calculée basée sur la hauteur

// A CALIBRER !!!
float largeurDeObjet = 6; // en cm vrai taille de l'objet
float hauteurDeObjet = 6; // en cm vrai taille de l'objet

int largeurDistanceFocale; // distance focale calculée pour la largeur
int hauteurDistanceFocale; // distance focale calculée pour la hauteur
float moyenne;

// Formule : largeurDistanceFocale = (pixels * distanceconnueencm) / largeurDeObjet
// Distance = (largeurDeObjet * largeurDistanceFocale) / largeurPixel
// distance focale et distance pour la hateur calculée de la même façon

/// Fin distance
*/
/// Pour les moteurs

// Moteur 1
int enA = 10;
int in1 = 9;
int in2 = 8;

// Moteur 2
int enB = 5;
int in3 = 7;
int in4 = 6;

Pixy pixy; // Créer pixy

void setup() {
/*
    // Caméra
    Serial.begin(9600);
    Serial.print("Début...\n")
    // Initialise pixycam
    pixy.init();

    // Calcule la distance focale
    largeurDistanceFocale = (largeurCalibree * distanceCalibree) / largeurDeObjet;
    hauteurDistanceFocale = (hauteurCalibree * distanceCalibree) / hauteurDeObjet;
*/
    // Moteur comme sortie
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

}

void demoOne() {
    // this function will run the motors in both directions at a fixed speed
    // turn on motor A
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // set speed to 200 out of possible range 0~255
    analogWrite(enA, 100);
    // turn on motor B
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    // set speed to 200 out of possible range 0~255
    analogWrite(enB, 100);
    delay(3000);
    // now change motor directions
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(3000);
    // now turn off motors
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

/*
void aligne() {
    if (pixy.blocks[j].x < 135) {
        // Aller à gauche
    } else if (pixy.blocks[j].x > 165) {
        // Aller à droite
    }
}

void mesureDistance() {

    sprintf(buf, "Detected %d:\n", blocks);
    Serial.print(buf);
    for (j=0; j<blocks; j++) {

        largeurPixel = pixy.blocks[j].width;
        hauteurPixel = pixy.blocks[j].height;
        distanceLargeur = (largeurDeObjet * largeurDistanceFocale) / largeurPixel;
        distanceHauteur = (hauteurDeObjet * hauteurDistanceFocale) / hauteurPixel;
        moyenne = (distanceLargeur + distanceHauteur) / 2;
        moyenne = round(moyenne);

        Serial.print("Largeur: ");
        Serial.print(largeurPixel);
        Serial.print(" Hauteur: ");
        Serial.print(" Distance L: ");
        Serial.print(distanceLargeur);
        Serial.print("cm");
        Serial.print("Distance H: ");
        Serial.print(distanceHeight);
        Serial.print("cm. Angle:");
        Serial.println(pixy.blocks[j].angle);
        Serial.print("moyenne: ");
        Serial.print(moyenne);
        Serial.print("cm. ");

    }

}

*/

void loop() {

    demoOne();
    delay(1000);

    /*

    static int i = 0;
    int j;
    uint16_t blocks;
    char buf[32]; // ??

    // grab blocks!
    blocks = pixy.getBlocks();

    // If there are detect blocks, print them!
    if (blocks) {

      i++;

      Serial.print(pixy.blocks[j].x);
      Serial.print(" \n");

      if (i%50==0) {

        aligne();

        mesureDistance();

        //avancer

      }
    }

    */

}
