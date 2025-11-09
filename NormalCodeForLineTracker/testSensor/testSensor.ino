#include "Constante.h"
void setup(){
  pinMode(LEFT_PHOTOELECTRIQUE_PIN,INPUT);
  pinMode(MIDDLE_LEFT_PHOTOELECTRIQUE_PIN,INPUT);
  pinMode(MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN,INPUT);
  pinMode(RIGHT_PHOTOELECTRIQUE_PIN,INPUT);
  Serial.begin(9600);
}

void loop(){
  int leftPhotoPin = digitalRead(LEFT_PHOTOELECTRIQUE_PIN);
     int leftMiddlePin =digitalRead(MIDDLE_LEFT_PHOTOELECTRIQUE_PIN);
     int rightMiddlePin =digitalRead(MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN);
     int rightPhotoPin = digitalRead(RIGHT_PHOTOELECTRIQUE_PIN);
     Serial.println(String(leftPhotoPin) + String(leftMiddlePin) +String(rightMiddlePin) + String(rightPhotoPin));
}
