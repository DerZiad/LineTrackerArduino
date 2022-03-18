#include <SPI.h>
#include <MFRC522.h>
#ifndef PILE_H
  #include "Pile.h"
#endif
#include "Robot.h"
#include "db.h"
#define LEFT_PHOTOELECTRIQUE_PIN 11
#define MIDDLE_LEFT_PHOTOELECTRIQUE_PIN 10
#define MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN 9
#define RIGHT_PHOTOELECTRIQUE_PIN 8
#define SS_PIN 53
#define RST_PIN 5

#ifndef CONSTANTE_H
  #include "Constante.h"
#endif

byte card_ID[4];
byte X[4]={0xC0,0xC7,0xDA,0x32}; // AMPHI 250
byte Y[4]={0xC0,0xC7,0xDA,0x32}; // AMPHI 450
byte Z[4]={80,52,58,82}; // Buvette
byte Q[4]={0xC0,0xC7,0xDA,0x32}; // BIB
byte P[4]={0xC0,0xC7,0xDA,0x32}; // ADMINISTRATION
int mouvement;

String target = "";

Element *nextNoeud = NULL;
Robot *robot = NULL;
MFRC522 mfrc522(SS_PIN, RST_PIN);

//Functions
void loadSetup();
void ajuster();

void setup() {
    mouvement = 0;
    //Initialisation des capteurs
    pinMode(LEFT_PHOTOELECTRIQUE_PIN,INPUT);
    pinMode(MIDDLE_LEFT_PHOTOELECTRIQUE_PIN,INPUT);
    pinMode(MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN,INPUT);
    pinMode(RIGHT_PHOTOELECTRIQUE_PIN,INPUT);

    //Initialisation de la card RFID
    SPI.begin();  
    mfrc522.PCD_Init(); 
    Serial.begin(9600);
    robot = new Robot();
}

void getTarget(){
  if(card_ID[0] == X[0]&& card_ID[1] == X[1] && card_ID[2] == X[2] && card_ID[3] == X[3]){
    target = "AMPHI250";
  }

  if(card_ID[0] == Y[0]&& card_ID[1] == Y[1] && card_ID[2] == Y[2] && card_ID[3] == Y[3]){
    target = "AMPHI450";
  }

  if(card_ID[0] == Z[0]&& card_ID[1] == Z[1] && card_ID[2] == Z[2] && card_ID[3] == Z[3]){
     target = "BUVETTE";
  }

  if(card_ID[0] == Q[0]&& card_ID[1] == Q[1] && card_ID[2] == Q[2] && card_ID[3] == Q[3]){
    target = "BIB";
  }

  if(card_ID[0] == P[0]&& card_ID[1] == P[1] && card_ID[2] == P[2] && card_ID[3] == P[3]){
    target = "ADMIN";
  }
}

void loop() {
  if(mouvement==0){
    loadSetup();
  }else{
        int leftPhotoPin = digitalRead(LEFT_PHOTOELECTRIQUE_PIN);
        int leftMiddlePin =digitalRead(MIDDLE_LEFT_PHOTOELECTRIQUE_PIN);
        int rightMiddlePin =digitalRead(MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN);
        int rightPhotoPin = digitalRead(RIGHT_PHOTOELECTRIQUE_PIN);
        if(nextNoeud->digits[0] == leftPhotoPin && nextNoeud->digits[1] == leftMiddlePin && nextNoeud->digits[2] == rightMiddlePin && nextNoeud->digits[3] == rightPhotoPin){
          if(leftPhotoPin == D && leftMiddlePin == D && rightMiddlePin == D && rightPhotoPin == D){
              if(nextNoeud->action == 1){
                robot->move(1,100,-1);
                while(leftPhotoPin != W || leftMiddlePin != W || rightMiddlePin != W || rightPhotoPin != W){
                  leftPhotoPin = digitalRead(LEFT_PHOTOELECTRIQUE_PIN);
                  leftMiddlePin =digitalRead(MIDDLE_LEFT_PHOTOELECTRIQUE_PIN);
                  rightMiddlePin =digitalRead(MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN);
                  rightPhotoPin = digitalRead(RIGHT_PHOTOELECTRIQUE_PIN);
                }
                robot->stop(-1,0);
                robot->turn(1,60,60,-1);              
                ajuster();
                
            }else if (nextNoeud->action == 2){
                robot->move(1,100,-1);
                while(leftPhotoPin != W || leftMiddlePin != W || rightMiddlePin != W || rightPhotoPin != W){
                  leftPhotoPin = digitalRead(LEFT_PHOTOELECTRIQUE_PIN);
                  leftMiddlePin =digitalRead(MIDDLE_LEFT_PHOTOELECTRIQUE_PIN);
                  rightMiddlePin =digitalRead(MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN);
                  rightPhotoPin = digitalRead(RIGHT_PHOTOELECTRIQUE_PIN);
                }
                robot->stop(-1,0);
                robot->turn(0,60,60,-1);
                ajuster();
            }else if(nextNoeud->action == 3){
                Serial.println("STOP");
                robot->stop(-1,1);
                mouvement = 0;
            }
          }else{
              if(nextNoeud->action == 1){
                robot->move(1,60,0.5);
                robot->stop(-1,0);
                robot->turn(1,70,70,-1);
                ajuster();
                robot->stop(-1,0);
                ajuster();
                
            }else if (nextNoeud->action == 2){
                robot->move(1,60,0.5);
                robot->stop(-1,0);
                robot->turn(0,70,70,1);
                ajuster();
                robot->stop(-1,0);
                ajuster();
            }else if(nextNoeud->action == 3){
                Serial.println("STOP");
                robot->stop(-1,1);
                mouvement = 0;
            }
          }
          robot->stop(-1,0);
          
          nextNoeud = depiler();
        }else{
          if((leftPhotoPin == W && leftMiddlePin == D && rightMiddlePin == D && rightPhotoPin == W) || (leftPhotoPin == D && leftMiddlePin == D && rightMiddlePin == D && rightPhotoPin == W) || (leftPhotoPin == W && leftMiddlePin == D && rightMiddlePin == D && rightPhotoPin == D)){
            Serial.println("Move");
            robot->move(1,120 ,-1);
          }else {
              if(leftMiddlePin == W){
                Serial.println("Devilla lisr");
                robot->stop(-1,0);
                robot->turn(1,40,40,-1);
                ajuster();
              }else if(rightMiddlePin == W){
                Serial.println("Devilla limn");
                robot->stop(-1,0);
                robot->turn(0,40,40,-1);
                ajuster();
              }else if (leftPhotoPin == W && leftMiddlePin == W && rightMiddlePin == W && rightPhotoPin == D){
                Serial.println("Devilla lisr");
                robot->stop(-1,0);
                robot->turn(1,40,40,-1);
                ajuster();
                
              }else if (leftPhotoPin == D && leftMiddlePin == W && rightMiddlePin == W && rightPhotoPin == W){
                Serial.println("Devilla lisr");
                robot->stop(-1,0);
                robot->turn(0,40,40,-1);
                ajuster();
                
              }else{
                robot->stop(-1,0);
              }
          }
        }    
  }
}


void loadSetup(){
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  for (byte i = 0; i < mfrc522.uid.size; i++) {
     card_ID[i]=mfrc522.uid.uidByte[i];
  }

  getTarget();

  //DEPART
  if(target.equals("AMPHI250")) {
   loadDepartAMPHI250();
   mouvement = 1;
  }

  if(target.equals("AMPHI450")) {
    loadDepartAMPHI450();
    mouvement = 1;
  }

  if(target.equals("BUVETTE")) {
   loadDepartBuvette();
   mouvement = 1;
  }

  if(target.equals("BIB")){
    loadDepartBIB();
    mouvement = 1;
  }

  if(target.equals("ADMIN")){
    loadDepartADMI();
    mouvement = 1;
  }
  nextNoeud = depiler();
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
