#include "tree.h"

//GOOD
char *extractTypeFromChar(char *line) {
    char *type = malloc(3 * sizeof(char));
    char *information = extractInformationFromLine(line);
    for (int i = 0; i < 3; i++) {
        type[i] = information[i];
    }
    return type;
}

//GOOD
//return un tree initialiser
Tree initTree() {
    Tree tree;

    tree.adj = createNode('0');
    tree.adv = createNode('0');
    tree.ver = createNode('0');
    tree.nom = createNode('0');

    return tree;
}


//GOOD
// return true s'il a déjà un fils avec la lettre demander, false sinon
bool isSonExisting(Node *currentNode, char letterToSearch) {
    if (currentNode != NULL) {
        ListChainSon allSon = currentNode->list;
        CelloflistChainSon *temporary = allSon.head;
        while (temporary != NULL) {
            if ((temporary->value)->value == letterToSearch) {
                return true;
            }
            temporary = temporary->next;
        }
    }
    return false;
}


//GOOD
void createSonWithGivenLetter(Node *currentNode, char valueOfNewSon) {
    if (!isSonExisting(currentNode, valueOfNewSon)) {
        if (currentNode != NULL) {
            addCellToListOfSon(&(currentNode->list), valueOfNewSon);
        } else {
            currentNode = (Node *) malloc(sizeof(Node));
            currentNode->value = valueOfNewSon;
            currentNode->list.head = NULL;
            currentNode->list.tail = NULL;

            currentNode->agreeForm = NULL;
        }
    }
    return;
}


//GOOD
//return le node avec la lettre demander
Node *giveNodeWithTheGivenLetter(Node *currentNode, char letterToSearch) {
    createSonWithGivenLetter(currentNode, letterToSearch);
    CelloflistChainSon *temporary = (currentNode->list).head;
    while (((temporary->value)->value != letterToSearch) && (temporary->next != NULL)) {
        temporary = temporary->next;
    }
    return temporary->value;
}


// return true s'il a déjà un la forme fléchis, false sinon
bool isAgreeExisting(ListChainAgreeForm *currentListOfAgreeForm, char *line) {
    char *informationAgreeForm = extractInformationFromLine(line);
    CellOfChainAgreeForm *temporary = currentListOfAgreeForm->head;
    if (temporary != NULL) {
        while (temporary != NULL) {
            if (strcmp(temporary->def, informationAgreeForm) == 0) {
                return true;
            }
            temporary = temporary->next;
        }
    }
    return false;
}


void createAgreeForm(ListChainAgreeForm *currentListOfAgreeForm, char *line) {
    if (!isAgreeExisting(currentListOfAgreeForm, line)) {
        if (currentListOfAgreeForm->head != NULL) {
            addAgreeForm(line, currentListOfAgreeForm);
        } else {
            CellOfChainAgreeForm *newAgreeForm;
            newAgreeForm = (CellOfChainAgreeForm *) malloc(sizeof(CellOfChainAgreeForm));

            stpcpy(newAgreeForm->category, extractTypeFromChar(line));
            stpcpy(newAgreeForm->word, extractAgreeFormeFromLine(line));
            stpcpy(newAgreeForm->def, extractInformationFromLine(line));
            newAgreeForm->next = NULL;

            currentListOfAgreeForm->head = currentListOfAgreeForm->tail = newAgreeForm;
        }
    }
    return;
}


AllAgreeForm *initAllAgreeForm(){
    AllAgreeForm *newAgreeForm;
    newAgreeForm = (AllAgreeForm *) malloc(sizeof(AllAgreeForm));
    newAgreeForm->nbAgreeForm = 0;
    newAgreeForm->listAgreeForm.head = NULL;
    newAgreeForm->listAgreeForm.tail = NULL;

    return newAgreeForm;
}


void placeWordInTree(Tree dictionaryInTree, int line) {
    char *newWord = extractBaseFormeFromLine("stabilisaient\tstabiliser\tVer:IImp+PL+P3");
    char *informationWord = extractTypeFromChar("stabilisaient\tstabiliser\tVer:IImp+PL+P3");

    int lengthWord = strlen(newWord);
    Node *currentNode, *nextNode = NULL;

    if (strcmp(informationWord, "Adv") == 0) {
        currentNode = dictionaryInTree.adv;
    } else if (strcmp(informationWord, "Adj") == 0) {
        currentNode = dictionaryInTree.adj;
    } else if (strcmp(informationWord, "Ver") == 0) {
        currentNode = dictionaryInTree.ver;
    } else if (strcmp(informationWord, "Nom") == 0) {
        currentNode = dictionaryInTree.nom;
    }

    for (int i = 0; i < lengthWord; i++) {
        nextNode = giveNodeWithTheGivenLetter(currentNode, newWord[i]);
        currentNode = ((currentNode->list).head)->value;
    }

    AllAgreeForm *agreeFormOfCurrentWord = nextNode->agreeForm;
    if (agreeFormOfCurrentWord == NULL) {
        agreeFormOfCurrentWord = initAllAgreeForm();
    }
    createAgreeForm(&(agreeFormOfCurrentWord->listAgreeForm), "stabilisaient\tstabiliser\tVer:IImp+PL+P3");
    agreeFormOfCurrentWord->nbAgreeForm++;
    return;
}


