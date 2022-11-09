#include "tree.h"

Node *createNode(char value) {
    Node *newNode;

    newNode->value = value;
    (newNode->list).tail = NULL;
    (newNode->list).head = NULL;
    newNode->agreeForm = NULL;

    return newNode;
}

//return un tree initialiser
Tree initTree() {
    Tree tree;

    tree.adj = NULL;
    tree.adv = NULL;
    tree.ver = NULL;
    tree.nom = NULL;

    return tree;
}



// return true s'il a déjà un fils avec la lettre demander, false sinon
bool isSonExisting(Node *currentNode, char letterToSearch) {
    ListChainSon allSon = currentNode->list;
    CelloflistChainSon *temporary = allSon.head;
    while (temporary != allSon.tail) {
        if ((temporary->value)->value == letterToSearch) {
            return true;
        }
        temporary = temporary->next;
    }
    return false;
}


void createSonWithGivenLetter(Node *currentNode, char valueOfNewSon) {
    if (!isSonExisting(currentNode, valueOfNewSon)) {
        CelloflistChainSon *newNode = malloc(sizeof(CelloflistChainSon));
        newNode->next = NULL;
        newNode->value = createNode(valueOfNewSon);
    }
    return;
}


//return le node avec la lettre demander
Node *giveNodeWithTheGivenLetter(Node *currentNode, char letterToSearch) {

}


void placeWordInTree(Tree dictionaryInTree, int line) {

}


