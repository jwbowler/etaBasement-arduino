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
  0,0,0,0,0,0,0,0,0};

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
}

void loop() {
  if (Serial.available() > 0) {
    byte inByte = Serial.read();
    if (inByte == frameBegin) {
      for (int i = 0; i < 9; i++) {
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
      
      analogWrite(R_M_PIN, colors[3]);
      analogWrite(G_M_PIN, colors[4]);
      analogWrite(B_M_PIN, colors[5]);
      
      analogWrite(R_T_PIN, colors[6]);
      analogWrite(G_T_PIN, colors[7]);
      analogWrite(B_T_PIN, colors[8]);
    }
  }
  delay(1);
}
