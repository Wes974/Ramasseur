#include <Arduino.h>
#include <SPI.h>
#include <Pixy.h>

//Moteur gauche
int moteurG = 10;
int MGR = 9;
int MGN = 8;

//Moteur droite
int moteurD = 5;
int MDR = 7;
int MDN = 6;

// Configure la caméra
Pixy pixy;

void setup() {

    Serial.begin(9600);
    Serial.print("Début...\n");

    // Initialise la caméra
    pixy.init();

    // Moteur
    pinMode(moteurG, OUTPUT);
    pinMode(moteurD, OUTPUT);
    pinMode(MGR, OUTPUT);
    pinMode(MGN, OUTPUT);
    pinMode(MDR, OUTPUT);
    pinMode(MDN, OUTPUT);

}

void avancer() {

    // Sens
    digitalWrite(MGR, HIGH);
    digitalWrite(MGN, LOW);
    digitalWrite(MDR, HIGH);
    digitalWrite(MDN, LOW);

    // Vitesse
    analogWrite(moteurG, 100);
    analogWrite(moteurD, 130);

    // Durée
    delay(100);

}

void tournerDroite() {

    // Sens
    digitalWrite(MGR, HIGH);
    digitalWrite(MGN, LOW);
    digitalWrite(MDR, LOW);
    digitalWrite(MDN, HIGH);

    // Vitesse
    analogWrite(moteurG, 80);//70);
    analogWrite(moteurD, 0);//70);

}

void tournerGauche() {

    // Sens
    digitalWrite(MGR, LOW);
    digitalWrite(MGN, HIGH);
    digitalWrite(MDR, HIGH);
    digitalWrite(MDN, LOW);

    analogWrite(moteurD, 120);
    delay(10);

    // Vitesse
    analogWrite(moteurG, 0);//70);
    analogWrite(moteurD, 80);//70);

}

void stop() {

    // Sens
    digitalWrite(MGR, HIGH);
    digitalWrite(MGN, LOW);
    digitalWrite(MDR, HIGH);
    digitalWrite(MDN, LOW);

    // Vitesse
    analogWrite(moteurG, 0);
    analogWrite(moteurD, 0);

}

void loop() {

    // Crée varibles
    uint16_t blocks;
    int j;

    // Récupère ce que la caméra voit
    blocks = pixy.getBlocks();

    // Si balle détectée
    if (blocks) {

        // Regarde si aligné coté gauche
        if (pixy.blocks[j].x > 138) {

            // Regarde si aligné coté droit
            if (pixy.blocks[j].x < 188) {

                // Si la taille de la balle est < 18 px
                if (pixy.blocks[j].width < 48 && pixy.blocks[j].height < 20) {
                    avancer();
                    blocks = pixy.getBlocks();
                } else if (pixy.blocks[j].height > 18) {
                    stop();
                    blocks = pixy.getBlocks();
                }

            } else {
                tournerDroite();
                delay(50);
                stop();
            }

        } else {
            tournerGauche();
            delay(50);
            stop();
        }

    } else {
        stop();
        blocks = pixy.getBlocks();
        delay(100);
    }

}
