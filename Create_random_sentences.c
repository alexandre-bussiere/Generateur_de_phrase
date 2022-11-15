//
// Created by bussi on 14/11/2022.
//

#include "Create_random_sentences.h"

int Nb_of_node_in_ht_list(Node *cell) {

    CelloflistChainSon *tmpcell;
    int i = 0;
    tmpcell = cell->list.head;
    while (cell->list.tail != tmpcell->next) {
        i++;
        tmpcell = tmpcell->next;
    }
    i++;
    return i;
}


char *find_rand_word(Tree dictionaryInTree, char *informationWord) {
    char *resultat[50];
    int i = 0;
    srand(time(NULL));
    if (strcmp(informationWord, "Adv") == 0) {
        Node *tmp = dictionaryInTree.adv;
        CelloflistChainSon *temp2 = tmp->list.head;
        while (tmp->list.head != NULL) {
            for (int shits = 0; shits < rand() % Nb_of_node_in_ht_list(tmp); shits++) {
                temp2 = temp2->next;
            }
            resultat[i] = temp2->value;
            i++;
            tmp = temp2->value;
        }
        return *resultat;
    }
    if (strcmp(informationWord, "Adj") == 0) {

    }
    if (strcmp(informationWord, "Ver") == 0) {

    }
    if (strcmp(informationWord, "Nom") == 0) {

    }
}