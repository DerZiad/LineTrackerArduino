#include "Robot.h"
Robot *robot = NULL;
void setup() {
  robot = new Robot();
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop() {
  
  robot->move(1,150,5);
}
