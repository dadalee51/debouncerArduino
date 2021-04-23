#include "Debouncer.h"
#include "Arduino.h"
int reading=0;
int buttonState=0;             // the current reading from the input pin
int lastButtonState = 0;   // the previous reading from the input pin
int ledState = 0;
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

int buttonPin;    // the number of the pushbutton pin

Debouncer::Debouncer(){} //does nothing.

void Debouncer::begin(int pinN){
  pinMode(pinN, INPUT_PULLUP); //this needs be done in setup.
  buttonPin=pinN;
}

int Debouncer::getState(){
  reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }
  lastButtonState = reading;
  return ledState;
}
