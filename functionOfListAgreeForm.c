#include "functionOfListAgreeForm.h"

void addAgreeForm(int indexLineToExtract, ListChainAgreeForm *currentList) {
    CellOfChainAgreeForm *newCell = malloc(sizeof(CellOfChainAgreeForm));
    newCell->next = NULL;

    strcpy(newCell->category, extractTypeFromChar(indexLineToExtract));
    strcpy(newCell->word, extractAgreeFormeFromLine(indexLineToExtract));
    strcpy(newCell->def, extractInformationFromLine(indexLineToExtract));
    currentList->tail = newCell;
}
