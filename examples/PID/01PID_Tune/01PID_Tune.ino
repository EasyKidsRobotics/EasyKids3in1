#include <EasyKids3in1.h>

void setup() {
  EasyKids_Setup();
}

void loop() {
  if ((sw_Start() == 0)) {
    while (1) {
      Run_PID(50, 0.5, 0);
    }
  }
}
