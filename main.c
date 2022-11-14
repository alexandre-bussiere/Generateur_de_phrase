#include <stdio.h>
#include "tree.h"
#include "struct.h"

#define x 't'

int main() {
    Tree dictionary=initTree();
    //placeWordInTree(dictionary, 0);

    createDictionaryInTree();

    if(isSonExisting(dictionary.ver, x)){
        printf("oui\n");
    } else{
        printf("non\n");
    }

    return 0;
}
