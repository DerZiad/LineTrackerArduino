#ifndef CONSTANTE_H
	//#include "Sonor.h"
#endif
class Sonor{	
	public:
		Sonor(){
		}

		float calculateDistance(float &mesure) {
			 digitalWrite(TRIG_PIN, LOW);
			 delayMicroseconds(2);
			 digitalWrite(TRIG_PIN, HIGH);
			 delayMicroseconds(10);
			 digitalWrite(TRIG_PIN, LOW); 
			 mesure = pulseIn(ECHO_PIN, HIGH);  
			 mesure=mesure/speedSonor;
       Serial.println(mesure);
       delay(200);
		} 
};
