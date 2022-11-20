#include <stdio.h>
#include "tree.h"
#include "struct.h"
#include "Create_random_sentences.h"

#define x 'a'

int main() {
    srand(time(NULL));

    Tree dictionary;

    dictionary = createDictionaryInTree();/*
    Node *test = createNode('0');

    printf("%s\n", find_rand_word_base_form(dictionary, "Nom", &test));


    char *gen, *nb, *mot;
    gen = (char *) malloc(6 * sizeof(char));
    nb = (char *) malloc(6 * sizeof(char));
    mot = giveGenderAndNumberOfAName(test->agreeForm, &gen, &nb);

    printf("mot: %s, genre:  %s, nombre: %s\n", mot, gen, nb);
    //printf("%s", conjugateAWord(test, "Fem", "PL"));*/

    char userChoice;
    do {
        create_random_phrase(dictionary);
        printf("\n");
        scanf("%c", &userChoice);
    } while (userChoice!='q');

    return 0;
}
