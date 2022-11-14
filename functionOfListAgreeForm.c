#include "functionOfListAgreeForm.h"

void addAgreeForm(int indexLineToExtract, ListChainAgreeForm *currentList) {
    CellOfChainAgreeForm *newCell = malloc(sizeof(CellOfChainAgreeForm));
    newCell->next = NULL;
    stpcpy(newCell->category, extractTypeFromChar(indexLineToExtract));
    stpcpy(newCell->word, extractAgreeFormeFromLine(indexLineToExtract));
    stpcpy(newCell->def, extractInformationFromLine(indexLineToExtract));
    currentList->tail = newCell;
}
