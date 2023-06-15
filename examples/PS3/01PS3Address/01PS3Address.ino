#include <EasyKids3in1.h>

void setup()
{
    EasyKids_Setup();
    joystick_begin();
    // put your setup code here, to run once:
    String address = joy.getAddress();

    Serial.print("The ESP32's Bluetooth MAC address is: ");
    Serial.println(address);
}

void loop()
{
    // put your main code here, to run repeatedly:
}