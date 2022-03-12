#ifndef ROBOT_H
	#define VITESSE_M1 3
	#define VITESSE_M2 11
	#define FREIN_M1 8
	#define FREIN_M2 9
	#define SENS_M1 12
	#define SENS_M2 13
	#include "Sonor.h"
  	#include "Printer.h"
#endif
class Robot{
	private:
		Sonor *sonor = NULL;
    	Printer *printer = NULL;
	public:
		Robot(){
			pinMode(VITESSE_M1, OUTPUT); // Vitesse rotation Moteur 1
	 		pinMode(VITESSE_M2, OUTPUT); // Vitesse rotation Moteur 2
	 		pinMode(SENS_M1, OUTPUT); // sens rotation Moteur 1
	 		pinMode(SENS_M2, OUTPUT); // sens rotation Moteur 2
	 		pinMode(FREIN_M1, OUTPUT); // frein Moteur 1
	 		pinMode(FREIN_M2, OUTPUT); // frein Moteur 2
	 		sonor = new Sonor();
      printer = new Printer(0x3F,16,2);
		}

		void move(short direction = 1,short vitesse = 200,short delai = 2){
			//Direction = 1 move forward , Direction = 0 move backward
			//Delai for seconds
				if(direction){
					//Fix M1 sens motor 1
					digitalWrite(SENS_M1, HIGH);    
				    //Fix M2 motor 2
				    digitalWrite(SENS_M2, HIGH);
				}else{
					//Move motor 1
					digitalWrite(SENS_M1, LOW);
				    //Move motor 2
				    digitalWrite(SENS_M2, LOW);
				}
				digitalWrite(FREIN_M2, LOW);
				digitalWrite(FREIN_M1, LOW);
				analogWrite(VITESSE_M2, vitesse); 
				analogWrite(VITESSE_M1, vitesse);
        if(delai != -1){
          delay(delai * 1000); 
        }
		};

		void  stop(int final = 1,short delai = 2){
			//final == 1 will block the thread
			  digitalWrite(9, HIGH); 
		    digitalWrite(8, HIGH);
        if(delai != -1){
          delay(delai*1000);
        }
		    if(final == 1){
		    	while(1 == 1);
		    }else{
		    	digitalWrite(9, LOW);
		    	digitalWrite(8, LOW);
		    }
		}

		void turn(short orientation = 0,short firstMotorSpeed = 200,short secondMotorSpeed = 200,int delai = 2){
			//orientation = 0 for right movement , orientation = 1 for left movement
		    if(orientation==0){
			    digitalWrite(13,LOW);
			    digitalWrite(12,HIGH);
			    
		    }else{
		        digitalWrite(13,HIGH);
		        digitalWrite(12,LOW);
		    }
		    analogWrite(3, firstMotorSpeed);
		    analogWrite(11, secondMotorSpeed);
        if(delai != -1){
          delay(delai * 1000);
        }
		    
 		};

 		void turnAlpha(){
 			short vitesseBoth = 200;
 		}
};
