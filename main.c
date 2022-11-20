#include <stdio.h>
#include "tree.h"
#include "struct.h"
#include "Create_random_sentences.h"

#define x 'a'

int main() {
    srand(time(NULL));

    Tree dictionary;

    dictionary = createDictionaryInTree();

    char userChoice;
    do {
        create_random_phrase(dictionary);
        printf("\n");
        scanf("%c", &userChoice);
    } while (userChoice!='q');

    return 0;
}
