#include <EasyKids3in1.h>

void setup() {
  EasyKids_Setup();
}

void loop() {
Serial.println(analog(A0));
delay(20);
}