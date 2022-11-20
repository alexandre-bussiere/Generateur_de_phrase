//
// Created by bussi on 14/11/2022.
//

#include "Create_random_sentences.h"

bool compareTwoChar(char list[3], char *pointer) {
    if ((list[0] == pointer[0]) && (list[1] == pointer[1])) {
        return true;
    }
    return false;
}

int Nb_of_node_in_ht_list_into_ht(CelloflistChainSon *cell) {
    if (cell->next == NULL) {
        return 1;
    }
    return 1 + Nb_of_node_in_ht_list_into_ht(cell->next);
}


int Nb_of_node_in_ht_list(Node *cell) {
    return Nb_of_node_in_ht_list_into_ht(cell->list.head);
}


char *find_rand_word_base_form(Tree dictionaryInTree, char *informationWord, Node **lastNode) {
    char *result = (char *) malloc(30 * sizeof(char));
    int i = 0;
    Node *tmp = NULL;

    if (strcmp(informationWord, "Adv") == 0) {
        tmp = dictionaryInTree.adv;
    } else if (strcmp(informationWord, "Adj") == 0) {
        tmp = dictionaryInTree.adj;
    } else if (strcmp(informationWord, "Ver") == 0) {
        tmp = dictionaryInTree.ver;
    } else if (strcmp(informationWord, "Nom") == 0) {
        tmp = dictionaryInTree.nom;
    }

    CelloflistChainSon *temp2 = tmp->list.head;
    while (tmp->list.head != NULL) {
        int Nb_of_node = rand() % Nb_of_node_in_ht_list(tmp);
        for (int j = 0; j < Nb_of_node; j++) {
            temp2 = temp2->next;
        }
        result[i] = temp2->value->value;
        tmp = temp2->value;
        temp2 = temp2->value->list.head;
        i++;
    }
    result[i] = '\0';
    if ((lastNode != NULL) && (*lastNode != NULL)) {
        *lastNode = tmp;
    }
    return result;
}


bool isWantsAgreeFormExisting(ListChainAgreeForm list, char gender[3], char number[2]) {
    CellOfChainAgreeForm *temporary = list.head;
    char *temp = (char *) malloc(15 * sizeof(char));
    char *gen, *nb;
    while (temporary != NULL) {
        strcpy(temp, temporary->def);
        strtok(temp, ":");
        gen = strtok(NULL, "+");
        nb = strtok(NULL, "+");
        for (int i = 0; i < strlen(nb); i++) {
            if (nb[i] == ':') {
                nb[i] = '\0';
            }
        }
        //printf("%s, %s\n", gen, nb);
        if ((strcmp(gen, gender) == 0) && (strcmp(nb, number) == 0)) {
            return true;
        }
        if ((strcmp(gen, gender) == 0) && (strcmp(nb, "InvPL") == 0)) {
            return true;
        }
        if ((strcmp(gen, "InvGen") == 0) && (strcmp(nb, number) == 0)) {
            return true;
        }
        if ((strcmp(gen, "InvGen") == 0) && (strcmp(nb, "InvPL") == 0)) {
            return true;
        }
        temporary = temporary->next;
    }
    return false;
}


CellOfChainAgreeForm *giveRandomAgreeForm(AllAgreeForm *agreeForm) {
    CellOfChainAgreeForm *temporary = agreeForm->listAgreeForm.head;
    for (int i = 0; i < rand() % agreeForm->nbAgreeForm; i++) {
        temporary = temporary->next;
    }
    return temporary;
}


CellOfChainAgreeForm *giveWantedAgreeFormAdj(AllAgreeForm *agreeForm, char gender[3], char number[2]) {
    ListChainAgreeForm list = agreeForm->listAgreeForm;
    if (isWantsAgreeFormExisting(list, gender, number)) {
        char *temp = (char *) malloc(15 * sizeof(char));
        CellOfChainAgreeForm *correctCell = NULL;
        CellOfChainAgreeForm *temporary = list.head;
        char *gen, *nb;
        while (temporary != NULL) {
            strcpy(temp, temporary->def);
            strtok(temp, ":");
            gen = strtok(NULL, "+");
            nb = strtok(NULL, "+");
            for (int i = 0; i < strlen(nb); i++) {
                if (nb[i] == ':') {
                    nb[i] = '\0';
                }
            }
            correctCell = temporary;

            if ((strcmp(gen, gender) == 0) && (strcmp(nb, number) == 0)) {
                return correctCell;
            }
            if ((strcmp(gen, gender) == 0) && (strcmp(nb, "InvPL") == 0)) {
                return correctCell;
            }
            if ((strcmp(gen, "InvGen") == 0) && (strcmp(nb, number) == 0)) {
                return correctCell;
            }
            if ((strcmp(gen, "InvGen") == 0) && (strcmp(nb, "InvPL") == 0)) {
                return correctCell;
            }
            temporary = temporary->next;
        }
    }
    return giveRandomAgreeForm(agreeForm);
}

CellOfChainAgreeForm *giveWantedAgreeFormVer(AllAgreeForm *agreeForm, char number[2]) {
    ListChainAgreeForm list = agreeForm->listAgreeForm;
    CellOfChainAgreeForm *correctCell = NULL, *lastCorrectCell = NULL;
    CellOfChainAgreeForm *temporary = list.head;
    char *temp = (char *) malloc(15 * sizeof(char));
    char *nb, *pr;
    while (temporary != NULL) {
        strcpy(temp, temporary->def);
        strtok(temp, ":");
        strtok(NULL, "+");
        nb = strtok(NULL, "+");
        pr = strtok(NULL, "+");
        if (pr != NULL) {
            for (int i = 0; i < strlen(pr); i++) {
                if (pr[i] == ':') {
                    pr[i] = '\0';
                }
            }
            correctCell = temporary;

            if ((strcmp(pr, "P3") == 0) && (strcmp(nb, number) == 0)) {
                lastCorrectCell = correctCell;
                if (rand() % 3 == 0) {
                    return correctCell;
                }
            }
        }
        temporary = temporary->next;
    }
    if (lastCorrectCell != NULL) {
        return lastCorrectCell;
    }
    return giveRandomAgreeForm(agreeForm);
}

char *conjugateAWord(Node *lastNodeOfTheWord, char gender[3], char number[2]) {
    CellOfChainAgreeForm *allAgreeForm = lastNodeOfTheWord->agreeForm->listAgreeForm.head;

    if (compareTwoChar(allAgreeForm->category, "Adv")) {
        return allAgreeForm->word;
    }

    if (compareTwoChar(allAgreeForm->category, "Adj")) {
        CellOfChainAgreeForm *wantedAgreeForm;
        wantedAgreeForm = giveWantedAgreeFormAdj(lastNodeOfTheWord->agreeForm, gender, number);
        return wantedAgreeForm->word;
    }

    if (compareTwoChar(allAgreeForm->category, "Ver")) {
        CellOfChainAgreeForm *wantedAgreeForm;
        wantedAgreeForm = giveWantedAgreeFormVer(lastNodeOfTheWord->agreeForm, number);
        return wantedAgreeForm->word;
    }

}


char *giveGenderAndNumberOfAName(AllAgreeForm *agreeForm, char *gender[3], char *number[2]) {
    CellOfChainAgreeForm *wantedAgreeForm;
    wantedAgreeForm = giveRandomAgreeForm(agreeForm);
    if ((gender != NULL) && (number != NULL)) {
        char *temp = (char *) malloc(15 * sizeof(char));
        strcpy(temp, wantedAgreeForm->def);
        strtok(temp, ":");
        *gender = strtok(NULL, "+");
        *number = strtok(NULL, "+");
    }
    return wantedAgreeForm->word;
}


void create_random_phrase(Tree dictionaryInTree) {
    int choice = rand() % 3;
    if (choice == 0) {
        Node *nom1, *adj, *ver, *nom2;
        nom1 = createNode('0');
        adj = createNode('0');
        ver = createNode('0');
        nom2 = createNode('0');

        find_rand_word_base_form(dictionaryInTree, "Nom", &nom1);
        find_rand_word_base_form(dictionaryInTree, "Ver", &ver);
        find_rand_word_base_form(dictionaryInTree, "Adj", &adj);
        find_rand_word_base_form(dictionaryInTree, "Nom", &nom2);

        char *nom1Final, *adjFinal, *verFinal, *nom2Final;
        char *gender, *number;
        gender = (char *) malloc(6 * sizeof(char));
        number = (char *) malloc(6 * sizeof(char));

        nom1Final = giveGenderAndNumberOfAName(nom1->agreeForm, &gender, &number);
        nom2Final = giveGenderAndNumberOfAName(nom1->agreeForm, NULL, NULL);

        if (compareTwoChar(gender, "InvGen")) {
            int i = rand() % 2;
            if (i == 0) {
                strcpy(gender, "Fem");
            } else {
                strcpy(gender, "Mas");
            }
        }

        if (compareTwoChar(number, "InvPL")) {
            int i = rand() % 2;
            if (i == 0) {
                strcpy(number, "SG");
            } else {
                strcpy(number, "PL");
            }
        }

        adjFinal = conjugateAWord(adj, gender, number);
        verFinal = conjugateAWord(ver, gender, number);

        printf("%s %s %s %s.", nom1Final, adjFinal, verFinal, nom2Final);/*
    }
    if (choice == 1) {
        printf("%s qui %s %s %s %s.\n", find_rand_word_base_form(dictionaryInTree, "Nom", NULL),
               find_rand_word_base_form(dictionaryInTree, "Ver", NULL),
               find_rand_word_base_form(dictionaryInTree, "Ver", NULL),
               find_rand_word_base_form(dictionaryInTree, "Nom", NULL),
               find_rand_word_base_form(dictionaryInTree, "Adj", NULL));
    }
    if (choice == 2) {
        printf("Elle %s, quand son groupe %s %s %s.", find_rand_word_base_form(dictionaryInTree, "Ver", NULL),
               find_rand_word_base_form(dictionaryInTree, "Ver", NULL),
               find_rand_word_base_form(dictionaryInTree, "Adj", NULL),
               find_rand_word_base_form(dictionaryInTree, "Nom", NULL));
    }
*/

}