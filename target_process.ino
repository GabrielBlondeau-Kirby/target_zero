#define relais1 22
#define relais2 23
#define relais3 24
#define relais4 25
#define relais5 26
#define relais6 27
#define relais7 28
#define relais8 29
#define relais9 30
#define relais10 31

// Relais
int total_cible = 10;
int tab_relais[10] = {relais1, relais2, relais3, relais4, relais5, relais6, relais7, relais8, relais9, relais10};

// Sensor
int tab_sensor[10] = {sensor1, sensor2, ...};

int random_cible;


void setup() {
  Serial.begin(9600); 
  Serial.println("-----");
  // initialisation Cibles
  for (int x = 0; x < total_cible; x++) {
    // relais/leds
    Serial.println("active relais: ");
    Serial.println(tab_relais[x]);
    pinMode(tab_relais[x], OUTPUT);
    digitalWrite(tab_relais[x], HIGH);
    delay(250);
    digitalWrite(tab_relais[x], LOW);
    //sensors
    pinMode(tab_sensor[x], INPUT)
  }
  Serial.println("-----");
  mode_nb_cible(1000);
}

void loop() {
}


void mode_nb_cible(int nb_cibles) {
  Serial.println("");
  Serial.println("MODE_NB_CIBLE");
  // All led ON
  Serial.println("");
  Serial.println("ALLUMAGE ALL");
  loop_relais_starting(HIGH, 0);
  Serial.println("");
  Serial.println("DECOMPTE");
  // CountDown
  loop_relais_starting(LOW, 1000);

  Serial.println("");
  Serial.println("BANG BANG");
  // Bang Bang
  for (int cibles = 0; cibles <= nb_cibles; cibles++) {
    random_cible = random(relais1, relais10);
    Serial.println("**");
    Serial.println("random cible :");
    Serial.println(random_cible);
    
    digitalWrite(random_cible, HIGH);
    // activer capteur
    // change_state_capteur(random_cible)
    bool toucher = false;
    while (toucher == false) {
      // Reception capteur vibration

      // la on fake le capteur
      // apre un delay on passe: toucher => true
      toucher = fake_vribreur();
    }

    Serial.println("BANG !!!!!!");
    digitalWrite(random_cible, LOW);
    // désactiver capteur
    // change_state_capteur(random_cible)
  }
  Serial.println("FINISHH BANG BANG");
}

void loop_relais_starting(int state, int _delay) {
  for (int x = 0; x < total_cible; x++) {
    delay(_delay);
    digitalWrite(tab_relais[x], state);
  }
}

void change_state_capteur(int capteur) {
  // a coder
}

int fake_vribreur() {
  int nb = random(1, 10 * 75);
  Serial.println(nb);
  delay(nb);
  return true;
}

