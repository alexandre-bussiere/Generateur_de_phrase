#include "tree.h"

//GOOD
char *extractTypeFromChar(int indexLineToExtract) {
    char *type = (char *)malloc(3 * sizeof(char));
    char *information = extractInformationFromLine(indexLineToExtract);
    for (int i = 0; i < 3; i++) {
        type[i] = information[i];
    }
    free(information);
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
bool isAgreeExisting(ListChainAgreeForm *currentListOfAgreeForm, int indexLineToExtract) {
    char *informationAgreeForm = extractInformationFromLine(indexLineToExtract);
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


void createAgreeForm(ListChainAgreeForm *currentListOfAgreeForm, int indexLineToExtract) {
    if (!isAgreeExisting(currentListOfAgreeForm, indexLineToExtract)) {
        if (currentListOfAgreeForm->head != NULL) {
            addAgreeForm(indexLineToExtract, currentListOfAgreeForm);
        } else {
            CellOfChainAgreeForm *newAgreeForm;
            newAgreeForm = (CellOfChainAgreeForm *) malloc(sizeof(CellOfChainAgreeForm));

            stpcpy(newAgreeForm->category, extractTypeFromChar(indexLineToExtract));
            stpcpy(newAgreeForm->word, extractAgreeFormeFromLine(indexLineToExtract));
            stpcpy(newAgreeForm->def, extractInformationFromLine(indexLineToExtract));
            newAgreeForm->next = NULL;

            currentListOfAgreeForm->head = currentListOfAgreeForm->tail = newAgreeForm;
        }
    }
    return;
}


AllAgreeForm *initAllAgreeForm() {
    AllAgreeForm *newAgreeForm;
    newAgreeForm = (AllAgreeForm *) malloc(sizeof(AllAgreeForm));
    newAgreeForm->nbAgreeForm = 0;
    newAgreeForm->listAgreeForm.head = NULL;
    newAgreeForm->listAgreeForm.tail = NULL;

    return newAgreeForm;
}


void placeWordInTree(Tree dictionaryInTree, int indexLineToExtract) {
    char *newWord = extractBaseFormeFromLine(indexLineToExtract);
    char *informationWord = extractTypeFromChar(indexLineToExtract);
    informationWord[3]='\0';
    int lengthWord = (int) strlen(newWord);
    Node *currentNode, *nextNode = NULL;

    if (strcmp(informationWord, "Adv") == 0) {
        currentNode = dictionaryInTree.adv;
    } else if (strcmp(informationWord, "Adj") == 0) {
        currentNode = dictionaryInTree.adj;
    } else if (strcmp(informationWord, "Ver") == 0) {
        currentNode = dictionaryInTree.ver;
    } else if (strcmp(informationWord, "Nom") == 0) {
        currentNode = dictionaryInTree.nom;
    } else{
        return;
    }


    for (int i = 0; i < lengthWord; i++) {
        nextNode = giveNodeWithTheGivenLetter(currentNode, newWord[i]);
        currentNode = ((currentNode->list).head)->value;
    }

    AllAgreeForm *agreeFormOfCurrentWord = nextNode->agreeForm;
    if (agreeFormOfCurrentWord == NULL) {
        agreeFormOfCurrentWord = initAllAgreeForm();
    }
    createAgreeForm(&(agreeFormOfCurrentWord->listAgreeForm), indexLineToExtract);
    agreeFormOfCurrentWord->nbAgreeForm++;
    free(newWord);
    free(informationWord);
    return;
}


int createDictionaryInTree(){
    Tree dictionary = initTree();

    for (int i = 1; i <=35; i++) {
        placeWordInTree(dictionary, i);
    }

    return 1;
}