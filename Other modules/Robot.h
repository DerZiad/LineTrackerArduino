#define motorPin1 8
#define motorPin2 9
class Robot{
	public:
	    Robot(){
                pinMode(motorPin1, OUTPUT);
                pinMode(motorPin2, OUTPUT);
                // Initialisation du port série
                Serial.begin(9600);
	    }


  	void move(short direction = 1,short vitesse = 200
                 ,short delai = 2){

    if (Serial.available() > 0)
                {

      //
      // Sens du mouvement
      //
      if (direction) // avant
      {
        digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, LOW);
        Serial.print("Avant ");
        Serial.println(vitesse);
      }
      else if (direction==0) // arrière
      {
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, HIGH);
        Serial.print("Arriere ");
      }
      else // Stop (freinage)
      {
        digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, HIGH);
        Serial.println("Stop");
      }
      //
      // Vitesse du mouvement
      //
    }
    delay(100);
}
};