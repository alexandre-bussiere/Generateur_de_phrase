#ifndef GENERATEUR_DE_PHRASE_STRUCT_H
#define GENERATEUR_DE_PHRASE_STRUCT_H

typedef struct cellOfChainAgreeForm {
    char category[3];
    char word[25];
    char def[14];
    struct cellOfChainAgreeForm *next;
} CellOfChainAgreeForm;

typedef struct {
    CellOfChainAgreeForm *head;
    CellOfChainAgreeForm *tail;
} ListChainAgreeForm;

typedef struct allAgreeForm {
    int nbAgreeForm;
    ListChainAgreeForm listAgreeForm;
} AllAgreeForm;

typedef struct celloflistChainSon {
    struct node *value;
    struct celloflistChainSon *next;
} CelloflistChainSon;

typedef struct listChainSon {
    CelloflistChainSon *head;
    CelloflistChainSon *tail;
} ListChainSon;

typedef struct node {
    char value;
    ListChainSon list;
    AllAgreeForm *agreeForm;
} Node;


typedef struct tree {
    Node *ver;
    Node *nom;
    Node *adv;
    Node *adj;
} Tree;

#endif //GENERATEUR_DE_PHRASE_STRUCT_H
