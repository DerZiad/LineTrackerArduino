#include <SPI.h>
#include <MFRC522.h>
#ifndef PILE_H
  #include "Pile.h"
#endif
#include "Robot.h"
#include "db.h"
#include "Sonor.h"

#ifndef CONSTANTE_H
  #include "Constante.h"
#endif

byte card_ID[4];
byte X[4]={247,84,186,78}; // AMPHI 250
byte Y[4]={247,84,186,78}; // AMPHI 450
byte Z[4]={247,71,184,77}; // Buvette
byte Q[4]={39,35,186,78}; // BIB
byte P[4]={07,49,179,78}; // ADMINISTRATION
int mouvement;

String target = "";

Element *nextNoeud = NULL;
int depart = 0;
int passageCarte = 0;
int firstObstacle = 0;
Robot *robot = NULL;
MFRC522 mfrc522(SS_PIN, RST_PIN);
Sonor* sonor = NULL;

int moveTurn =  60;
int moveNoir = 75;
int moveForward = 75;
int moveSeconds = 75;

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
    sonor = new Sonor();
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
  float mesure = sonor->calculateDistance();
  Serial.println(mesure);
  if(mesure > 9){
              if(firstObstacle == 0){
                  int leftPhotoPin = digitalRead(LEFT_PHOTOELECTRIQUE_PIN);
                  int leftMiddlePin =digitalRead(MIDDLE_LEFT_PHOTOELECTRIQUE_PIN);
                  int rightMiddlePin =digitalRead(MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN);
                  int rightPhotoPin = digitalRead(RIGHT_PHOTOELECTRIQUE_PIN);
                  if((leftPhotoPin == W && leftMiddlePin == D && rightMiddlePin == D && rightPhotoPin == W)){
                      Serial.println("Move");
                      robot->move(1,moveForward ,-1);
                    }else {
                        if(leftMiddlePin == W){
                          Serial.println("Devilla lisr");
                          robot->stop(-1,0);
                          robot->turn(1,moveTurn,moveTurn,-1);
                          ajuster();
                        }else if(rightMiddlePin == W){
                          Serial.println("Devilla limn");
                          robot->stop(-1,0);
                          robot->turn(0,moveTurn,moveTurn,-1);
                          ajuster();
                        }else if (leftPhotoPin == W && leftMiddlePin == W && rightMiddlePin == W && rightPhotoPin == D){
                          Serial.println("Devilla lisr");
                          robot->stop(-1,0);
                          robot->turn(1,moveTurn,moveTurn,-1);
                          ajuster();
                          
                        }else if (leftPhotoPin == D && leftMiddlePin == W && rightMiddlePin == W && rightPhotoPin == W){
                          Serial.println("Devilla lisr");
                          robot->stop(-1,0);
                          robot->turn(0,moveTurn,moveTurn,-1);
                          ajuster();
                        }else if (leftPhotoPin == D && leftMiddlePin == D && rightMiddlePin == D && rightPhotoPin == W){
                          robot->move(1,moveForward,-1);
                          while(leftPhotoPin != W || leftMiddlePin != W || rightMiddlePin != W || rightPhotoPin != W){
                            leftPhotoPin = digitalRead(LEFT_PHOTOELECTRIQUE_PIN);
                            leftMiddlePin =digitalRead(MIDDLE_LEFT_PHOTOELECTRIQUE_PIN);
                            rightMiddlePin =digitalRead(MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN);
                            rightPhotoPin = digitalRead(RIGHT_PHOTOELECTRIQUE_PIN);
                          }
                          robot->stop(0,-1);
                          robot->turn(0,moveTurn,moveTurn,-1);
                          ajuster();
                        }else if (leftPhotoPin == W && leftMiddlePin == D && rightMiddlePin == D && rightPhotoPin == D){
                          robot->move(1,moveForward,-1);
                          while(leftPhotoPin != W || leftMiddlePin != W || rightMiddlePin != W || rightPhotoPin != W){
                            leftPhotoPin = digitalRead(LEFT_PHOTOELECTRIQUE_PIN);
                            leftMiddlePin =digitalRead(MIDDLE_LEFT_PHOTOELECTRIQUE_PIN);
                            rightMiddlePin =digitalRead(MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN);
                            rightPhotoPin = digitalRead(RIGHT_PHOTOELECTRIQUE_PIN);
                          }
                          robot->stop(0,-1);
                          robot->turn(1,moveTurn,moveTurn,-1);
                          ajuster();

                        }else if(leftPhotoPin == D && leftMiddlePin == D && rightMiddlePin == D && rightPhotoPin == W){
                          robot->move(1,100,-1);
                          while(leftPhotoPin != W || leftMiddlePin != W || rightMiddlePin != W || rightPhotoPin != W){
                            leftPhotoPin = digitalRead(LEFT_PHOTOELECTRIQUE_PIN);
                            leftMiddlePin =digitalRead(MIDDLE_LEFT_PHOTOELECTRIQUE_PIN);
                            rightMiddlePin =digitalRead(MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN);
                            rightPhotoPin = digitalRead(RIGHT_PHOTOELECTRIQUE_PIN);
                          }
                          robot->stop(0,-1);
                          robot->turn(0,moveTurn,moveTurn,-1);
                          ajuster();
                        }else{
                          robot->stop(-1,0);
                        }
                    }
              }else{
                    if(mouvement==0){
                      loadSetup();
                    }else{
              int leftPhotoPin = digitalRead(LEFT_PHOTOELECTRIQUE_PIN);
              int leftMiddlePin =digitalRead(MIDDLE_LEFT_PHOTOELECTRIQUE_PIN);
              int rightMiddlePin =digitalRead(MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN);
              int rightPhotoPin = digitalRead(RIGHT_PHOTOELECTRIQUE_PIN);
              Serial.print(String(leftPhotoPin) + String(leftMiddlePin) +String(rightMiddlePin) + String(rightPhotoPin));
              if(nextNoeud->digits[0] == leftPhotoPin && nextNoeud->digits[1] == leftMiddlePin && nextNoeud->digits[2] == rightMiddlePin && nextNoeud->digits[3] == rightPhotoPin){
                if(leftPhotoPin == D && leftMiddlePin == D && rightMiddlePin == D && rightPhotoPin == D){
                    if(nextNoeud->action == 1){
                      robot->move(1,moveNoir,-1);
                      while(leftPhotoPin != W || leftMiddlePin != W || rightMiddlePin != W || rightPhotoPin != W){
                        leftPhotoPin = digitalRead(LEFT_PHOTOELECTRIQUE_PIN);
                        leftMiddlePin =digitalRead(MIDDLE_LEFT_PHOTOELECTRIQUE_PIN);
                        rightMiddlePin =digitalRead(MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN);
                        rightPhotoPin = digitalRead(RIGHT_PHOTOELECTRIQUE_PIN);
                      }
                      robot->stop(-1,0);
                      robot->turn(1,moveTurn,moveTurn,-1);              
                      ajuster();
                      
                  }else if (nextNoeud->action == 2){
                      robot->move(1,moveForward,-1);
                      while(leftPhotoPin != W || leftMiddlePin != W || rightMiddlePin != W || rightPhotoPin != W){
                        leftPhotoPin = digitalRead(LEFT_PHOTOELECTRIQUE_PIN);
                        leftMiddlePin =digitalRead(MIDDLE_LEFT_PHOTOELECTRIQUE_PIN);
                        rightMiddlePin =digitalRead(MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN);
                        rightPhotoPin = digitalRead(RIGHT_PHOTOELECTRIQUE_PIN);
                      }
                      robot->stop(-1,0);
                      robot->turn(0,moveTurn,moveTurn,-1);
                      ajuster();
                  }else if(nextNoeud->action == 3){
                      Serial.println("STOP");
                      robot->stop(-1,1);
                      mouvement = 0;
                  }
                }else{
                    if(nextNoeud->action == 1){
                      robot->move(1,moveSeconds,0.5);
                      robot->stop(-1,0);
                      robot->turn(1,moveTurn,moveTurn,-1);
                      ajuster();
                      robot->stop(-1,0);
                      ajuster();
                      
                  }else if (nextNoeud->action == 2){
                      robot->move(1,moveSeconds,0.5);
                      robot->stop(-1,0);
                      robot->turn(0,moveTurn,moveTurn,1);
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
                  robot->move(1,moveForward ,-1);
                }else {
                    if(leftMiddlePin == W){
                      Serial.println("Devilla lisr");
                      robot->stop(-1,0);
                      robot->turn(1,moveTurn,moveTurn,-1);
                      ajuster();
                    }else if(rightMiddlePin == W){
                      Serial.println("Devilla limn");
                      robot->stop(-1,0);
                      robot->turn(0,moveTurn,moveTurn,-1);
                      ajuster();
                    }else if (leftPhotoPin == W && leftMiddlePin == W && rightMiddlePin == W && rightPhotoPin == D){
                      Serial.println("Devilla lisr");
                      robot->stop(-1,0);
                      robot->turn(1,moveTurn,moveTurn ,-1);
                      ajuster();
                      
                    }else if (leftPhotoPin == D && leftMiddlePin == W && rightMiddlePin == W && rightPhotoPin == W){
                      Serial.println("Devilla lisr");
                      robot->stop(-1,0);
                      robot->turn(0,moveTurn,moveTurn,-1);
                      ajuster();
                      
                    }else{
                      robot->stop(-1,0);
                    }
                }
              }    
        }
              }
              
                
    }else{
    robot->stop(0,-1);
    if(firstObstacle == 0){
      if(mouvement==0){
        loadSetup();
      }
      firstObstacle = 1;
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
     Serial.print(card_ID[i] + "-");
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
