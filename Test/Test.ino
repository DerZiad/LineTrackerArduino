#define D 1
#define W 0
#include "Pile.h"

static String right = "RIGHT";
static String left = "LEFT";
//static String forward = "FORWARD"
static String stop = "STOP";

Element *element = NULL;
void loadDepartBuvette(){
  empiler(element,D,D,D,D,right);
  empiler(element,D,D,D,D,left);
  
  empiler(element,D,D,D,W,right);
  empiler(element,D,D,D,D,stop);
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Loading");
  loadDepartBuvette();
  if(element != NULL){
    Serial.println("OK");
  }else{
    Serial.println("Not ok");
  }
  //afficher(tete);
  
}
