#pragma once
#include <stdbool.h>

// tree node structure
typedef struct Node Node;

// creates tree
Node* createTree();

// deletes whole tree
void deleteTree(Node** root);

// reads data from file and fills the tree with input expression
bool parse(Node** root, FILE* file);

// evaluates input expression
int eval(Node* root);

// prints expression in prefix notation using preorder tree traversal
void printPreorder(Node* root);

// checks if root is empty
bool isEmpty(Node* root);