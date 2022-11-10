#include "functionOfListOfSon.h"

CelloflistChainSon *createCellSon(char valueOfNewSon) {
    CelloflistChainSon *newNode = malloc(sizeof(CelloflistChainSon));
    newNode->next = NULL;
    newNode->value = createNode(valueOfNewSon);
    return newNode;
}

//GOOD
Node *createNode(char value) {
    Node *newNode = malloc(sizeof(Node));

    newNode->value = value;
    (newNode->list).tail = NULL;
    (newNode->list).head = NULL;
    newNode->agreeForm = NULL;

    return newNode;
}

void addCellToListOfSon(ListChainSon *currentListOfSon, char valueOfNewSon) {
    CelloflistChainSon *newCell = createCellSon(valueOfNewSon);
    if ((currentListOfSon->head == NULL) && (currentListOfSon->tail == NULL)) {
        currentListOfSon->head = newCell;
        currentListOfSon->tail = newCell;
    } else {
        currentListOfSon->tail->next = newCell;
        currentListOfSon->tail = newCell;
    }
}
