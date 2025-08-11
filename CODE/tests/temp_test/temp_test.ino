const int TEMP_PIN = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float voltage, degC, degF;
  voltage = getVoltage(TEMP_PIN);
  degC = (voltage - 0.5) * 100.0;
  degF = degC * (9.0 / 5.0) + 32.0;

  Serial.print("voltage: ");
  Serial.print(voltage);
  Serial.print("   deg C: ");
  Serial.print(degC);
  Serial.print("   deg F: ");
  Serial.print(degF);

  delay(1000);
}

float getVoltage(int pin) {
  return (analogRead(pin) * 0.004882814);
}
