#include "functionOfListAgreeForm.h"

void addAgreeForm(char *line, ListChainAgreeForm *currentList) {
    CellOfChainAgreeForm *newCell = malloc(sizeof(CellOfChainAgreeForm));
    newCell->next = NULL;
    stpcpy(newCell->category, extractTypeFromChar(line));
    stpcpy(newCell->word, extractAgreeFormeFromLine(line));
    stpcpy(newCell->def, extractInformationFromLine(line));
    currentList->tail = newCell;
}
