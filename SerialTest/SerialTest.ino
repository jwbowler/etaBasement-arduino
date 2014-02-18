
#include<stdio.h>

#define LED_PIN 13
#define R_PIN 3
#define G_PIN 5
#define B_PIN 6
#define frameBegin ((char) 255)

char colors[] = {
  0,0,0};

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  //  establishContact();
  Serial.println("blah");
}

void loop() {
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    toggleLED();
    // Got a new frame
    //Serial.println('S');
    if (inByte == frameBegin) {
      //Serial.println('B');
      //write bass
      boolean allThree = true;
      for (int i=0; i < 3; i++) {
        char rgb = Serial.read();
        if (rgb == frameBegin) {
          //Serial.println('F');
          allThree = false;
          break;
        }
        else {
          colors[i] = rgb;
        }
      }
      if (allThree) {
        //printRGB();
        analogWrite(R_PIN, colors[0]);
        analogWrite(G_PIN, colors[1]);
        analogWrite(B_PIN, colors[2]);
      }
    }
  }
}

void printRGB() {
  Serial.print("rgb: ");
  Serial.print((uint8_t) colors[0]);
  Serial.print(" ");
  Serial.print((uint8_t) colors[1]);
  Serial.print(" ");
  Serial.println((uint8_t) colors[2]);
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

