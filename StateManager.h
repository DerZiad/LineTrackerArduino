#ifndef STATE_H

#define POUSSOIR_PIN A0

#endif
class StateManager{
	public:
		StateManager(){
			pinMode(POUSSOIR_PIN,INPUT_PULLUP); 
		}

		int canActivate(){
			  int btnVal=analogRead(POUSSOIR_PIN);  
  			if(btnVal<200){ 
    			return 1;
  			}
  			return 0;
		}
};
