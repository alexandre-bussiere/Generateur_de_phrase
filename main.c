#include <stdio.h>
#include "tree.h"
#include "struct.h"

int main() {
    Tree dictionary=initTree();
    //placeWordInTree(dictionary, 0);

    createSonWithGivenLetter(dictionary.nom, 'a');
    createSonWithGivenLetter(dictionary.nom->list.head->value, 'b');
    createSonWithGivenLetter(dictionary.nom, 'c');

    if(isSonExisting(dictionary.nom, 'b')){
        printf("oui");
    } else{
        printf("non");
    }
    return 0;
}
