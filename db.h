#ifndef PILE_H
	#include "Pile.h"
#endif
#ifndef CONSTANTE_H
	#include "Constance.h"
#endif


static String right = "RIGHT";
static String left = "LEFT";
//static String forward = "FORWARD"
static String stop = "STOP";


void loadDepartBuvette(Element *element){
	empiler(element,D,D,D,D,stop);
	empiler(element,D,D,D,W,right);
	empiler(element,D,D,D,D,left);
	empiler(element,D,D,D,D,right);
	
}

void loadDepartBuvette(Element *element){
	
	empiler(element,D,D,D,D,stop);
	empiler(element,D,D,D,W,right);
	empiler(element,D,D,D,D,left);
	empiler(element,D,D,D,D,right);
}

void loadDepartBIB(Element *element){
	
	empiler(element,D,D,D,D,stop);
	empiler(element,D,D,D,W,left);
	empiler(element,D,D,D,W,left);
}

void loadDepartADMI(Element *element){

	 empiler(element,D,D,D,D,stop);
	 empiler(element,W,D,D,D,right);
	 empiler(element,D,D,D,W,left);

}

void loadDepartAMPHI250(Element *element){
	 
	 empiler(element,D,D,D,D,stop);
	 empiler(element,D,D,D,D,right);
	 empiler(element,D,D,D,D,right);

}

void loadDepartAMPHI450(Element *element){
	
	empiler(element,D,D,D,D,stop);
	empiler(element,D,D,D,D,left);

}


void loadBibAmphi250(Element *element){

	empiler(element,D,D,D,D,stop);
	empiler(element,D,D,D,D,left);
	empiler(element,D,D,D,D,right);
    empiler(element,D,D,D,D,left);

}

void loadBibBuvette(Element *element){

	empiler(element,D,D,D,D,stop);
	empiler(element,D,D,D,D,right);
	empiler(element,D,D,D,D,left);
	empiler(element,D,D,D,D,right);
	empiler(element,D,D,D,D,left);

}

void loadBibAdmin(Element *element){

	empiler(element,D,D,D,D,stop);
	empiler(element,W,D,D,D,left);
	empiler(element,W,D,D,D,left);
	empiler(element,D,D,D,D,right);
	
}

// BibliothÃ¨que
void loadBibAmphi450(Element *element){
	
	empiler(element,D,D,D,D,stop);
	empiler(element,D,D,D,D,left);
	empiler(element,D,D,D,D,left);
}

void loadAdminAmphi250(Element *element){

	empiler(element,D,D,D,D,stop);
	empiler(element,D,D,D,D,right);
	empiler(element,D,D,D,D,right);
	empiler(element,D,D,D,D,left);
	empiler(element,D,D,D,D,left);
}

void loadAdminBuvette(Element *element){

	empiler(element,D,D,D,D,stop);
	empiler(element,W,D,D,D,right);
	empiler(element,D,D,D,D,left);
	empiler(element,D,D,D,D,right);
	empiler(element,D,D,D,D,left);
	empiler(element,D,D,D,D,left);	
	
}

void loadAdminAmphi450(Element *element){

	empiler(element,D,D,D,D,stop);
	empiler(element,D,D,D,W,left);
	empiler(element,W,D,D,D,right);
	empiler(element,D,D,D,D,right);
	
}

//Administration
void loadAdminBib(Element *element){

	empiler(element,D,D,D,D,stop);
	empiler(element,D,D,D,W,left);
	empiler(element,W,D,D,D,right);
	empiler(element,D,D,D,D,right);
	
}

void loadAmphi450Buvette(Element *element){
	
	empiler(element,D,D,D,D,stop);
	empiler(element,W,D,D,D,right);
	empiler(element,D,D,D,D,left);
	
}

void loadAmphi450Amphi250(Element *element){
	
	empiler(element,D,D,D,D,stop);
	empiler(element,D,D,D,D,right);
}

void loadAmphi450Admin(Element *element){
	
	empiler(element,D,D,D,D,stop);
	empiler(element,D,D,D,W,left);
	empiler(element,D,D,D,W,left);
	empiler(element,W,D,D,D,right);
}

void loadAmphi450Bib(Element *element){
	
	empiler(element,D,D,D,D,stop);
	empiler(element,W,D,D,D,right);
	empiler(element,W,D,D,D,right);
	
}

void loadBuvette_ADMI(Element *element){

	empiler(element,D,D,D,D,stop);
	empiler(element,W,D,D,D,right);
	empiler(element,W,D,D,D,right);
	empiler(element,D,D,D,W,left);
    empiler(element,W,D,D,D,right);
	empiler(element,D,D,D,D,left); 

}

void loadBuvette_AMPHI250(Element *element){
	
	empiler(element,D,D,D,D,stop);
	empiler(element,D,D,D,D,left);

}

void loadBuvette_AMPHI450(Element *element){
	
	empiler(element,D,D,D,D,stop);
	empiler(element,W,D,D,D,right);
	empiler(element,D,D,D,D,left);

}

void loadBuvette_BIB(Element *element){

	empiler(element,D,D,D,D,stop);
	empiler(element,W,D,D,D,right);
	empiler(element,D,D,D,W,left);
	empiler(element,W,D,D,D,right);
	empiler(element,D,D,D,D,left);

}

void loadAMPHI250Buvette(Element *element){
	
	empiler(element,D,D,D,D,stop);
	empiler(element,W,D,D,D,right);
}

void loadAMPHI250_450(Element *element){

	empiler(element,D,D,D,D,stop);
	empiler(element,D,D,D,W,left);
}

void loadAMPHI250_BIB(Element *element){

	empiler(element,D,D,D,D,stop);
    empiler(element,W,D,D,D,right);
	empiler(element,D,D,D,W,left);
	empiler(element,D,D,D,W,left);

}

void loadAMPHI250_ADMI(Element *element){

	empiler(element,D,D,D,D,stop);
	empiler(element,W,W,W,D,right);
	empiler(element,D,D,D,W,left);
	empiler(element,D,D,D,W,left);
	empiler(element,D,D,D,W,left);
	
	
}