//definition des bibliotéque 
#include <LiquidCrystal.h>

//definition des port
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
#define ENABLE 5
#define DIRA 3
#define DIRB 4
const int CapteurMusculaire = A0;
const int CapteurPression = A1; 

//mise a zero des variables
int ValueCapteurMusculaire = 0;
int ValueCapteurMusculairee2 = 0;
int ValueCapteurPression = 0;
 
void setup() {
  //definition des sortie/entrée
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  pinMode(CapteurMusculaire, INPUT);
  pinMode(CapteurPression, INPUT); 
  //definition de la taille de l'écran
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  //récuperation des valeur
  int ValueCapteurMusculaire = analogRead(CapteurMusculaire);
  delay(2000);
  int ValueCapteurMusculaire2 = analogRead(CapteurMusculaire);
  int ValueCapteurPression = analogRead(CapteurPression); 
  
  //Retour des valeur dans la console
  Serial.println("ValueCapteurMusculaire=");
  Serial.println(ValueCapteurMusculaire);
  Serial.println("ValueCapteurMusculaire2=");
  Serial.println(ValueCapteurMusculaire2);  
  Serial.println("ValueCapteurPression=");
  Serial.println(ValueCapteurPression);
  Serial.println("------------------");

  if (ValueCapteurMusculaire > 500){
    if (ValueCapteurMusculaire2 > 500) {
      //affichage sur l'écran
      lcd.setCursor(0, 0);
      lcd.print("PINCEF,PRESSION-");
      //fermeture de la pince
      digitalWrite(ENABLE,HIGH);
      digitalWrite(DIRA,LOW);
      digitalWrite(DIRB,HIGH);
      if (ValueCapteurPression > 814){
        //affichage sur l'écran
        lcd.setCursor(0, 0);
        lcd.print("PINCER,PRESSION+");
        //arrêt du moteur/arrêt de la fermeture de la pince
        digitalWrite(ENABLE,HIGH);
        digitalWrite(DIRA,LOW);
        digitalWrite(DIRB,LOW);   
      }
    }else{
      //affichage sur l'écran
      lcd.setCursor(0, 0);
      lcd.print("PINCEO,PRESSION-");
      //ouverture de la pince 
      digitalWrite(ENABLE,HIGH);
      digitalWrite(DIRA,HIGH);
      digitalWrite(DIRB,LOW);
      delay(5000);
      //affichage sur l'écran 
      lcd.setCursor(0, 0);
      lcd.print("PINCER,PRESSION-"); 
      //arrêt du moteur/arrêt de l'ouverture de la pince
      digitalWrite(ENABLE,HIGH);
      digitalWrite(DIRA,LOW);
      digitalWrite(DIRB,LOW);     
    } 
  }else{
    if (ValueCapteurPression > 814){
      lcd.setCursor(0, 0);
      lcd.print("PINCER,PRESSION+"); 
    }else{
      lcd.setCursor(0, 0);
      lcd.print("PINCER,PRESSION-"); 
    }
  }
}
//81 ligne de code 
