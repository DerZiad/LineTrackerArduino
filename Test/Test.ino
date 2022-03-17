#include "Robot.h"

Robot* robot = NULL;
void setup() {
  Serial.begin(9600);
  robot = new Robot();
}

void loop() {
   robot->move(1,200,3);
   robot->turn(0,200,200,2);
   robot->stop(-1,0);   
   robot->move(1,200,3);
}
