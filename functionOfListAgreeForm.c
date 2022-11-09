#include "functionOfListAgreeForm.h"

void addAgreeForm(char *line, ListChainAgreeForm *currentList) {
    CellOfChainAgreeForm *newCell = malloc(sizeof(CellOfChainAgreeForm));
    newCell->next = NULL;
    stpcpy(newCell->category, extractTypeFromChar("stabilisaient\tstabiliser\tVer:IImp+PL+P3"));
    stpcpy(newCell->word, extractAgreeFormeFromLine("stabilisaient\tstabiliser\tVer:IImp+PL+P3"));
    stpcpy(newCell->def, extractInformationFromLine("stabilisaient\tstabiliser\tVer:IImp+PL+P3"));
    currentList->tail = newCell;
}
