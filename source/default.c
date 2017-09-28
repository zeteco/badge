// Default Firmware of the Badge
void setup() {

  tone(0, 440, 200);
  delay(100);
  tone(0, 2440, 200);
  delay(200);
  noTone(0);

  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

}


void loop() {

  digitalWrite(1, HIGH);
  delay(100);
  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(100);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(4, LOW);
}
