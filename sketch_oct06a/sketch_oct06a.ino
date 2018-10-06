#include "Keyboard.h"

const int keyNum = 2;
const int inputPin[keyNum] = {3, 4};
const int ledPin = 13;
const byte keyMap[keyNum] = {0x61, 0x62};
bool currentState[keyNum];
bool beforeState[keyNum];
int i;

void setup() {
  for(i = 0; i < keyNum; i++) {
    pinMode(inputPin[i], INPUT);
    currentState[i] = LOW;
    beforeState[i] = LOW;
  }
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  for(i = 0; i < keyNum; i++) {
    currentState[i] = digitalRead(inputPin[i]);
    if (currentState[i] != beforeState[i]) {
      Serial.print("KEY");
      Serial.print(i);
      if (currentState[i] == HIGH) {
        Serial.println("PUSH");
      } else {
        Serial.println("RELEASE");
      }
      beforeState[i] = currentState[i];
    }
  }
}
