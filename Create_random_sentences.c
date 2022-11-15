//
// Created by bussi on 14/11/2022.
//
/*
#include "Create_random_sentences.h"
int Nb_of_node_in_ht_list (Node cell){

    CelloflistChainSon tmpcell;
    int i =0;
    tmpcell = cell.list.head;
    while(cell.list.tail != tmpcell.next){
        i++;
        tmpcell = tmpcell.next;
    }
    i++;
    return i;
}


char* find_rand_word (Tree dictionaryInTree, char *informationWord){
    char* resultat[50] ;
    int i =0;
    if(strcmp(informationWord, "Adv") == 0){
        CelloflistChainSon * tmp = dictionaryInTree.adv->list.head;
        while(tmp->value != 'NULL'){
            for(rand(0 a Nb_of_nod_in_ht_list(tmp))){
                tmp = tmp->next;
            }//randome entre la 0 et le nombre de node presente dans la liste et tu vas la ou le rand te dit et tu met sa dans res
            resultat[i]=tmp->value;
            i++;
            tmp = tmp->value->list.head;
        }
       return *resultat;
    }
    if(strcmp(informationWord, "Adj") == 0){

    }
    if(strcmp(informationWord, "Ver") == 0){

    }
    if(strcmp(informationWord, "Nom") == 0){

    }
}*/