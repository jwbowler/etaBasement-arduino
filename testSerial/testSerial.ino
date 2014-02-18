#define LED_PIN 13

void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
  while (!Serial) {} //wait for connection 
  Serial.print(21);
}

void loop()                       // run over and over again
{
  if (Serial.available() > 0) {
    char inByte = Serial.read();
  //  analogWrite(3, inByte);
    Serial.print("char read: ");
    Serial.println(inByte);
  } 
}

void toggleLED() {
  Serial.println("in toggle");
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
}
