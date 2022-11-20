#include <stdio.h>
#include "tree.h"
#include "struct.h"
#include "Create_random_sentences.h"

#define x 'a'

int main() {
    srand(time(NULL));

    Tree dictionary;

    dictionary = createDictionaryInTree();
    Node *test = (Node *) malloc(sizeof(Node));
    test->value = '0';
    test->list.head = NULL;
    test->list.tail = NULL;
    test->agreeForm = NULL;

    printf("%s\n", find_rand_word_base_form(dictionary, "Ver", &test));

    printf("%s", conjugateAWord(test, "Fem", "PL"));
/*
    char userChoice;
    do {
        create_random_phrase(dictionary);
        printf("\n");
        scanf("%c", &userChoice);
    } while (userChoice!='q');*/

    return 0;
}
