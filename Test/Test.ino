#include "Robot.h"

Robot *robot = NULL;
void setup() {
  robot = new Robot();
  Serial.begin(9600);
}

void loop() {
  robot->move(1,200,4);
  Serial.println("About to stop");
  robot->stop(2,0);
  robot->move(0,200,4);
  Serial.println("About to stop");
  robot->stop(2,0);
  /*robot->move(0,200,4);
  Serial.println("About to stop");
  robot->stop(2,1);
  */
}
