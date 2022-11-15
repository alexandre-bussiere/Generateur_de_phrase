//
// Created by bussi on 14/11/2022.
//

#ifndef GENERATEUR_DE_PHRASE_CREATE_RANDOM_SENTENCES_H
#define GENERATEUR_DE_PHRASE_CREATE_RANDOM_SENTENCES_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "struct.h"
#include "take-from-txt.h"
#include "functionOfListAgreeForm.h"
#include "functionOfListOfSon.h"



char* find_rand_word (Tree dictionaryInTree, char *informationWord);
int Nb_of_node_in_ht_list (Node* list);
//random phrase
//
#endif //GENERATEUR_DE_PHRASE_CREATE_RANDOM_SENTENCES_H
