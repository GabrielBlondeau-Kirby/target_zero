#include <LiquidCrystal_I2C.h>
#include <C:\Users\blond\Desktop\cool_target\target_zero\non_git\target_z3r0\menu\target_process.ino>

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

  menuTargetsZero();
}

void loop() {}



void menuTargetsZero() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Jeux");
  lcd.setCursor(8,0);
  lcd.print("Gestion User");
  lcd.setCursor(0,1);
  lcd.print("Réglages");

  delay(250);
  while(1){
    // Play
    if(digitalRead(btnUp) == HIGH){
      menuGames();
    }

    // Gestion User
    if(digitalRead(btnDown) == HIGH){
      menuUser();
    }

    // Settings
    if(digitalRead(btnSelect) == HIGH){
      menuSettings();
    }

    delay(200);
  }
}


void menuGames(){
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

  delay (250);
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
      menuTargetsZero();
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
  menuGames();
}

void gameDrill(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("DRILL");
  delay(1500);
  menuGames();
}

void gameReflex(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("REFLEX");
  delay(1500);
  menuGames();
}

void moreGame(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MORE");
  delay(1500);
  menuGames();
}

//---- Settings Games

void settingStand(){
  int nbTarget = 10;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Nb de Cibles :");
  lcd.setCursor(1,7);
  lcd.print(nbTarget);

  while(1){
    delay(250);

    if(digitalRead(btnUp) == HIGH){
      nbTarget++;
      changeLCDPrintStand(nbTarget);
    }

    if(digitalRead(btnDown) == HIGH){
      if(nbTarget == 0){} 
      else {
        nbTarget--;
        changeLCDPrintStand(nbTarget);
      }
    }

    if(digitalRead(btnSelect) == HIGH){ gameStandard(nbTarget) }

    if(digitalRead(btnSelect) == HIGH){ menuGames() }

  }
}

void changeLCDPrintStand(int nbTarget){
  lcd.clearLine(1);
  lcd.setCursor(1,7);
  if(nbTarget >= 10){
    lcd.setCursor(1,6)
  }
  lcd.print(nbTarget);
}

//----

void changeLCDPrint(int choix){
  switch(choix){
    case 0:
      lcd.setCursor(0,0);
      lcd.print("> Stand");
      lcd.setCursor(8,0);
      lcd.print("  Drill");
      lcd.setCursor(0,1);
      lcd.print("  Reflex");
      lcd.setCursor(8,1);
      lcd.print("  Plus");
      break;
    case 1:
      lcd.setCursor(0,0);
      lcd.print(" Stand");
      lcd.setCursor(8,0);
      lcd.print(">  Drill");
      lcd.setCursor(0,1);
      lcd.print("  Reflex");
      lcd.setCursor(8,1);
      lcd.print("  Plus");
      break;
    case 2:
      lcd.setCursor(0,0);
      lcd.print(" Stand");
      lcd.setCursor(8,0);
      lcd.print("  Drill");
      lcd.setCursor(0,1);
      lcd.print(">  Reflex");
      lcd.setCursor(8,1);
      lcd.print("  Plus");
      break;
    case 3:
      lcd.setCursor(0,0);
      lcd.print(" Stand");
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

void menuUser(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MENU USER");
  delay(1500);
  menuTargetsZero();
}

//------------------------------------------------------------------------------------

void menuSettings(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MENU REGLAGE");
  delay(1500);
  menuTargetsZero();
}
