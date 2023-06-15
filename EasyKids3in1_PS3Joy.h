#include "Ps3Controller.h"

//String address = joy.getAddress();

// ------ Function joystick_begin ------
void joyStick_begin()
{
  joy.begin();
  
}
void showAddressLcd(){
  String address = joy.getAddress();
  display.setCursor(23, 90);
  display.setTextSize(3);
  display.setTextColor(TFT_CYAN );
  display.print("MAC Address");
  display.setCursor(17, 120);
  display.setTextSize(2);
  display.setTextColor(TFT_GREEN);
  display.print(address);
}
// ------ JoyValue ------
int JoyCross()
{
  return joy.data.button.cross;
}

int JoySquare()
{
  return joy.data.button.square;
}

int JoyTriangle()
{
  return joy.data.button.triangle;
}

int JoyCircle()
{
  return joy.data.button.circle;
}

int JoyUp()
{
  return joy.data.button.up;
}

int JoyDown()
{
  return joy.data.button.down;
}

int JoyRight()
{
  return joy.data.button.right;
}

int Joyleft()
{
  return joy.data.button.left;
}

int JoyL1()
{
  return joy.data.button.l1;
}

int JoyL2()
{
  return joy.data.button.l2;
}

int JoyR1()
{
  return joy.data.button.r1;
}

int JoyR2()
{
  return joy.data.button.r2;
}

int JoySelect()
{
  return joy.data.button.select;
}

int JoyStart()
{
  return joy.data.button.start;
}

int JoyPS()
{
  return joy.data.button.ps;
}

int JoyLX()
{
  return joy.data.analog.stick.lx;
}

int JoyLY()
{
  return joy.data.analog.stick.ly;
}

int JoyRX()
{
  return joy.data.analog.stick.rx;
}

int JoyRY()
{
  return joy.data.analog.stick.ry;
}