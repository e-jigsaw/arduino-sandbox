#include "Keyboard.h"

const int inputPin = 3;
const int ledPin = 13;
bool currentState = LOW;
bool beforeState = LOW;

void setup() {
  pinMode(inputPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  currentState = digitalRead(inputPin);
  if (currentState != beforeState) {
    if (digitalRead(inputPin) == HIGH) {
      digitalWrite(ledPin, HIGH);
      Serial.println("PUSH");
//      Keyboard.press(0x61);
    } else {
      digitalWrite(ledPin, LOW);
      Serial.println("RELEASE");
//      Keyboard.release(0x61);
    }
    beforeState = currentState;
  }
}
