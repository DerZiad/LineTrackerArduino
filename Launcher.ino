#include "Robot.h"
#include "StateManager.h"
#define LEFT_PIN 2
#define RIGHT_PIN 4
#define CENTER_PIN 7
Robot *robot = NULL;
Sonor *sonor = NULL;
StateManager *stateManager = NULL;

void setup() {
    pinMode(LEFT_PIN,INPUT);
    pinMode(RIGHT_PIN,INPUT);
    pinMode(CENTER_PIN,INPUT);
    stateManager = new StateManager();
    robot = new Robot();
    //printer = new Printer();
    //sonor = new Sonor();
    Serial.begin(9600);
    //pinMode(2,INPUT);
}

void loop() {
    int leftValue = digitalRead(LEFT_PIN);
    int rightValue= digitalRead(RIGHT_PIN);
    int middleValue=digitalRead(CENTER_PIN);

    if(leftValue == 0 && middleValue == 0 && rightValue == 0){
      robot->stop(0,-1);
    }

    if(leftValue == 0 && middleValue == 0 && rightValue == 1){
      robot->turn(0,100,100,-1);
      while(leftValue != 0 && middleValue != 1 && rightValue != 0);
      robot->stop(0,-1);
    }
    
    if(leftValue == 0 && middleValue == 1 && rightValue == 0){
       robot->move(1,200,-1);
    }

    //Forward or turn right
    if(leftValue == 0 && middleValue == 1 && rightValue == 1){
      robot->move(1,150,-1);
    }
    
    if(leftValue == 1 && middleValue == 0 && rightValue == 0){
      robot->turn(1,100,100,-1);
      while(leftValue != 0 && middleValue != 1 && rightValue != 0);
      robot->stop(0,-1);
    }

    if(leftValue == 1 && middleValue == 0 && rightValue == 1){
      robot->turn(0,100,100,-1);
      while(leftValue != 0 && middleValue != 1 && rightValue != 0);
      robot->stop(0,-1);
    }

    //Forward or turn left
    if(leftValue == 1 && middleValue == 1 && rightValue == 0){
      robot->move(1,150,-1);
    }

    if(leftValue == 1 && middleValue == 1 && rightValue == 1){
      robot->move(1,150,-1);
    }
    
}
