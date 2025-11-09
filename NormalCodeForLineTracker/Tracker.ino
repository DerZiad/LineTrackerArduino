#include "Sonor.h"
#include "Robot.h"
#include "Printer.h"
Sonor *sonor = NULL;
Robot *robot = NULL;
Printer *printer = NULL;
int turnSpeed = 200;
int moveSpeed = 220;
void setup() {
  sonor = new Sonor();
  robot = new Robot();
  printer = new Printer();
  pinMode(LEFT_PHOTOELECTRIQUE_PIN,INPUT);
  pinMode(MIDDLE_LEFT_PHOTOELECTRIQUE_PIN,INPUT);
  pinMode(MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN,INPUT);
  pinMode(RIGHT_PHOTOELECTRIQUE_PIN,INPUT);
  Serial.begin(9600);
}

void ajuster(){
  int leftPhotoPin = digitalRead(LEFT_PHOTOELECTRIQUE_PIN);
  int leftMiddlePin =digitalRead(MIDDLE_LEFT_PHOTOELECTRIQUE_PIN);
  int rightMiddlePin =digitalRead(MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN);
  int rightPhotoPin = digitalRead(RIGHT_PHOTOELECTRIQUE_PIN);
  while(leftPhotoPin != W || leftMiddlePin != D || rightMiddlePin != D || rightPhotoPin != W){
    leftPhotoPin = digitalRead(LEFT_PHOTOELECTRIQUE_PIN);
    leftMiddlePin =digitalRead(MIDDLE_LEFT_PHOTOELECTRIQUE_PIN);
    rightMiddlePin =digitalRead(MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN);
    rightPhotoPin = digitalRead(RIGHT_PHOTOELECTRIQUE_PIN);
  }
  robot->stop(-1,0);
}
void loop(){
  float mesure = sonor->calculateDistance();
  if(mesure > 5){
     int leftPhotoPin = digitalRead(LEFT_PHOTOELECTRIQUE_PIN);
     int leftMiddlePin =digitalRead(MIDDLE_LEFT_PHOTOELECTRIQUE_PIN);
     int rightMiddlePin =digitalRead(MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN);
     int rightPhotoPin = digitalRead(RIGHT_PHOTOELECTRIQUE_PIN);
     if(leftMiddlePin == D && rightMiddlePin == D){
        Serial.println("Forward");
        printer->print("Forward move");
        robot->move(1,moveSpeed,-1);
     }else if(leftMiddlePin == W && rightMiddlePin == D){
        Serial.println("Turning right");
        printer->print("Right turn");
        robot->turn(1,turnSpeed,turnSpeed,-1);
        ajuster();
     }else if(leftMiddlePin == D && rightMiddlePin == W){
        Serial.println("Turning left");
        printer->print("Left turn");
        robot->turn(0,turnSpeed,turnSpeed,-1);
        ajuster();
      }else{
        printer->print("White detected");
        Serial.println("Stop");
        robot->stop(-1,0);
      }
  }else{
    robot->stop(-1,0);
    printer->print("Obstacle detected");
  }
   
}
