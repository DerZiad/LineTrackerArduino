typedef struct Element Element;
struct Element{
    byte digits[4];
    String action;
    Element* suivant;
};

/*
int afficher(Element *tete){
    Element* iterator = tete;
    int cmp = 0;
    while(iterator != NULL){
        Serial.println("%d ",iterator->number);
        iterator=iterator->suivant;
    }
    return 1;
}*/
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
Element* empiler(Element *tete,byte* digits,String action){

    Element* nouveau = (Element*)malloc(sizeof(Element));

    for(int i=0;i<4;i++){
        nouveau->digits[i] = *(digits + i);
    }
    nouveau->action = action;

    if(tete != NULL){
        nouveau->suivant = tete;
    }else{
        nouveau->suivant = NULL;
    }

    tete = nouveau;
    return nouveau;
}