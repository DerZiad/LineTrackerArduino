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
				pinMode(ENABLEPIN1, OUTPUT);
	 	}


	  	void move(short direction = 1,short vitesse = 200,short delai = 2){

	  		//Vitesse
	  		analogWrite(enablePin1, abs(vitesse));
	      	analogWrite(enablePin2, abs(vitesse));

	      	//Stop freinage
	      	digitalWrite(motorPin2, LOW);
	      	digitalWrite(motorPin4, LOW);

	      	//Direction 1 Forward et 0 Backward
	  		if(direction == 1){
	  			digitalWrite(motorPin1, HIGH); 
	        	Serial.print("Avant M1");
		        digitalWrite(motorPin3, HIGH); 
		        Serial.print("Avant M2");
	  		}else{
	  			digitalWrite(motorPin1, LOW); 
	        	Serial.print("Arriere M1");
		        digitalWrite(motorPin3, LOW); 
		        Serial.print("Arriere M2");
	  		}
	  		
		    if(delai != -1){
		    	delay(delai * 1000);
		    }
		}

		void turn(short direction = 1,short vitesseLeft = 200,short vitesseRight=200,short delai = 2){

	  		//Vitesse
	  		analogWrite(enablePin1, abs(vitesseLeft));
	      	analogWrite(enablePin2, abs(vitesseRight));

	      	//Stop freinage
	      	digitalWrite(motorPin2, LOW);
	      	digitalWrite(motorPin4, LOW);

	      	//Direction 1 Right et 0 left
	  		if(direction == 1){
	  			digitalWrite(motorPin1, HIGH); 
	        	Serial.print("Avant M1");
		        digitalWrite(motorPin3, LOW); 
		        Serial.print("Avant M2");
	  		}else{
	  			digitalWrite(motorPin1, LOW); 
	        	Serial.print("Arriere M1");
		        digitalWrite(motorPin3, HIGH); 
		        Serial.print("Arriere M2");
	  		}
	  		
		    if(delai != -1){
		    	delay(delai * 1000);
		    }
		}

		void stop(short delai = 2){
			digitalWrite(motorPin2, HIGH);
	      	digitalWrite(motorPin4, HIGH);

	      	if(delai == -1){
	      		delay(delai * 1000);
	      	}
		}


};