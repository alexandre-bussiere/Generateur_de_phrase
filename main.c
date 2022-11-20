#include <stdio.h>
#include "tree.h"
#include "struct.h"
#include "Create_random_sentences.h"

#define x 'a'

int main() {
    srand(time(NULL));

    Tree dictionary;

    printf("Création du dictionnaire...\n");
    dictionary = createDictionaryInTree();

    printf("Dictionnaire créer.\n");
    printf("Pour générer une phrase aléatoire, appuyer sur entrée.\n");

    char userChoice;
    scanf("%c", &userChoice);
    printf("\t");
    create_random_phrase(dictionary);
    printf("\n\n");
    printf("Pour générer d'autre phrase, appuyer sur entrée.\n");
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
