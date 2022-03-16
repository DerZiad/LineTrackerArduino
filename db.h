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
	empiler(element,D,D,D,D,right);
	empiler(element,D,D,D,D,left);
	empiler(element,D,D,D,W,right);
	empiler(element,D,D,D,D,stop);
}
/*
void loadDepartBIB(Element *element){

	short tab[4] = {D,D,D,W}
	empiler(element,tab,left);
	tab[4] = {D,D,D,W}
	empiler(element,tab,left);
	tab[4] = {D,D,D,D}
	empiler(element,tab,action)
}

void loadDepartADMI(Element *element){
	 short tab[4] = {D,D,D,W}
	 empiler(element,tab,left);
	 tab[4] = {W,D,D,D}
	 empiler(element,tab,right);
	 tab[4] = {D,D,D,D}
	 empiler(element,tab,action);

}

void loadDepartAMPHI250(Element *element){
	 short tab[4] = {D,D,D,D}
	 empiler(element,tab,right);
	 short tab[4] = {D,D,D,D}
	 empiler(element,tab,right);
	 short tab[4] = {D,D,D,D}
	 empiler(element,tab,action);

}

void loadDepartAMPHI450(Element *element){
	short tab[4]={D,D,D,D}
	empiler(element,tab,left);
	short tab[4] = {D,D,D,D}
	empiler(element,tab,action);

}

//Fin Depart

void loadAMPHI250Buvette(Element *element){
	
	short tab[4]={W,D,D,D}
    empiler(element,tab,right);
    short tab[4] = {D,D,D,D}
	empiler(element,tab,action);
}

void loadAMPHI250_450(Element *element){
	short tab[4]={D,D,D,W}
	empiler(element,tab,left);
	short tab[4] = {D,D,D,D}
	empiler(element,tab,action);
}

void loadAMPHI250_BIB(Element *element){
	short tab[4]={D,D,D,W}
	empiler(element,tab,left);
	short tab[4]={D,D,D,W}
	empiler(element,tab,left);
	short tab[4]={W,D,D,D}
	empiler(element,tab,right);
	short tab[4] = {D,D,D,D}
	empiler(element,tab,action);

}

void loadAMPHI250_ADMI(Element *element){
	short tab[4]={D,D,D,W}
	empiler(element,tab,left);
	short tab[4]={D,D,D,W}
	empiler(element,tab,left);
	short tab[4]={D,D,D,W}
	empiler(element,tab,left);
	short tab[4]={W,W,W,D}
	empiler(element,tab,right);
	short tab[4] = {D,D,D,D}
	empiler(element,tab,action);

}

void loadBuvette_AMPHI250(Element *element){
	short tab[4] = {D,D,D,D}
	empiler(element,tab,left);
	short tab[4] = {D,D,D,D}
	empiler(element,tab,action);

}

void loadBuvette_AMPHI450(Element *element){
	short tab[4] = {D,D,D,D}
	empiler(element,tab,left);
	short tab[4]={W,D,D,D}
	empiler(element,tab,right);
	short tab[4] = {D,D,D,D}
	empiler(element,tab,action);

}

void loadBuvette_BIB(Element *element){

	short tab[4] = {D,D,D,D}
	empiler(element,tab,left);
	short tab[4]={W,D,D,D}
	empiler(element,tab,right);
	short tab[4] = {D,D,D,W}
	empiler(element,tab,left);
	short tab[4]={W,D,D,D}
	empiler(element,tab,right);
	short tab[4] = {D,D,D,D}
	empiler(element,tab,action);

}

void loadBuvette_ADMI(Element *element){

	short tab[4] = {D,D,D,D}
	empiler(element,tab,left); 
	short tab[4]={W,D,D,D}
	empiler(element,tab,right);
	short tab[4] = {D,D,D,W}
	empiler(element,tab,left);
	short tab[4]={W,D,D,D}
	empiler(element,tab,right);
	short tab[4]={W,D,D,D}
	empiler(element,tab,right);
	short tab[4] = {D,D,D,D}
	empiler(element,tab,action);


}

// Amphi450
void loadAmphi450Bib(Element *element){
	String action = right
	short tab[4] = {W,D,D,D}
	empiler(element,tab,action);
	action = right
	tab[4] = {W,D,D,D}
	empiler(element,tab,action);
	action = stop
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
	action = stop
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
}

void loadAmphi450Admin(Element *element){
	String action = right
	short tab[4] = {W,D,D,D}
	empiler(element,tab,action);
	action = left
	tab[4] = {D,D,D,W}
	empiler(element,tab,action);
	action = left
	tab[4] = {D,D,D,W}
	empiler(element,tab,action);
	action = stop
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
}

void loadAmphi450Amphi25W(Element *element){
	String action = right
	short tab[4] = {D,D,D,D}
	empiler(element,tab,action);
	action = stop
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
}

void loadAmphi450Buvette(Element *element){
	String action = left
	short tab[4] = {D,D,D,D}
	empiler(element,tab,action);
	action = right
	tab[4] = {W,D,D,D}
	empiler(element,tab,action);
	action = stop
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
}

//Administration
void loadAdminBib(Element *element){
	String action = right
	short tab[4] = {D,D,D,D}
	empiler(element,tab,action);
	action = right
	tab[4] = {W,D,D,D}
	empiler(element,tab,action);
	action = left
	tab[4] = {D,D,D,W}
	empiler(element,tab,action);
	action = stop
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
}

void loadAdminAmphi45W(Element *element){
	String action = right
	short tab[4] = {D,D,D,D}
	empiler(element,tab,action);
	action = right
	tab[4] = {W,D,D,D}
	empiler(element,tab,action);
	action = left
	tab[4] = {D,D,D,W}
	empiler(element,tab,action);
	action = stop
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
}

void loadAdminBuvette(Element *element){
	String action = left
	short tab[4] = {D,D,D,D}
	empiler(element,tab,action);
	action = left
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
	action = right
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
	action = left
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
	action = right
	tab[4] = {W,D,D,D}
	empiler(element,tab,action);
	action = stop
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
}

void loadAdminAmphi25W(Element *element){
	String action = left
	short tab[4] = {D,D,D,D}
	empiler(element,tab,action);
	action = left
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
	action = right
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
	action = right
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
	action = stop
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
}


// Bibliothèque
void loadBibAmphi450(Element *element){
	String action = left
	short tab[4] = {D,D,D,D}
	empiler(element,tab,action);
	action = left
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
	action = stop
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
}

void loadBibAdmin(Element *element){
	String action = right
	short tab[4] = {D,D,D,D}
	empiler(element,tab,action);
	action = left
	tab[4] = {W,D,D,D}
	empiler(element,tab,action);
	action = left
	tab[4] = {W,D,D,D}
	empiler(element,tab,action);
	action = stop
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
}

void loadBibBuvette(Element *element){
	String action = left
	short tab[4] = {D,D,D,D}
	empiler(element,tab,action);
	action = right
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
	action = left
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
	action = right
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
	action = stop
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
}

void loadBibAmphi250(Element *element){
	String action = left
	short tab[4] = {D,D,D,D}
	empiler(element,tab,action);
	action = right
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
	action = left
	tab[4] = {D,D,D,D}
	action = stop
	tab[4] = {D,D,D,D}
	empiler(element,tab,action);
}*/