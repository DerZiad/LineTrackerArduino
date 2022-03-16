#include <SPI.h>
#include <MFRC522.h>
#include "Pile.h"
#include "Robot.h"
#include "db.h"
#define LEFT_PHOTOELECTRIQUE_PIN 2
#define MIDDLE_LEFT_PHOTOELECTRIQUE_PIN 3
#define MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN 4
#define RIGHT_PHOTOELECTRIQUE_PIN 5
#define SS_PIN 10
#define RST_PIN 8

#ifndef CONSTANTE_H
  #include "Constance.h"
#endif

byte card_ID[4];
byte X[4]={0xC0,0xC7,0xDA,0x32}; // AMPHI 250
byte Y[4]={0xC0,0xC7,0xDA,0x32}; // AMPHI 450
byte Z[4]={0xC0,0xC7,0xDA,0x32}; // Buvette
byte Q[4]={0xC0,0xC7,0xDA,0x32}; // BIB
byte P[4]={0xC0,0xC7,0xDA,0x32}; // ADMINISTRATION
int mouvement = 0;

String target = "";
String startPlace = "DEPART";

Element *nextNoeud = NULL;
Robot *robot = NULL;
Element *tete = NULL;
MFRC522 mfrc522(SS_PIN, RST_PIN);

//Functions
void loadSetup();

void setup() {
    //Initialisation des capteurs
    pinMode(LEFT_PHOTOELECTRIQUE_PIN,INPUT);
    pinMode(MIDDLE_LEFT_PHOTOELECTRIQUE_PIN,INPUT);
    pinMode(MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN,INPUT);
    pinMode(RIGHT_PHOTOELECTRIQUE_PIN,INPUT);

    //Initialisation de la card RFID
    SPI.begin();  
    mfrc522.PCD_Init(); 

    robot = new Robot();
    Serial.begin(9600);
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
  }
  
  int leftPhotoPin = digitalRead(LEFT_PHOTOELECTRIQUE_PIN);
  int leftMiddlePin =digitalRead(MIDDLE_LEFT_PHOTOELECTRIQUE_PIN);
  int rightMiddlePin =digitalRead(MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN);
  int rightPhotoPin = digitalRead(RIGHT_PHOTOELECTRIQUE_PIN);

    if(nextNoeud->digits[0] == leftPhotoPin && nextNoeud->digits[1] == leftMiddlePin && nextNoeud->digits[2] == rightMiddlePin && nextNoeud->digits[3] == rightPhotoPin){
      //robot->stop(0,1);
      if(nextNoeud->action.equals("RIGHT")){
        //robot->turn(1)

      leftPhotoPin = digitalRead(LEFT_PHOTOELECTRIQUE_PIN);
      leftMiddlePin =digitalRead(MIDDLE_LEFT_PHOTOELECTRIQUE_PIN);
      rightMiddlePin =digitalRead(MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN);
      rightPhotoPin = digitalRead(RIGHT_PHOTOELECTRIQUE_PIN);

      while(leftPhotoPin != W || leftMiddlePin != D || rightMiddlePin != D || rightPhotoPin != W){
        leftPhotoPin = digitalRead(LEFT_PHOTOELECTRIQUE_PIN);
        leftMiddlePin =digitalRead(MIDDLE_LEFT_PHOTOELECTRIQUE_PIN);
        rightMiddlePin =digitalRead(MIDDLE_RIGHT_PHOTOELECTRIQUE_PIN);
        rightPhotoPin = digitalRead(RIGHT_PHOTOELECTRIQUE_PIN);
      }

      //robot->stop();
      }else if (nextNoeud->action.equals("LEFT")){
        
      }else if(nextNoeud->action.equals("STOP")){
        
      }

      
    }
   
   
  if(leftPhotoPin == W && leftMiddlePin == D && rightMiddlePin == D && rightPhotoPin == W){
    robot->move(1,100,6);
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
  if(target.equals("AMPHI250") && startPlace.equals("DEPART")) {
    //loadDepartAMPHI250(tete);
  }

  if(target.equals("AMPHI450") && startPlace.equals("DEPART")) {
    
  }

  if(target.equals("BUVETTE") && startPlace.equals("DEPART")) {
    loadDepartBuvette(tete);
  }

  if(target.equals("BIB") && startPlace.equals("DEPART")){
    
  }

  if(target.equals("ADMIN") && startPlace.equals("DEPART")){
    
  }


  //AMPHI250
  if(target.equals("AMPHI450") && startPlace.equals("AMPHI250")) {
    
  }

  if(target.equals("BUVETTE") && startPlace.equals("AMPHI250")) {
    
  }

  if(target.equals("BIB") && startPlace.equals("AMPHI250")){
    
  }

  if(target.equals("ADMIN") && startPlace.equals("AMPHI250")){
    
  }

  //AMPHI450
  if(target.equals("AMPHI250") && startPlace.equals("AMPHI450")) {
    
  }

  if(target.equals("BUVETTE") && startPlace.equals("AMPHI450")) {
    
  }

  if(target.equals("BIB") && startPlace.equals("AMPHI450")){
    
  }

  if(target.equals("ADMIN") && startPlace.equals("AMPHI450")){
    
  }
  nextNoeud = depiler(tete);
  
}
