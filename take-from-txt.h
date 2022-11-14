#ifndef GENERATEUR_DE_PHRASE_TAKE_FROM_TXT_H
#define GENERATEUR_DE_PHRASE_TAKE_FROM_TXT_H

char* takeLineFromTxt(int indexLineToExtract,int argument);// -> return toute la ligne n°ligne
char* extractAgreeFormeFromLine(int indexLineToExtract); //-> return la forme fléchis de la ligne envoyer
char* extractBaseFormeFromLine(int indexLineToExtract); //-> return la forme de base de la ligne envoyer
char* extractInformationFromLine(int indexLineToExtract); //-> return les informations de la ligne envoyer

#endif //GENERATEUR_DE_PHRASE_TAKE_FROM_TXT_H
