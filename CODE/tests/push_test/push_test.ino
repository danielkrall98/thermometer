const int push = 7;
const int LED = 13;

byte lastPushState = LOW;
byte ledState = LOW;

unsigned long debounce = 50;
unsigned long lastChange = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(push, INPUT);
}

void loop() {
  if (millis() - lastChange > debounce) {
    byte pushState = digitalRead(push);
    if (pushState != lastPushState) {
      lastChange = millis();
      lastPushState = pushState;
      if (pushState == LOW) {
        ledState = (ledState == HIGH) ? LOW: HIGH;
        digitalWrite(LED, ledState);
      }
    }
  }
}
