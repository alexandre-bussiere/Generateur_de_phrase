#include <stdio.h>
#include "tree.h"
#include "struct.h"

#define x 't'

int main() {
    Tree dictionary=initTree();
    placeWordInTree(dictionary, 0);
/*
    createSonWithGivenLetter(dictionary.nom, 'a');
    createSonWithGivenLetter(dictionary.nom, 'E');
    createSonWithGivenLetter(dictionary.nom, 'c');

    printf("%c\n", (giveNodeWithTheGivenLetter(dictionary.nom, x)->value));
*/
    if(isSonExisting(dictionary.ver, x)){
        printf("oui\n");
    } else{
        printf("non\n");
    }

    return 0;
}
