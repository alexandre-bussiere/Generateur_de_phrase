#ifndef GENERATEUR_DE_PHRASE_TREE_H
#define GENERATEUR_DE_PHRASE_TREE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "take-from-txt.h"
#include "functionOfListAgreeForm.h"
#include "functionOfListOfSon.h"

char *extractTypeFromChar(int indexLineToExtract);

Node* createNode(char value);
Tree initTree(); //-> return un tree initialiser

bool isSonExisting(Node *currentNode, char letterToSearch); //-> return true s'il a déjà un fils avec la lettre demander, false sinon
void createSonWithGivenLetter(Node *currentNode, char valueOfNewSon); //-> aucun return
Node* giveNodeWithTheGivenLetter(Node *currentNode, char letterToSearch); //-> return le node avec la lettre demander

bool isAgreeExisting(ListChainAgreeForm *currentListOfAgreeForm, int indexLineToExtract); //-> return true s'il a déjà un la forme fléchis, false sinon
void createAgreeForm(ListChainAgreeForm *currentListOfAgreeForm, int indexLineToExtract); //-> aucun return
AllAgreeForm *initAllAgreeForm();

void placeWordInTree(Tree dictionaryInTree, int indexLineToExtract); //-> aucun return


#endif //GENERATEUR_DE_PHRASE_TREE_H
