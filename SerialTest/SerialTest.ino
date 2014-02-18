
#include<stdio.h>

#define LED_PIN 13
#define R_PIN 8
#define G_PIN 9
#define B_PIN 10
#define frameBegin 255

int colors[] = {
  0,0,0};

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  //  establishContact();
}

void loop() {
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    // Got a new frame
    if (inByte == frameBegin) {
      //write bass
      boolean allThree = true;
      for (int i=0; i < 3; i++) {
        char rgb = Serial.read();
        if (rgb == frameBegin) {
          allThree = false;
          break;
        }
        else {
          colors[i] = rgb;
        }
      }
      if (allThree) {
        printRGB();
        analogWrite(R_PIN, colors[0]);
        analogWrite(G_PIN, colors[1]);
        analogWrite(B_PIN, colors[2]);
      }
    }
  }
}

void printRGB() {
  Serial.print("rgb: ");
  Serial.print(colors[0]);
  Serial.print(" ");
  Serial.print(colors[1]);
  Serial.println(colors[2]);
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

