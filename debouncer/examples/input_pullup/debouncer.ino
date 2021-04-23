#include "Debouncer.h"

Debouncer btn_01;
void setup() {
  btn_01.begin(14);
  Serial.begin(115200);
  Serial.println();
  
}

void loop() {
  // set the LED:
  Serial.println(btn_01.getState());
  
}
