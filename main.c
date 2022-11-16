#include <stdio.h>
#include "tree.h"
#include "struct.h"

#define x 'a'

int main() {
    Tree dictionary;

  //  placeWordInTree(dictionary, 7);


    dictionary = createDictionaryInTree();

    if(isSonExisting(dictionary.nom, x)){
        printf("oui\n");
    } else{
        printf("non\n");
    }

    return 0;
}
