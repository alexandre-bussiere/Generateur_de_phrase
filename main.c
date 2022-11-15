#include <stdio.h>
#include "tree.h"
#include "struct.h"
#include "Create_random_sentences.h"

#define x 'a'

int main() {
    Tree dictionary;

    //placeWordInTree(dictionary, 7);

    dictionary = createDictionaryInTree();

    if(isSonExisting(dictionary.adj, x)){
        printf("oui\n");
    } else{
        printf("non\n");
    }
    int word = Nb_of_node_in_ht_list(dictionary.adj);
    //char * word = find_rand_word(dictionary, "Ver");
    printf("\n%d",word);
    return 0;
}
