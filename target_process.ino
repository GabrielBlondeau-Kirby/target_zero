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
#define sensor1 32
#define sensor2 33
#define sensor3 34
#define sensor4 35
#define sensor5 36
#define sensor6 37
#define sensor7 38
#define sensor8 39
#define sensor9 40
#define sensor10 41

// Relais
int total_cible = 10;
int list_relais[10] = {relais1, relais2, relais3, relais4, relais5, relais6, relais7, relais8, relais9, relais10};
int number_random;
int random_cible;
int sensor_of_cible;

// Sensors
int list_sensor[10] ={sensor1, sensor2, sensor3, sensor4, sensor5, sensor6, sensor7, sensor8, sensor9, sensor10};
byte value = 0;
int THRESHOLD = 100; // Detection value


void setup() {
 // initialisation Cibles
  for (int x = 0; x < total_cible; x++) {
    // relais/leds
    Serial.println("active relais: ");
    Serial.println(list_relais[x]);
    pinMode(list_relais[x], OUTPUT);
    digitalWrite(list_relais[x], HIGH);
    delay(250);
    digitalWrite(list_relais[x], LOW);
    //sensors
    pinMode(list_sensor[x], INPUT);
  }

  Serial.println("-----");
  mode_nb_cible(10);
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
    number_random = random(0, 9);
    random_cible = list_relais[number_random];
    sensor_of_cible = list_sensor[number_random];

    Serial.println("**");
    Serial.println("random cible :");
    Serial.println(random_cible);
    Serial.println("Sensor associate :");
    Serial.println(sensor_of_cible);
    
    digitalWrite(random_cible, HIGH);
    value = 0;
    while(value < THRESHOLD){
      value = analogRead(sensor_of_cible);
      Serial.println("value :");
      Serial.println(value);

      // A enlever pour le test en vrai
      value = fake_vribreur();
    }

    Serial.println("BANG !!!!!!");
    digitalWrite(random_cible, LOW);
  }

  Serial.println("FINISHH BANG BANG");
}

// Call while initialization
void loop_relais_starting(int state, int _delay) {
  for (int x = 0; x < total_cible; x++) {
    delay(_delay);
    digitalWrite(list_relais[x], state);
  }
}

int fake_vribreur() {
  int nb = random(50, 250);
  delay(750);
  return nb;
}