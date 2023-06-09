int valSensor0;
int valSensor1;
int valSensor2;
int valSensor3;
int valSensor4;
int valSensor5;
int valSensor6;

int rightMotor;
int leftMotor;
int numSensor = 7;
uint16_t sensorPin[] = { 0, 1, 2, 3, 4, 5, 6 };
uint16_t minSensorValues[] = { 379, 360, 272, 503, 326, 318, 255 };//สีดำ
uint16_t maxSensorValues[] = { 1945, 2102, 1984, 2451, 1954, 2208, 1815 };//สีขาว
uint16_t stateOnLine = 0;
float KP ;
float KD ;
uint16_t setPoint;
uint32_t lastPosition;
float errors = 0;
float output = 0;
float derivative;
float previous_error;

int readline() {
  bool onLine = false;
  long avg = 0;
  long sum = 0;
  for (uint8_t i = 0; i < numSensor; i++) {
    long value = map(analog(sensorPin[i]), minSensorValues[i], maxSensorValues[i], 1000, 0);  
    if (value > 200) {
      onLine = true;
    }
    if (value > 50) {
      avg += (long)value * (i * 1000);
      sum += value;
    }
  }
  if (!onLine) {
    if (lastPosition < 3000) {
      return 0;
    } else {
      return 6000;
    }
  }
  lastPosition = avg / sum;
  return lastPosition;
}

void trackPID(int setSpeed, float iKP, float iKD) {
  KP = iKP;
  KD = iKD;
  int speed = setSpeed;
  setPoint = 3000;
  errors = readline() - setPoint;
  derivative = (errors - previous_error);
  output = ((KP * errors) + (KD * derivative)) / 100;
  previous_error = errors;
  if (output > speed) {
    output = speed;
  } else if (output < 0 - speed) {
    output = 0 - speed;
  }
  leftMotor = speed - output;
  rightMotor = speed + output;
  if (leftMotor >= 100) {
    leftMotor = 100;
  }
  if (leftMotor <= 0) {
    leftMotor = -70;
  }
  if (rightMotor >= 100) {
    rightMotor = 100;
  }
  if (rightMotor <= 0) {
    rightMotor = -70;
  }
  motor(1, leftMotor);
  motor(4, rightMotor);
}

void timePID(int setSpeed, float iKP, float iKD, int setTime) {
  long timer = 0;
  timer = millis();
  do {
    trackPID(setSpeed, iKP, iKD);
  } while ((millis() - timer) < setTime);
  motor(1, 0);
  motor(4, 0);
}

void crossLinePID(int setSpeed, float iKP, float iKD) {
  while (analog(0) > minSensorValues[0] + 1000  || analog(6) > minSensorValues[6] + 1000){
    trackPID(setSpeed, iKP, iKD);
  }
  delay(30);
  motor(1, 0);
  motor(4, 0);
}

void dicularLeftPID(int setSpeed, float iKP, float iKD) {
  do {
    trackPID(setSpeed, iKP, iKD);
  } while (analog(4) > minSensorValues[4]  || analog(5) > minSensorValues[5]  || analog(6) > minSensorValues[6]);
  motor(1, 0);
  motor(4, 0);
}

void dicularRightPID(int setSpeed, float iKP, float iKD) {
  do {
    trackPID(setSpeed, iKP, iKD);
  } while (analog(0) > minSensorValues[0]  || analog(1) > minSensorValues[1]  || analog(2) > minSensorValues[2]);
  motor(1, 0);
  motor(4, 0);
}
void leftPID(){
    motor(1,-50);
    motor(4,50);
    delay(20);
  do{
    motor(1,-50);
    motor(4,50);
  }  
  while(analog(6) > minSensorValues[6] + 1000 );
  motor(1, 0);
  motor(4, 0);
}
void rightPID(){
  motor(1,50);
    motor(4,-50);
    delay(20);
  do{
    motor(1,50);
    motor(4,-50);
  }  
  while(analog(0) > minSensorValues[0] + 1000 );
  motor(1, 0);
  motor(4, 0);
}
void readSensor()
{
  display.setTextFont(GLCD);
  display.setTextSize(2);
  display.setCursor(15, 5);
  display.setTextColor(0xF81F);
  display.print("Read Sensor 0 - 6");
  // ------- Sensor 0 -------
  display.setTextFont(GLCD);
  display.setTextSize(2);
  display.setCursor(20, 30);
  display.setTextColor(0x0);
  display.print("Sensor(0) = ");
  display.print(valSensor0);
  valSensor0 = analog(0);
  display.setTextSize(2);
  display.setCursor(20, 30);
  display.setTextColor(0x07FF);
  display.print("Sensor(0) = ");
  display.print(valSensor0);
  // ------- Sensor 1 -------
  display.setTextFont(GLCD);
  display.setTextSize(2);
  display.setCursor(20, 60);
  display.setTextColor(0x0);
  display.print("Sensor(1) = ");
  display.print(valSensor1);
  valSensor1 = analog(1);
  display.setTextSize(2);
  display.setCursor(20, 60);
  display.setTextColor(0x07FF);
  display.print("Sensor(1) = ");
  display.print(valSensor1);
  // ------- Sensor 2 -------
  display.setTextFont(GLCD);
  display.setTextSize(2);
  display.setCursor(20, 90);
  display.setTextColor(0x0);
  display.print("Sensor(2) = ");
  display.print(valSensor2);
  valSensor2 = analog(2);
  display.setTextSize(2);
  display.setCursor(20, 90);
  display.setTextColor(0x07FF);
  display.print("Sensor(2) = ");
  display.print(valSensor2);
  // ------- Sensor 3 -------
  display.setTextFont(GLCD);
  display.setTextSize(2);
  display.setCursor(20, 120);
  display.setTextColor(0x0);
  display.print("Sensor(3) = ");
  display.print(valSensor3);
  valSensor3 = analog(3);
  display.setTextSize(2);
  display.setCursor(20, 120);
  display.setTextColor(0x07FF);
  display.print("Sensor(3) = ");
  display.print(valSensor3);
  // ------- Sensor 4 -------
  display.setTextFont(GLCD);
  display.setTextSize(2);
  display.setCursor(20, 150);
  display.setTextColor(0x0);
  display.print("Sensor(4) = ");
  display.print(valSensor4);
  valSensor4 = analog(4);
  display.setTextSize(2);
  display.setCursor(20, 150);
  display.setTextColor(0x07FF);
  display.print("Sensor(4) = ");
  display.print(valSensor4);
  // ------- Sensor 5 -------
  display.setTextFont(GLCD);
  display.setTextSize(2);
  display.setCursor(20, 180);
  display.setTextColor(0x0);
  display.print("Sensor(5) = ");
  display.print(valSensor5);
  valSensor5 = analog(5);
  display.setTextSize(2);
  display.setCursor(20, 180);
  display.setTextColor(0x07FF);
  display.print("Sensor(5) = ");
  display.print(valSensor5);
  // ------- Sensor 6 -------
  display.setTextFont(GLCD);
  display.setTextSize(2);
  display.setCursor(20, 210);
  display.setTextColor(0x0);
  display.print("Sensor(6) = ");
  display.print(valSensor6);
  valSensor6 = analog(6);
  display.setTextSize(2);
  display.setCursor(20, 210);
  display.setTextColor(0x07FF);
  display.print("Sensor(6) = ");
  display.print(valSensor6);
  delay(50);
}
