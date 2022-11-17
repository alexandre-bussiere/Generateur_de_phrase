#include <stdio.h>
#include "tree.h"
#include "struct.h"
#include "Create_random_sentences.h"

#define x 'a'

int main() {
    Tree dictionary;

  //  placeWordInTree(dictionary, 7);


    dictionary = createDictionaryInTree();

    create_random_phrase(dictionary);

    return 0;
}
