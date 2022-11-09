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
Node *createNode(char value) {
    Node *newNode = malloc(sizeof(Node));

    newNode->value = value;
    (newNode->list).tail = NULL;
    (newNode->list).head = NULL;
    newNode->agreeForm = NULL;

    return newNode;
}

//GOOD
//return un tree initialiser
Tree initTree() {
    Tree tree;

    tree.adj = NULL;
    tree.adv = NULL;
    tree.ver = NULL;
    tree.nom = NULL;

    return tree;
}


//normaly good
// return true s'il a déjà un fils avec la lettre demander, false sinon
bool isSonExisting(Node *currentNode, char letterToSearch) {
    if (currentNode != NULL) {
        ListChainSon allSon = currentNode->list;
        CelloflistChainSon *temporary = allSon.head;
        while (temporary != allSon.tail) {
            if ((temporary->value)->value == letterToSearch) {
                return true;
            }
            temporary = temporary->next;
        }
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
    createSonWithGivenLetter(currentNode, letterToSearch);
    CelloflistChainSon *temporary = (currentNode->list).head;
    while (((temporary->value)->value != letterToSearch) && (temporary->next != NULL)) {
        temporary = temporary->next;
    }
    return temporary->value;
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
    }
    AllAgreeForm *agreeFormOfCurrentWord = nextNode->agreeForm;
    agreeFormOfCurrentWord->nbAgreeForm++;
    addAgreeForm("stabilisaient\tstabiliser\tVer:IImp+PL+P3", &(agreeFormOfCurrentWord->listAgreeForm));
    return;
}


