#include <stdio.h>
#include "tree.h"
#include "struct.h"

int main() {
    Tree dictionary=initTree();
    //placeWordInTree(dictionary, 0);

    createSonWithGivenLetter(dictionary.nom, 'a');

    if(isSonExisting(dictionary.nom, 'a')){
        printf("oui");
    } else{
        printf("non");
    }
    return 0;
}
