#include "Pile.h"
#ifndef CONSTANTE_H
#include "Constante.h"
#endif

static String right = "RIGHT";
static String left = "LEFT";
//static String forward = "FORWARD"
static String stope = "STOP";
void loadDepartBuvette(){
  Serial.println("Work 1");
  empiler(D,D,D,D,stope);
  Serial.println("Work 2");
  empiler(D,D,D,W,right);
  Serial.println("Work 3");
  empiler(D,D,D,D,left);
  Serial.println("Work 4");
  empiler(D,D,D,D,right);
  Serial.println("Work 5");
}

//Robot* robot = NULL;
void setup() {
  Serial.begin(9600);
  //robot = new Robot();
}

void loop() {
    loadDepartBuvette();
    afficher();
    Serial.println("Work");
    depiler();
    afficher();
    delay(10000);
   //robot->move(1,200,3);
   //robot->turn(0,200,200,2);
   //robot->stop(-1,0);   
   //robot->move(1,200,3);
}
