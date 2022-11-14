#include <stdio.h>
#include "tree.h"
#include "struct.h"

#define x 't'

int main() {
    Tree dictionary=initTree();
    char *test = takeLineFromTxt(7, 1);
    printf("%s", test);/*
    placeWordInTree(dictionary, 7);

    //createDictionaryInTree();

    if(isSonExisting(dictionary.ver, x)){
        printf("oui\n");
    } else{
        printf("non\n");
    }
*/
    return 0;
}
