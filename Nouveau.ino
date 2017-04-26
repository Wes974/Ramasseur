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

float tableauDistanceBalles[2];
bool tourCompletEffectue = false;

//Moteur gauche
int moteurG = 10;
int MGR = 9;
int MGN = 8;

//Moteur droite
int moteurD = 5;
int MDR = 7;
int MDN = 6;

Pixy pixy;

void setup() {

    Serial.begin(9600);
    Serial.print("Début...\n");

    pixy.init();

    largeurDistanceFocale = (largeurCalibree * distanceCalibree) / largeurDeObjet;

    Serial.print(largeurDistanceFocale);

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

    delay(100);

}

void reculer() {

    digitalWrite(MGR, LOW);
    digitalWrite(MGN, HIGH);
    digitalWrite(MDR, LOW);
    digitalWrite(MDN, HIGH);

    analogWrite(moteurG, 100);
    analogWrite(moteurD, 130);

    delay(100);

}

void tournerDroite() {

    digitalWrite(MGR, HIGH);
    digitalWrite(MGN, LOW);
    digitalWrite(MDR, LOW);
    digitalWrite(MDN, HIGH);

    analogWrite(moteurG, 0);
    analogWrite(moteurD, 0);

    delay(10);

}

void tournerGauche() {

    digitalWrite(MGR, LOW);
    digitalWrite(MGN, HIGH);
    digitalWrite(MDR, HIGH);
    digitalWrite(MDN, LOW);

    analogWrite(moteurG, 70);
    analogWrite(moteurD, 75);

    delay(25);

}

void tournerGaucheDroit() {
    // Sens
    digitalWrite(MGR, LOW);
    digitalWrite(MGN, HIGH);
    digitalWrite(MDR, HIGH);
    digitalWrite(MDN, LOW);

    // Vitesse
    analogWrite(moteurG, 100);
    analogWrite(moteurD, 126);

    // Durée
    delay(420);
}

void stop() {

    digitalWrite(MGR, HIGH);
    digitalWrite(MGN, LOW);
    digitalWrite(MDR, HIGH);
    digitalWrite(MDN, LOW);

    analogWrite(moteurG, 0);
    analogWrite(moteurD, 0);

    delay(100);

}

void loop() {

    //static int i = 0;
    uint16_t blocks;
    // char buf[32];
    int j;
    //float distanceLargeur;
    //int largeurPixel;

    //int distanceLaPlusProche = 100;

    blocks = pixy.getBlocks();
/* SAM
    // Calcul de la distance
    for (j = 0; j < blocks; j++) {
        largeurPixel = pixy.blocks[j].width;
        distanceLargeur = (largeurDeObjet * largeurDistanceFocale) / largeurPixel;
        Serial.print("Calcul de la distance\n");
    }

    if  (blocks || distanceLargeur < 60) {

     tournerDroite();
        blocks = pixy.getBlocks();
    }
 else if (blocks || distanceLargeur > 60 ) {
      avancer();
        blocks = pixy.getBlocks();
 }
*/

    if (blocks || distanceLargeur < 30) {
        stop();
        blocks = pixy.getBlocks();
    } else if (blocks || distanceLargeur > 60) {
        avancer();
        blocks = pixy.getBlocks();
    }

    if (blocks) {

        if (pixy.blocks[j].x > 138) {

            if (pixy.blocks[j].x < 188) {

                // Calcul de la distance
                for (j = 0; j < blocks; j++) {
                    largeurPixel = pixy.blocks[j].width;
                    distanceLargeur = (largeurDeObjet * largeurDistanceFocale) / largeurPixel;
                    Serial.print("Calcul de la distance\n");
                }

                if (distanceLargeur < 30) {
                    stop();
                    blocks = pixy.getBlocks();
                } else if (distanceLargeur > 30) {
                    avancer();
                    delay(100);
                    blocks = pixy.getBlocks();
                }

            } else {
                tournerDroite();
            }

        } else {
            tournerGauche();
        }

    } else {
        stop();
        blocks = pixy.getBlocks();
        delay(100);
    }

/*        // Calcul de la distance
        for (j = 0; j < blocks; j++) {
            largeurPixel = pixy.blocks[j].width;
            distanceLargeur = (largeurDeObjet * largeurDistanceFocale) / largeurPixel;
            Serial.print("Calcul de la distance\n");
            delay(50);
        }
    }

        stop();
        blocks = pixy.getBlocks();

        // Calcul de la distance
        for (j = 0; j < blocks; j++) {
            largeurPixel = pixy.blocks[j].width;
            distanceLargeur = (largeurDeObjet * largeurDistanceFocale) / largeurPixel;
            Serial.print("Calcul de la distance\n");
            delay(50);
        }

*/

    /*  if (pixy.blocks[j].x < 140) {

        Serial.print("Aller à gauche\n");
        gauche();

      } else if (pixy.blocks[j].x > 160) {

      Serial.print("Aller à droite\n");
      droite();

    }




    if (blocks) {

        avancer();
        blocks = pixy.getBlocks();

    } else if (!blocks) {

        stop();
        blocks = pixy.getBlocks();

    }




    if (blocks) {

        if (pixy.blocks[j].x < 140) {
          Serial.print("Aller à gauche\n");
          tournerGauche();
          delay(100);
        } else if (pixy.blocks[j].x > 170) {
          Serial.print("Aller à droite\n");
          tournerDroite();
          delay(100);
        }
        blocks = pixy.getBlocks();
      } else if (!blocks) {
        stop();
        blocks = pixy.getBlocks();
       }
*/

/* if (blocks) {
    Serial.print("Balle vue\n");

    if (pixy.blocks[j].x > 138) {
      Serial.print("Balle x < 140\n");

      if (pixy.blocks[j].x < 188) {
        Serial.print("Balle x > 170\n");
        delay(1000);
        avancer();
        Serial.print("Avancer\n");
        delay(100);
        blocks = pixy.getBlocks();
      } else {
        tournerDroite();
        //delay(100);
      }

    Serial.print("Balle pas à 170\n");
    } else {
      tournerGauche();
      //delay(100);
    }

  Serial.print("Balle pas à 140\n");
  } else {
    Serial.print("Stop\n");
    stop();
    blocks = pixy.getBlocks();
    delay(100);
  }
    }
    else if  (blocks || distanceLargeur > 60) {
      stop();
    }
    }
    }
*/
}
