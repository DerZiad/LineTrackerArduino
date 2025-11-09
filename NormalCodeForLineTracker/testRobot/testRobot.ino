#include "Robot.h"
Robot *robot = NULL;
void setup(){
  Serial.begin(9600);
  robot = new Robot();
}

void loop(){
  Serial.println("Moving forward");
  robot->move(1,150,2);
  Serial.println("Moving backward");
  robot->move(0,150,2);
  Serial.println("Moving right");
  robot->turn(1,150,150,2);
  Serial.println("Moving left");
  robot->turn(0,150,150,2);
  Serial.println("Stopping");
  robot->stop(5,0);
}
