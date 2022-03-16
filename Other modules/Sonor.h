#ifndef SONOR_H
	#define TRIG_PIN 2
	#define ECHO_PIN 4
	#define speedSonor 59
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
