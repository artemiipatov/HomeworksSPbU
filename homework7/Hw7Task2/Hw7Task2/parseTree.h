#pragma once
#include <stdbool.h>

// tree node structure
typedef struct Node Node;

// deletes whole tree
void deleteTree(Node** root);

// creates tree, reads data from file with given name and fills the tree with input expression
Node* parse(const char* fileName);

// evaluates input expression
int eval(Node* root);

// prints expression in prefix notation using preorder tree traversal
void printPreorder(Node* root);

// checks if root is empty
bool isEmpty(Node* root);