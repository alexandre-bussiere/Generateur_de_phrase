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



char *find_rand_word_base_form (Tree dictionaryInTree, char *informationWord, Node **lastNode); //GOOD
int Nb_of_node_in_ht_list (Node* list); //GOOD

bool isWantsAgreeFormExisting(ListChainAgreeForm list, char gender[3], char number[2]); //GOOD
CellOfChainAgreeForm *giveWantedAgreeFormAdj(AllAgreeForm *agreeForm, char gender[3], char number[2]); //GOOD

CellOfChainAgreeForm *giveWantedAgreeFormVer(AllAgreeForm *agreeForm, char number[2]); //GOOD

CellOfChainAgreeForm *giveRandomAgreeForm(AllAgreeForm *agreeForm); //GOOD

char *giveGenderAndNumberOfAName(AllAgreeForm *agreeForm, char **gender, char **number);

char *conjugateAWord(Node *lastNodeOfTheWord, char gender[3], char number[2]);

void create_random_phrase (Tree dictionaryInTree);

#endif //GENERATEUR_DE_PHRASE_CREATE_RANDOM_SENTENCES_H
