#ifndef GENERATEUR_DE_PHRASE_STRUCT_H
#define GENERATEUR_DE_PHRASE_STRUCT_H

typedef struct listChainAgreeForm{
    char category[3];
    char word[25];
    char def[10];
    struct listChainAgreeForm* next;
}ListChainAgreeForm;

typedef struct allAgreeForm{
    int nbAgreeForm;
    ListChainAgreeForm listAgreeForm;
}AllAgreeForm;

typedef struct listChainSon ListChainSon;

typedef struct node{
    char value;
    ListChainSon list;
    AllAgreeForm* agreeForm;
}Node;

ListChainSon {
    Node* value;
    struct listChainSon* next;
};

typedef struct tree{
    Node* ver;
    Node* nom;
    Node* adv;
    Node* adj;
}Tree;

#endif //GENERATEUR_DE_PHRASE_STRUCT_H
