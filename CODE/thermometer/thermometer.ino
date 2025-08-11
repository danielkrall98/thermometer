// Daniel Krall 11742259
// Abgabe
// Code fuer Aufgabe 4b

/*********************************************************************************************************************************************/

// LCD DISPLAY
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// TEMPERATUR SENSOR
const int TEMP_PIN = A0;
float degC, degF;

// RBG LED
const int RED_PIN = 8;
const int GREEN_PIN = 9;
const int BLUE_PIN = 10;

// PUSH BUTTON
const int PUSH_PIN = 7;
byte lastPushState = LOW;
byte tempState = LOW;
unsigned long debounce = 20;
unsigned long lastChange = 0; 
int displayState = 0;

// BUZZER
const int BUZZER_PIN = 6;
const int FREQ = 523;

/*********************************************************************************************************************************************/

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);          // Blaues LED
  pinMode(PUSH_PIN, INPUT);     // Push Button
  pinMode(BUZZER_PIN, OUTPUT);  // Buzzer
  lcd.begin(16, 2);
  lcd.clear();

  // MESSUNG
  // "Messung..." + blaues LED
  showMessage();
  showMessage();

  lcd.print("TEMPERATUR:");
}

void loop() {
  getTemp();
  ledColour();

  // DISPLAY celsius ODER FAHRENHEIT
  tempCorF();
  makeSound();
  
  delay(500);
}


/*********************************************************************************************************************************************/

// CELSIUS ODER FAHRENHEIT
void tempCorF() {
  if (millis() - lastChange > debounce) {
    byte pushState = digitalRead(PUSH_PIN);
    if (pushState != lastPushState) {
      lastChange = millis();
      lastPushState = pushState;
      if (pushState == LOW)
        tempState = (tempState == HIGH) ? LOW: HIGH;
    }
  }
  
  if (tempState == LOW)
    celsius();
  else
    fahrenheit();
}

// DISPLAY celsius
void celsius() {
  lcd.setCursor(0, 1);
  lcd.print(degC);
  lcd.setCursor(6, 1);
  lcd.print("C");
}

// DISPLAY FAHRENHEIT
void fahrenheit() {
  lcd.setCursor(0, 1);
  lcd.print(degF);
  lcd.setCursor(6, 1);
  lcd.print("F");
}

// GET TEMPERATURE
void getTemp() {
  float voltage = (analogRead(TEMP_PIN) * 0.004882814);
  degC = (voltage - 0.5) * 100.0;       // Umrechnung von Voltage auf Celsius
  degF = degC * (9.0 / 5.0) + 32.0;     // Umrechnung von celsius auf Fahrenheit
}

// MESSUNG TEXT
void showMessage() {
  lcd.print("Messung");
  flash();
  delay(500);
  lcd.print(".");
  flash();
  delay(500);
  lcd.print(".");
  flash();
  delay(500);
  lcd.print(".");
  flash();
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
}

// BLINKENDES LED
void flash() {
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
}

// LED FARBE
void ledColour() {
  if (degC < 0.0) {                          // LED WEISS BEI UNTER 0 GRAD celsius
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BLUE_PIN, HIGH);
    // Serial.print("weiss ");
  }
  else if (degC >= 0.0 && degC < 10.0) {    // LED BLAU ZWISCHEN 0 UND 10 GRAD
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, HIGH);
    // Serial.print("blau ");
  }
  else if (degC >= 10.0 && degC < 20.0) {   // LED GRUEN ZWISCHEN 10 UND 20 GRAD
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BLUE_PIN, LOW);
    // Serial.print("gruen ");
  }
  else if (degC >= 20.0 && degC < 30.0) {   // LED GELB ZWISCHEN 20 UND 30 GRAD
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BLUE_PIN, LOW);
    // Serial.print("gelb ");
  }
  else {                                      // LED ROT BEI UEBER 30 GRAD
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);
    // Serial.print("rot ");
  }
}

// BUZZER SOUND
void makeSound() {
  int buttonState = digitalRead(PUSH_PIN);

  if (buttonState == LOW) {
    digitalWrite(13, HIGH);
    tone(BUZZER_PIN, FREQ);
    Serial.print("ton! / ");
  }
  else {
    digitalWrite(13, LOW);
    noTone(BUZZER_PIN);
    Serial.print("ton aus!   ");
  }
}
