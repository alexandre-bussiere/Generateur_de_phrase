#ifndef GENERATEUR_DE_PHRASE_FUNCTIONOFLISTOFSON_H
#define GENERATEUR_DE_PHRASE_FUNCTIONOFLISTOFSON_H

#include "struct.h"
#include <stdlib.h>

CelloflistChainSon *createCellSon(char valueOfNewSon);
Node *createNode(char value);

void addCellToListOfSon(ListChainSon *currentListOfSon, char valueOfNewSon);

#endif //GENERATEUR_DE_PHRASE_FUNCTIONOFLISTOFSON_H
