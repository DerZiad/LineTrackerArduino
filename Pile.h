#ifndef PILE_H
#define PILE_H
#endif
typedef struct Element Element;
struct Element{
    short digits[4];
    String action;
    Element* suivant;
};


void afficher(Element *tete){
    Element* iterator = tete;
    int cmp = 1;
    while(iterator != NULL){
        //Serial.print("Element " + cmp + " : " + iterator->action + " ");
        for(int i=0;i<4;i++){
            Serial.print(iterator->digits[i]);
        } 
        Serial.println();
        iterator=iterator->suivant;
        cmp++;
    }
}

Element* depiler(Element *tete){
    Element* temporelle = tete;
    if(temporelle != NULL){
        Element* nouveau = (Element*)malloc(sizeof(Element));
        for(int i=0;i<4;i++){
            nouveau->digits[i] = temporelle->digits[i];
        }
        nouveau->action = temporelle->action;

        tete = tete->suivant;
        free(temporelle);
        return nouveau;
    }
    return NULL;
}
Element* empiler(Element *tete,int x,int y,int z,int k,String action){

    Element* nouveau = (Element*)malloc(sizeof(Element));

    nouveau->digits[0] = x;
    nouveau->digits[1] = y;
    nouveau->digits[2] = z;
    nouveau->digits[3] = k;

    nouveau->action = action;

    if(tete != NULL){
        nouveau->suivant = tete;
    }else{
        nouveau->suivant = NULL;
    }

    tete = nouveau;
    return nouveau;
}
