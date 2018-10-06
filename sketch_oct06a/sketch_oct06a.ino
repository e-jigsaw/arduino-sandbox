#include "Keyboard.h"

const int inputPin1 = 3;
const int inputPin2 = 4;
const int ledPin = 13;
bool currentState1 = LOW;
bool beforeState1 = LOW;
bool currentState2 = LOW;
bool beforeState2 = LOW;

void setup() {
  pinMode(inputPin1, INPUT);
  pinMode(inputPin2, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  currentState1 = digitalRead(inputPin1);
  currentState2 = digitalRead(inputPin2);
  if (currentState1 != beforeState1) {
    if (currentState1 == HIGH) {
      digitalWrite(ledPin, HIGH);
      Serial.println("PUSH 1");
//      Keyboard.press(0x61);
    } else {
      digitalWrite(ledPin, LOW);
      Serial.println("RELEASE 1");
//      Keyboard.release(0x61);
    }
    beforeState1 = currentState1;
  }
  if (currentState2 != beforeState2) {
    if (currentState2 == HIGH) {
      digitalWrite(ledPin, HIGH);
      Serial.println("PUSH 2");
    } else {
      digitalWrite(ledPin, HIGH);
      Serial.println("RELEASE 2");
    }
    beforeState2 = currentState2;
  }
}
