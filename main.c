#include <stdio.h>
#include "tree.h"
#include "struct.h"

#define x 'a'

int main() {
    Tree dictionary=initTree();

    placeWordInTree(dictionary, 7);

    createDictionaryInTree();

    if(isSonExisting(dictionary.adj, x)){
        printf("oui\n");
    } else{
        printf("non\n");
    }

    return 0;
}
