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


int Nb_of_node_in_ht_list(Node *cell) {
    return Nb_of_node_in_ht_list_into_ht(cell->list.head);
}


char *find_rand_word(Tree dictionaryInTree, char *informationWord) {
    char *resultat = (char *) malloc(50 * sizeof(char));
    int i = 0;

    if (strcmp(informationWord, "Adv") == 0) {
        Node *tmp = dictionaryInTree.adv;
        CelloflistChainSon *temp2 = tmp->list.head;
        while (tmp->list.head != NULL) {
            int Nb_of_node = rand() % Nb_of_node_in_ht_list(tmp);
            for (int shits = 0; shits < Nb_of_node; shits++) {
                temp2 = temp2->next;
            }
            resultat[i] = temp2->value->value; // JAD LJMSDFGfdlxc:v
            tmp = temp2->value;
            temp2 = temp2->value->list.head;
            i++;
        }
        resultat[i] = '\0';
        return resultat;
    }
    if (strcmp(informationWord, "Adj") == 0) {
        Node *tmp = dictionaryInTree.adj;
        CelloflistChainSon *temp2 = tmp->list.head;
        while (tmp->list.head != NULL) {
            int Nb_of_node = rand() % Nb_of_node_in_ht_list(tmp);
            for (int shits = 0; shits < Nb_of_node; shits++) {
                temp2 = temp2->next;
            }
            resultat[i] = temp2->value->value; // JAD LJMSDFGfdlxc:v
            tmp = temp2->value;
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
            for (int shits = 0; shits < rand() % Nb_of_node_in_ht_list(tmp); shits++) {
                temp2 = temp2->next;
            }
            tmp = temp2->value;
            temp2 = temp2->value->list.head;
        }
        return tmp->agreeForm->listAgreeForm.head->word;
    }
    if (strcmp(informationWord, "Nom") == 0) {
        Node *tmp = dictionaryInTree.nom;
        CelloflistChainSon *temp2 = tmp->list.head;
        while (tmp->list.head != NULL) {
            int Nb_of_node = rand() % Nb_of_node_in_ht_list(tmp);
            for (int shits = 0; shits < Nb_of_node; shits++) {
                temp2 = temp2->next;
            }
            //resultat[i] = temp2->value->value; // JAD LJMSDFGfdlxc:v
            tmp = temp2->value;
            temp2 = temp2->value->list.head;
            //i++;
        }
        //resultat[i] = '\0';
        return tmp->agreeForm->listAgreeForm.head->word;
    }
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
    *lastNode = tmp;
    return result;
}

void create_random_phrase(Tree dictionaryInTree) {
    int choice = rand() % 3;
    if (choice == 0) {
        printf("%s %s %s %s.", find_rand_word(dictionaryInTree, "Nom"), find_rand_word(dictionaryInTree, "Adj"),
               find_rand_word(dictionaryInTree, "Ver"), find_rand_word(dictionaryInTree, "Nom"));
    }
    if (choice == 1) {
        printf("%s qui %s %s %s %s.", find_rand_word(dictionaryInTree, "Nom"), find_rand_word(dictionaryInTree, "Ver"),
               find_rand_word(dictionaryInTree, "Ver"), find_rand_word(dictionaryInTree, "Nom"),
               find_rand_word(dictionaryInTree, "Adj"));
    }
    if (choice == 2) {
        printf("Il %s, quand son groupe %s %s %s.", find_rand_word(dictionaryInTree, "Ver"),
               find_rand_word(dictionaryInTree, "Ver"), find_rand_word(dictionaryInTree, "Adj"),
               find_rand_word(dictionaryInTree, "Nom"));
    }
}