#define SPEED_A 3
#define SPEED_B 11
#define DIRECTION_A 12
#define DIRECTION_B 13
#define BRAKE_A 8
#define BRAKE_B 9
class Robot{
  public:
      Robot(){
        //Setup Channel A
        pinMode(DIRECTION_A, OUTPUT); //Initialiser le pin du Channel A 
        pinMode(BRAKE_B, OUTPUT); //Initialiser le pin du frein Channel A 
      
        //Setup Channel B
        pinMode(DIRECTION_B, OUTPUT); // Initialiser le pin du Channel B
        pinMode(BRAKE_B, OUTPUT);  // Initialiser le pin du frein Channel B
      }


      void move(short direction = 1,short vitesse = 200,float delai = 2){
        //Speed
        analogWrite(SPEED_A, abs(vitesse));// Speed A motor
        analogWrite(SPEED_B, abs(vitesse)); // Speed B motor
        //Direction 1 Forward et 0 Backward
        if(direction == 1){
            digitalWrite(DIRECTION_A, HIGH); //Définir la direction en Avant du Channel A 
            digitalWrite(DIRECTION_B, LOW); //Définir la direction en Avant du Channel B
        }else{
            digitalWrite(DIRECTION_A, LOW); //Définir la direction en Avant du Channel A 
            digitalWrite(DIRECTION_B, HIGH); //Définir la direction en Avant du Channel A  
        }
        digitalWrite(BRAKE_A, LOW);// Disabling Frein A
        digitalWrite(BRAKE_B, LOW);// Disabling Frein B
        if(delai != -1){
          delay((int)(delai * 1000));
        }
    }

    void turn(short direction = 1,short vitesseA = 200,short vitesseB=200,float delai = 2){
        //Speed
        analogWrite(SPEED_A, abs(vitesseA));// Speed A motor
        analogWrite(SPEED_B, abs(vitesseB)); // Speed B motor
        //Direction 0 Left et 1 Right
        if(direction == 0){
            digitalWrite(DIRECTION_A, HIGH); //Define A Direction
            digitalWrite(DIRECTION_B, HIGH); //Define B Direction
        }else{
            digitalWrite(DIRECTION_A, LOW); //Define A Direction
            digitalWrite(DIRECTION_B, LOW); //Define B Direction 
        }
        digitalWrite(BRAKE_A, LOW);// Disabling Frein A
        digitalWrite(BRAKE_B, LOW);// Disabling Frein B
        if(delai != -1){
          delay((int)(delai * 1000));
        }
    }

    void stop(short delai = 2,short finale = 0){
          digitalWrite(BRAKE_A, HIGH);// Disabling Frein A
          digitalWrite(BRAKE_B, LOW);// Disabling Frein B
  
          if(delai != -1){
            delay(delai * 1000);
          }

          if(finale == 1){
            while(1==1);
          }
    }


};
