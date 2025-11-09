#ifndef CONSTANTE_H
	#include "Constante.h"
#endif
class Sonor{	
	public:
		Sonor(){
			pinMode(TRIG_PIN,OUTPUT);
      pinMode(ECHO_PIN,INPUT);
     
		}

		float calculateDistance() {
       float mesure;
			 digitalWrite(TRIG_PIN, LOW);
			 delayMicroseconds(2);
			 digitalWrite(TRIG_PIN, HIGH);
			 delayMicroseconds(10);
			 digitalWrite(TRIG_PIN, LOW); 
			 mesure = pulseIn(ECHO_PIN, HIGH);  
			 mesure=mesure/59;
       return mesure;
		} 
};
