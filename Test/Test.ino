#include "Constante.h"
#include "Robot.h"
Robot* robot = NULL;
void setup() {
  pinMode(LEFT_PHOTOELECTRIQUE_PIN,INPUT);
  pinMode(MIDDLE_LEFT_PHOTOELECTRIQUE_PIN,INPUT);
  pinMode(MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN,INPUT);
  pinMode(RIGHT_PHOTOELECTRIQUE_PIN,INPUT);
  robot = new Robot();
  Serial.begin(9600);
}
void loop() {
  robot-> move(1,100,-1);
  //robot->turn(1,100,100,-1);
  
}
