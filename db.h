#ifndef PILE_H
	#include "Pile.h"
#endif
#ifndef CONSTANTE_H
	#include "Constance.h"
#endif


static int right = 1;
static int left = 2;
static int stope = 3;

void loadDepartBuvette(){
	empiler(D,D,D,D,stope);
	empiler(W,D,D,D,right);
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
