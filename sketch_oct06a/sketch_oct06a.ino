#include "Keyboard.h"

const int inputPin = 3;
const int ledPin = 13;

void setup() {
  pinMode(inputPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Keyboard.begin();
}

void loop() {
  if (digitalRead(inputPin) == HIGH) {
    digitalWrite(ledPin, HIGH);
    Keyboard.press(0x61);
  } else {
    digitalWrite(ledPin, LOW);
    Keyboard.release(0x61);
  }
}
