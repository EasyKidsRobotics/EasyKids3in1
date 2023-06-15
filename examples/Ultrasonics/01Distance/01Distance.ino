#include <EasyKids3in1.h>

void setup() {
  EasyKids_Setup();
}


void loop()
{
    // put your main code here, to run repeatedly:
    Serial.println(sonar());
    delay(100);
}