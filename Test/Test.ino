#include "Pile.h"
#include "Constante.h"
void setup() {
  Serial.begin(9600);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
}

static String right = "RIGHT";
static String left = "LEFT";
//static String forward = "FORWARD"
static String stope = "STOP";


void loadDepartBuvette(){
  empiler(D,D,D,D,stope);
  empiler(D,D,D,W,right);
  empiler(D,D,D,D,left);
  empiler(D,D,D,D,right);
  Serial.println(right);
}
void loop() {
  loadDepartBuvette();
    Element* element = depiler();
    Serial.println(String(element->action));
    delay(100000);
}
