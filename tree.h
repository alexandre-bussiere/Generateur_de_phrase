#ifndef GENERATEUR_DE_PHRASE_TREE_H
#define GENERATEUR_DE_PHRASE_TREE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "take-from-txt.h"
#include "functionOfListAgreeForm.h"

char *extractTypeFromChar(char *line);

Node* createNode(char value);
Tree initTree(); //-> return un tree initialiser

bool isSonExisting(Node *currentNode, char letterToSearch); //-> return true s'il a déjà un fils avec la lettre demander, false sinon
void createSonWithGivenLetter(Node *currentNode, char valueOfNewSon); //-> aucun return
Node* giveNodeWithTheGivenLetter(Node *currentNode, char letterToSearch); //-> return le node avec la lettre demander

void placeWordInTree(Tree dictionaryInTree, int line); //-> aucun return


#endif //GENERATEUR_DE_PHRASE_TREE_H
