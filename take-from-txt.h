#ifndef GENERATEUR_DE_PHRASE_TAKE_FROM_TXT_H
#define GENERATEUR_DE_PHRASE_TAKE_FROM_TXT_H

char** takeLineFromTxt(int indexLineToExtract,int argument);  //-> return toute la ligne n°ligne
char* extractAgreeFormeFromLine(char* line); //-> return la forme fléchis de la ligne envoyer
char* extractBaseFormeFromLine(char* line); //-> return la forme de base de la ligne envoyer
char* extractInformationFromLine(char* line); //-> return les informations de la ligne envoyer

#endif //GENERATEUR_DE_PHRASE_TAKE_FROM_TXT_H
