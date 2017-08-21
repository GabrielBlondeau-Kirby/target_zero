#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

#define btnUp 3
#define btnDown 4
#define btnBack 5
#define btnSelect 2
int choix = 0;

void setup() {
  lcd.begin(20, 21);

  lcd.clear();
  lcd.setCursor(6,0);
  lcd.print("Menu");
  lcd.setCursor(2,1);
  lcd.print("Target z3r0");
  delay(1500);

  MenuTargetZero();
}

void loop() {
}



void MenuTargetZero() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Jeux");
  lcd.setCursor(8,0);
  lcd.print("Gestion User");
  lcd.setCursor(0,1);
  lcd.print("Réglages");

  delay(500);
  while(1){
    // Play
    if(digitalRead(btnUp) == HIGH){
      MenuGames();
    }

    // Gestion User
    if(digitalRead(btnDown) == HIGH){
      MenuUser();
    }

    // Settings
    if(digitalRead(btnSelect) == HIGH){
      MenuSettings();
    }

    delay(200);
  }
}


void MenuGames(){
  choix = 0;
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("> Stand");
  lcd.setCursor(8,0);
  lcd.print("  Drill");
  lcd.setCursor(0,1);
  lcd.print("  Reflex");
  lcd.setCursor(8,1);
  lcd.print("  Plus");

  delay(500);
  while(1){
    // Deplacement suivant
    if(digitalRead(btnUp) == HIGH){
      if(choix == 3){
        choix = 0;
      } else {
        choix++;        
      }

      changeLCDPrint(choix);
    }

    // Deplacement precedent
    if(digitalRead(btnDown) == HIGH){
      if(choix == 0){
        choix = 3;
      } else {
        choix--;        
      }

      changeLCDPrint(choix);
    }

    // Select
    if(digitalRead(btnSelect) == HIGH){
      startGameMenuOne(choix);
    }

    // Back
    if(digitalRead(btnBack) == HIGH){
      MenuTargetZero();
    }

    delay(200);
  } // boucle infiny

}

void startGameMenuOne(int choix){
  // Standard
  if(choix == 0){
    gameStandard();
  } 
  // Drill
  else if (choix == 1) {
    gameDrill();
  } 
  // Reflex
  else if (choix == 2){
    gameReflex();
  } 
  // More
  else {
    moreGame();
  }
}

//----

void gameStandard(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("STANDARD");
  delay(1500);
  MenuGames();
}

void gameDrill(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("DRILL");
  delay(1500);
  MenuGames();
}

void gameReflex(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("REFLEX");
  delay(1500);
  MenuGames();
}

void moreGame(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MORE");
  delay(1500);
  MenuGames();
}

//----

void changeLCDPrint(int choix){
  switch(choix){
    case 0:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("> Standard");
      lcd.setCursor(8,0);
      lcd.print("  Drill");
      lcd.setCursor(0,1);
      lcd.print("  Reflex");
      lcd.setCursor(8,1);
      lcd.print("  Plus");
      break;
    case 1:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(" Standard");
      lcd.setCursor(8,0);
      lcd.print(">  Drill");
      lcd.setCursor(0,1);
      lcd.print("  Reflex");
      lcd.setCursor(8,1);
      lcd.print("  Plus");
      break;
    case 2:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(" Standard");
      lcd.setCursor(8,0);
      lcd.print("  Drill");
      lcd.setCursor(0,1);
      lcd.print(">  Reflex");
      lcd.setCursor(8,1);
      lcd.print("  Plus");
      break;
    case 3:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(" Standard");
      lcd.setCursor(8,0);
      lcd.print("  Drill");
      lcd.setCursor(0,1);
      lcd.print("  Reflex");
      lcd.setCursor(8,1);
      lcd.print(">  Plus");
      break;
  }

}

//------------------------------------------------------------------------------------

void MenuUser(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MENU USER");
  delay(1500);
  MenuTargetZero();
}

//------------------------------------------------------------------------------------

void MenuSettings(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MENU REGLAGE");
  delay(1500);
  MenuTargetZero();
}