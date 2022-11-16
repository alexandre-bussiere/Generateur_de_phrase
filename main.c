#include <stdio.h>
#include "tree.h"
#include "struct.h"
#include "Create_random_sentences.h"

#define x 'a'

int main() {
    Tree dictionary;

  //  placeWordInTree(dictionary, 7);


    dictionary = createDictionaryInTree();

    char * word = find_rand_word(dictionary, "Adj");
    printf("\n%s",word);
    return 0;
}
