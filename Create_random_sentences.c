//
// Created by bussi on 14/11/2022.
//

#include "Create_random_sentences.h"

int Nb_of_node_in_ht_list_into_ht(CelloflistChainSon *cell) {
    if (cell->next == NULL) {
        return 1;
    }
    return 1 + Nb_of_node_in_ht_list_into_ht(cell->next);
}


int Nb_of_node_in_ht_list(Node *cell) {/*
    CelloflistChainSon *tmpcell;
    int i = 0;
    tmpcell = cell->list.head;
    while (cell->list.tail != tmpcell->next || tmpcell == NULL) {
        i++;
        if (tmpcell->next == NULL) {
            return i;
        } else {
            tmpcell = tmpcell->next;
        }
    }*/
    return Nb_of_node_in_ht_list_into_ht(cell->list.head);
}


char *find_rand_word(Tree dictionaryInTree, char *informationWord) {
    char *resultat = (char *) malloc(50 * sizeof(char));
    int i = 0;
    srand(time(NULL));
    if (strcmp(informationWord, "Adv") == 0) {
        Node *tmp = dictionaryInTree.adv;
        CelloflistChainSon *temp2 = tmp->list.head;
        while (tmp->list.head != NULL) {
            for (int shits = 1; shits <= rand() % Nb_of_node_in_ht_list(tmp); shits++) {
                temp2 = temp2->next;
            }
            resultat[i] = tmp->value;
            tmp = temp2->value;
            temp2 = temp2->value->list.head;
            i++;
        }
        return resultat;
    }
    if (strcmp(informationWord, "Adj") == 0) {
        Node *tmp = dictionaryInTree.adj;
        CelloflistChainSon *temp2 = tmp->list.head;
        while (tmp->list.head != NULL) {
            int Nb_of_node = Nb_of_node_in_ht_list(tmp);
            for (int shits = 1; shits < Nb_of_node; shits++) {
                temp2 = temp2->next;
            }
            resultat[i] = temp2->value->value; // JAD LJMSDFGfdlxc:v
            tmp = tmp->list.head->value;
            temp2 = temp2->value->list.head;
            i++;
        }
        resultat[i] = '\0';
        return resultat;
    }
    if (strcmp(informationWord, "Ver") == 0) {
        Node *tmp = dictionaryInTree.ver;
        CelloflistChainSon *temp2 = tmp->list.head;
        while (tmp->list.head != NULL) {
            for (int shits = 1; shits <= rand() % Nb_of_node_in_ht_list(tmp); shits++) {
                temp2 = temp2->next;
            }
            tmp = temp2->value;
            temp2 = temp2->value->list.head;
        }
        return temp2->value->agreeForm->listAgreeForm.head->word;
    }
    if (strcmp(informationWord, "Nom") == 0) {
        Node *tmp = dictionaryInTree.nom;
        CelloflistChainSon *temp2 = tmp->list.head;
        while (tmp->list.head != NULL) {
            for (int shits = 1; shits <= rand() % Nb_of_node_in_ht_list(tmp); shits++) {
                temp2 = temp2->next;
            }
            tmp = temp2->value;
            temp2 = temp2->value->list.head;
        }
        i++;
    }
    return resultat;
}