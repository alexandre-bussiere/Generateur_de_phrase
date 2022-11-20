#include <stdio.h>
#include "tree.h"
#include "struct.h"
#include "Create_random_sentences.h"

#define x 'a'

int main() {
    srand(time(NULL));

    Tree dictionary;

    printf("Creation du dictionnaire...\n");
    dictionary = createDictionaryInTree();

    printf("Dictionnaire creer.\n");
    printf("Pour generer une phrase aleatoire, appuyer sur entree.\n");

    char userChoice;
    scanf("%c", &userChoice);
    printf("\t");
    create_random_phrase(dictionary);
    printf("\n\n");
    printf("Pour generer d'autre phrase, appuyer sur entree.\n");
    printf("Pour fermer le programme, entrer q.\n");

    scanf("%c", &userChoice);
    do {
        printf("\t");
        create_random_phrase(dictionary);
        printf("\n");
        scanf("%c", &userChoice);
    } while (userChoice!='q');

    return 0;
}
