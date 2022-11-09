#ifndef GENERATEUR_DE_PHRASE_TREE_H
#define GENERATEUR_DE_PHRASE_TREE_H

#include "struct.h"
#include <stdbool.h>
#include <stdio.h>

Tree initTree(); //-> return un tree initialiser

bool isSonExisting(Node *currentNode, char letterToSearch); //-> return true s'il a déjà un fils avec la lettre demander, false sinon
void createSonWithGivenLetter(Node *currentNode, char valueOfNewSon); //-> aucun return
Node* giveNodeWithTheGivenLetter(Node *currentNode, char letterToSearch); //-> return le node avec la lettre demander

void placeWordInTree(Tree dictionaryInTree, int line); //-> aucun return


#endif //GENERATEUR_DE_PHRASE_TREE_H
