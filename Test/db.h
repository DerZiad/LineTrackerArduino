#ifndef PILE_H
	#include "Pile.h"
#endif
#ifndef CONSTANTE_H
	#include "Constance.h"
#endif


static String right = "RIGHT";
static String left = "LEFT";
//static String forward = "FORWARD"
static String stope = "STOP";


void loadDepartBuvette(){
	empiler(D,D,D,D,stope);
	empiler(D,D,D,W,right);
	empiler(D,D,D,D,left);
	empiler(D,D,D,D,right);
	
}

void loadDepartBIB(){
	
	empiler(D,D,D,D,stope);
	empiler(D,D,D,W,left);
	empiler(D,D,D,W,left);
}

void loadDepartADMI(){

	 empiler(D,D,D,D,stope);
	 empiler(W,D,D,D,right);
	 empiler(D,D,D,W,left);

}

void loadDepartAMPHI250(){
	 
	 empiler(D,D,D,D,stope);
	 empiler(D,D,D,D,right);
	 empiler(D,D,D,D,right);

}

void loadDepartAMPHI450(){
	
	empiler(D,D,D,D,stope);
	empiler(D,D,D,D,left);

}


void loadBibAmphi250(){

	empiler(D,D,D,D,stope);
	empiler(D,D,D,D,left);
	empiler(D,D,D,D,right);
    empiler(D,D,D,D,left);

}

void loadBibBuvette(){

	empiler(D,D,D,D,stope);
	empiler(D,D,D,D,right);
	empiler(D,D,D,D,left);
	empiler(D,D,D,D,right);
	empiler(D,D,D,D,left);

}

void loadBibAdmin(){

	empiler(D,D,D,D,stope);
	empiler(W,D,D,D,left);
	empiler(W,D,D,D,left);
	empiler(D,D,D,D,right);
	
}

// BibliothÃ¨que
void loadBibAmphi450(){
	
	empiler(D,D,D,D,stope);
	empiler(D,D,D,D,left);
	empiler(D,D,D,D,left);
}

void loadAdminAmphi250(){

	empiler(D,D,D,D,stope);
	empiler(D,D,D,D,right);
	empiler(D,D,D,D,right);
	empiler(D,D,D,D,left);
	empiler(D,D,D,D,left);
}

void loadAdminBuvette(){

	empiler(D,D,D,D,stope);
	empiler(W,D,D,D,right);
	empiler(D,D,D,D,left);
	empiler(D,D,D,D,right);
	empiler(D,D,D,D,left);
	empiler(D,D,D,D,left);	
	
}

void loadAdminAmphi450(){

	empiler(D,D,D,D,stope);
	empiler(D,D,D,W,left);
	empiler(W,D,D,D,right);
	empiler(D,D,D,D,right);
	
}

//Administration
void loadAdminBib(){

	empiler(D,D,D,D,stope);
	empiler(D,D,D,W,left);
	empiler(W,D,D,D,right);
	empiler(D,D,D,D,right);
	
}

void loadAmphi450Buvette(){
	
	empiler(D,D,D,D,stope);
	empiler(W,D,D,D,right);
	empiler(D,D,D,D,left);
	
}

void loadAmphi450Amphi250(){
	
	empiler(D,D,D,D,stope);
	empiler(D,D,D,D,right);
}

void loadAmphi450Admin(){
	
	empiler(D,D,D,D,stope);
	empiler(D,D,D,W,left);
	empiler(D,D,D,W,left);
	empiler(W,D,D,D,right);
}

void loadAmphi450Bib(){
	
	empiler(D,D,D,D,stope);
	empiler(W,D,D,D,right);
	empiler(W,D,D,D,right);
	
}

void loadBuvette_ADMI(){

	empiler(D,D,D,D,stope);
	empiler(W,D,D,D,right);
	empiler(W,D,D,D,right);
	empiler(D,D,D,W,left);
    empiler(W,D,D,D,right);
	empiler(D,D,D,D,left); 

}

void loadBuvette_AMPHI250(){
	
	empiler(D,D,D,D,stope);
	empiler(D,D,D,D,left);

}

void loadBuvette_AMPHI450(){
	
	empiler(D,D,D,D,stope);
	empiler(W,D,D,D,right);
	empiler(D,D,D,D,left);

}

void loadBuvette_BIB(){

	empiler(D,D,D,D,stope);
	empiler(W,D,D,D,right);
	empiler(D,D,D,W,left);
	empiler(W,D,D,D,right);
	empiler(D,D,D,D,left);

}

void loadAMPHI250Buvette(){
	
	empiler(D,D,D,D,stope);
	empiler(W,D,D,D,right);
}

void loadAMPHI250_450(){

	empiler(D,D,D,D,stope);
	empiler(D,D,D,W,left);
}

void loadAMPHI250_BIB(){

	empiler(D,D,D,D,stope);
    empiler(W,D,D,D,right);
	empiler(D,D,D,W,left);
	empiler(D,D,D,W,left);

}

void loadAMPHI250_ADMI(){

	empiler(D,D,D,D,stope);
	empiler(W,W,W,D,right);
	empiler(D,D,D,W,left);
	empiler(D,D,D,W,left);
	empiler(D,D,D,W,left);
	
	
}
