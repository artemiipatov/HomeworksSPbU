#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "AVLtree.h"

typedef enum Direction
{
    left,
    right
} Direction;

typedef struct Node
{
    struct Node* leftSon;
    struct Node* rightSon;
    struct Node* parent;
    char key[50];
    char value[50];
    int height;
} Node;

typedef struct Dict
{
    Node* root;
} Dict;

Dict* createDictionary()
{
    return calloc(1, sizeof(Dict));
}

void deleteTreeRecursive(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    deleteTreeRecursive(root->leftSon);
    deleteTreeRecursive(root->rightSon);
    free(root);
}

void deleteDictionary(Dict** dict)
{
    if (*dict == NULL)
    {
        return;
    }
    deleteTreeRecursive((*dict)->root);
    free(*dict);
    *dict = NULL;
}

void correctHeight(Node* node)
{
    if (node->leftSon == NULL && node->rightSon == NULL)
    {
        node->height = 1;
    }
    else if (node->leftSon == NULL)
    {
        node->height = node->rightSon->height + 1;
    }
    else if (node->rightSon == NULL)
    {
        node->height = node->leftSon->height + 1;
    }
    else
    {
        node->height = node->rightSon->height > node->leftSon->height ? node->rightSon->height + 1 : node->leftSon->height + 1;
    }
}

int getBalanceFactor(Node* node)
{
    if (node->leftSon == NULL && node->rightSon == NULL)
    {
        return 0;
    }
    else if (node->leftSon == NULL)
    {
        return -node->rightSon->height;
    }
    else if (node->rightSon == NULL)
    {
        return node->leftSon->height;
    }
    return node->leftSon->height - node->rightSon->height;
}

void attach(Node* parent, Node* child, Direction direction)
{
    if (direction == left)
    {
        parent->leftSon = child;
    }
    else
    {
        parent->rightSon = child;
    }
    if (child != NULL)
    {
        child->parent = parent;
    }
}

Node* rotateLeft(Node* a)
{
    Node* b = a->rightSon;
    attach(a, b->leftSon, right);
    b->parent = a->parent;
    attach(b, a, left);
    correctHeight(a);
    correctHeight(b);
    return b;
}

Node* rotateRight(Node* a)
{
    Node* b = a->leftSon; 
    attach(a, b->rightSon, left);
    b->parent = a->parent;
    attach(b, a, right);
    correctHeight(a);
    correctHeight(b);
    return b;
}

Node* bigRotateLeft(Node* a)
{
    a->rightSon = rotateRight(a->rightSon);
    return rotateLeft(a); 
}

Node* bigRotateRight(Node* a)
{
    a->leftSon = rotateLeft(a->leftSon);
    return rotateRight(a);
}

Node* balance(Node* node)
{
    if (getBalanceFactor(node) == -2)
    {
        if (getBalanceFactor(node->rightSon) <= 0)
        {
            return rotateLeft(node);
        }
        return bigRotateLeft(node);
    }
    if (getBalanceFactor(node) == 2)
    {
        if (getBalanceFactor(node->leftSon) >= 0)
        {
            return rotateRight(node);
        }
        return bigRotateRight(node);
    }
    return node;
}

Node* insertRecursive(Node* parent, Node* node, const char* key, const char* value)
{
    if (node == NULL)
    {
        Node* newNode = calloc(1, sizeof(Node));
        if (newNode == NULL)
        {
            return NULL;
        }
        strcpy_s(newNode->key, 50, key);
        strcpy_s(newNode->value, 50, value);
        newNode->height = 1;
        newNode->parent = parent;
        return newNode;
    }
    if (strcmp(key, node->key) < 0)
    {
        node->leftSon = insertRecursive(node, node->leftSon, key, value);
        correctHeight(node);
    }
    else if (strcmp(key, node->key) > 0)
    {
        node->rightSon = insertRecursive(node, node->rightSon, key, value);
        correctHeight(node);
    }
    else
    {
        strcpy_s(node->value, 50, value);
        return node;
    }
    return balance(node);
}

bool insert(Dict* dict, const char* key, const char* value)
{
    Node* returnedNode = insertRecursive(dict->root, dict->root, key, value);
    if (returnedNode == NULL)
    {
        return false;
    }
    dict->root = returnedNode;
    return true;
}

Node* search(Node* root, const char* key)
{
    Node* i = root;
    while (i != NULL)
    {
        if (strcmp(key, i->key) > 0)
        {
            i = i->rightSon;
        }
        else if (strcmp(key, i->key) < 0)
        {
            i = i->leftSon;
        }
        else
        {
            return i;
        }
    }
    return NULL;
}

Node* searchMin(Node* node)
{
    while (node->leftSon != NULL)
    {
        node = node->leftSon;
    }
    return node;
}

Node* fullBalance(Node* x, const char* key)
{
    if (x == NULL)
    {
        return NULL;
    }
    if (strcmp(key, x->key) > 0)
    {
        x->rightSon = fullBalance(x->rightSon, key);
    }
    else if (strcmp(key, x->key) < 0)
    {
        x->leftSon = fullBalance(x->leftSon, key);
    }
    correctHeight(x);
    return balance(x);
}

void deleteNode(Dict** dict, const char* key)
{
    Node* root = (*dict)->root;
    Node* x = search(root, key);
    if (x == NULL)
    {
        return;
    }
    if (x->rightSon != NULL)
    {
        Node* minimum = searchMin(x->rightSon);
        strcpy_s(x->key, 50, minimum->key);
        strcpy_s(x->value, 50, minimum->value);
        if (minimum == x->rightSon)
        {
            x->rightSon = minimum->rightSon;
        }
        else
        {
            minimum->parent->leftSon = minimum->rightSon;
        }
        if (minimum->rightSon != NULL)
        {
            minimum->rightSon->parent = minimum->parent;
        }
        (*dict)->root = fullBalance((*dict)->root, x->key);
        free(minimum);
    }
    else if (x->leftSon != NULL)
    {
        if (x->parent != NULL)
        {
            if (x == x->parent->leftSon)
            {
                x->parent->leftSon = x->leftSon;
            }
            else
            {
                x->parent->rightSon = x->leftSon;
            }
            x->leftSon->parent = x->parent;
        }
        else
        {
            x->leftSon->parent = NULL;
            root = x->leftSon;
        }
        (*dict)->root = fullBalance((*dict)->root, x->key);
        free(x);
    }
    else if (x->parent == NULL)
    {
        deleteDictionary(dict);
    }
    else
    {
        if (x == x->parent->leftSon)
        {
            x->parent->leftSon = NULL;
        }
        else
        {
            x->parent->rightSon = NULL;
        }
        (*dict)->root = fullBalance((*dict)->root, x->key);
        free(x);
    }
}

const char* getValue(Dict* dict, const char* key)
{
    if (dict == NULL)
    {
        return NULL;
    }
    Node* wantedNode = search(dict->root, key);
    return wantedNode == NULL ? "" : wantedNode->value;
}

bool inDictionary(Dict* dict, const char* key)
{
    if (dict == NULL)
    {
        return false;
    }
    Node* wantedNode = search(dict->root, key);
    return wantedNode != NULL;
}

int getBalanceByKey(Dict* dict, const char* key)
{
    Node* node = search(dict->root, key);
    return node == NULL ? 0 : getBalanceFactor(node);
}