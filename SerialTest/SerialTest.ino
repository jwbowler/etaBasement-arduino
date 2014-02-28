#include<stdio.h>

#define LED_PIN 13
#define R_B_PIN 8
#define G_B_PIN 9
#define B_B_PIN 10
#define R_M_PIN 5
#define G_M_PIN 6
#define B_M_PIN 7
#define R_T_PIN 2
#define G_T_PIN 3
#define B_T_PIN 4
#define frameBegin ((byte) 255)

byte colors[] = {
  0,0,0};

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(R_B_PIN, OUTPUT);
  pinMode(G_B_PIN, OUTPUT);
  pinMode(B_B_PIN, OUTPUT);
  pinMode(R_M_PIN, OUTPUT);
  pinMode(G_M_PIN, OUTPUT);
  pinMode(B_M_PIN, OUTPUT);
  pinMode(R_T_PIN, OUTPUT);
  pinMode(G_T_PIN, OUTPUT);
  pinMode(B_T_PIN, OUTPUT);
  //  establishContact();
  Serial.println("blah");
}

void loop() {
  if (Serial.available() > 0) {
    byte inByte = Serial.read();
    toggleLED();
    
    if (inByte == frameBegin) {
      
      //GET BASS
      for (int i=0; i < 3; i++) {
        while (!Serial.available()) { }
        byte rgb = Serial.read();
        if (rgb == frameBegin) {
          return;
        }
        else {
          colors[i] = rgb;
        }
      }
      analogWrite(R_B_PIN, colors[0]);
      analogWrite(G_B_PIN, colors[1]);
      analogWrite(B_B_PIN, colors[2]);   
      //GET MID
      for (int i=0; i < 3; i++) {
        while (!Serial.available()) { }
        byte rgb = Serial.read();
        if (rgb == frameBegin) {
          return;
        }
        else {
          colors[i] = rgb;
        }
      }
      analogWrite(R_M_PIN, colors[0]);
      analogWrite(G_M_PIN, colors[1]);
      analogWrite(B_M_PIN, colors[2]);
      
      //GET Treble
      for (int i=0; i < 3; i++) {
        while (!Serial.available()) { }
        byte rgb = Serial.read();
        if (rgb == frameBegin) {
          return;
        }
        else {
          colors[i] = rgb;
        }
      }
      analogWrite(R_T_PIN, colors[0]);
      analogWrite(G_T_PIN, colors[1]);
      analogWrite(B_T_PIN, colors[2]);
    }
  }
  delay(1);
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

