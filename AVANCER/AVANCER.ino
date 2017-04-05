//Moteur Gauche 
int MoteurG = 10;
int MGR = 9;
int MGN = 8;
//Moteur droit 
int MoteurD = 5;
int MDR = 7;
int MDN = 6;


void setup() {
  	// put your setup code here, to run once:
	pinMode(MoteurG, OUTPUT);
	pinMode(MoteurD, OUTPUT);
	pinMode(MGR, OUTPUT);
	pinMode(MGN, OUTPUT);
	pinMode(MDR, OUTPUT);
	pinMode(MDN, OUTPUT);
}

void Avancer() {
  digitalWrite(MGR, HIGH);
  digitalWrite(MGN, LOW);
  digitalWrite(MDR, HIGH);
  digitalWrite(MDN, LOW);
  	// put your main code here, to run repeatedly:
	analogWrite (MoteurG, 100);
	analogWrite (MoteurD, 130); 
	//Reste a ajouter un delai ou une boucle tant que pour savoir quand s'arrête
delay(2000);
}
void Reculer() {
  digitalWrite(MGR, LOW);
  digitalWrite(MGN, HIGH);
  digitalWrite(MDR, LOW);
  digitalWrite(MDN, HIGH);
    // put your main code here, to run repeatedly:
  analogWrite (MoteurG, 100);
  analogWrite (MoteurD, 130); 
  delay(2000); 
}
void TournerD() {
  digitalWrite(MGR, HIGH);
  digitalWrite(MGN, LOW);
  digitalWrite(MDR, LOW);
  digitalWrite(MDN, HIGH);
    // put your main code here, to run repeatedly:
  analogWrite (MoteurG, 100);
  analogWrite (MoteurD, 130); 
  //Reste a ajouter un delai ou une boucle tant que pour savoir quand s'arrête
delay(2000); 
}
void TournerG() {
  digitalWrite(MGR, LOW);
  digitalWrite(MGN, HIGH);
  digitalWrite(MDR, HIGH);
  digitalWrite(MDN, LOW);
    // put your main code here, to run repeatedly:
  analogWrite (MoteurG, 100);
  analogWrite (MoteurD, 130); 
  //Reste a ajouter un delai ou une boucle tant que pour savoir quand s'arrête
delay(2000); 
}
void loop() {
Avancer(); 
Reculer();
TournerD(); 
TournerG(); 
	

}
