#ifndef CONSTANTE_H
  #include "Constante.h"
#endif
class Robot{
  public:
      Robot(){
        pinMode(MOTORPIN1, OUTPUT);
                pinMode(MOTORPIN2, OUTPUT);
                pinMode(ENABLEPIN1, OUTPUT);
        pinMode(MOTORPIN3, OUTPUT);
        pinMode(MOTORPIN4, OUTPUT);
        pinMode(ENABLEPIN2, OUTPUT);
    }


      void move(short direction = 1,short vitesse = 200,float delai = 2){

        //Vitesse
        analogWrite(ENABLEPIN1, abs(vitesse));
          analogWrite(ENABLEPIN2, abs(vitesse));
        
          //Direction 1 Forward et 0 Backward
        if(direction == 1){
            digitalWrite(MOTORPIN2, LOW); 
            digitalWrite(MOTORPIN4, LOW); 
          digitalWrite(MOTORPIN1, HIGH); 
            digitalWrite(MOTORPIN3, HIGH); 
        }else{
          digitalWrite(MOTORPIN2, HIGH); 
            digitalWrite(MOTORPIN1, LOW);
          digitalWrite(MOTORPIN4, HIGH); 
            digitalWrite(MOTORPIN3, LOW); 
        }
        
        if(delai != -1){
          delay((int)(delai * 1000));
        }
    }

    void turn(short direction = 1,short vitesseLeft = 200,short vitesseRight=200,float delai = 2){

        //Vitesse
        analogWrite(ENABLEPIN1, abs(vitesseLeft));
          analogWrite(ENABLEPIN2, abs(vitesseRight));

          //Stop freinage
          
          

          //Direction 1 Right et 0 left
        if(direction == 0){
          digitalWrite(MOTORPIN1, HIGH); 
          digitalWrite(MOTORPIN2, LOW);
            Serial.print("Avant M1");
            digitalWrite(MOTORPIN3, LOW);
           digitalWrite(MOTORPIN4, HIGH); 
            Serial.print("Avant M2");
        }else{
          digitalWrite(MOTORPIN1, LOW); 
           digitalWrite(MOTORPIN2, HIGH);
            Serial.print("Arriere M1");
            digitalWrite(MOTORPIN3, HIGH); 
           digitalWrite(MOTORPIN4, LOW);
            Serial.print("Arriere M2");
        }
        
        if(delai != -1){
          delay((int)(delai * 1000));
        }
    }

    void stop(short delai = 2,short finale = 0){
          digitalWrite(MOTORPIN1, LOW);
          digitalWrite(MOTORPIN2, LOW);
          digitalWrite(MOTORPIN3, LOW);
          digitalWrite(MOTORPIN4, LOW);
  
          if(delai != -1){
            delay(delai * 1000);
          }

          if(finale == 1){
            while(1==1);
          }
    }


};
