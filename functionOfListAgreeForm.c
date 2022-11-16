#include "functionOfListAgreeForm.h"

void addAgreeForm(int indexLineToExtract, ListChainAgreeForm *currentList) {
    CellOfChainAgreeForm *newCell = malloc(sizeof(CellOfChainAgreeForm));

    strcpy(newCell->category, extractTypeFromChar(indexLineToExtract));
    strcpy(newCell->word, extractAgreeFormeFromLine(indexLineToExtract));
    strcpy(newCell->def, extractInformationFromLine(indexLineToExtract));


    currentList->tail->next = newCell;
    newCell->next = NULL;

    currentList->tail = newCell;
}
