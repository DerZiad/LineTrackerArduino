#ifndef DB_H
	#include "Pile.h"
#endif

#include "Constante.h"
void loadDepartBuvette(Element *element){
	String action = "RIGHT"
	short tab[4] = {1,1,1,1}
	empiler(element,tab,action);
	action = "LEFT"
	tab[4] = {1,1,1,1}
	empiler(element,tab,action);
	String action = "RIGHT"
	tab[4] = {1,1,1,0}
	empiler(element,tab,action);
}
