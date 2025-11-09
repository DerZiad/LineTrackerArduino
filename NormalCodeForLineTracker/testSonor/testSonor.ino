#ifndef "SONOR_H"
#include "Sonor.h"
#endif

Sonor *sonor = NULL;

void setup(){
  Serial.begin(9600);
  sonor = new Sonor();
}


void loop(){
  float mesure = sonor->calculateDistance();
  Serial.println(mesure);
}
