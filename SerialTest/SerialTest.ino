
#define LED_PIN 13

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  establishContact();
}

void loop() {
  if (Serial.available() > 0) {
    toggleLED();
    char inByte = Serial.read();
    analogWrite(3, inByte);
    Serial.write(inByte);    
  }
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.println("Ready");
    toggleLED();
    delay(300);
  }
}

void toggleLED() {
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
}
