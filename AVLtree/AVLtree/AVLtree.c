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
    int key;
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
    if (node->leftSon != NULL && node->rightSon != NULL)
    {
        node->height = node->height > node->rightSon->height + 1 ? node->height : node->rightSon->height + 1;
        return;
    }
    node->height = node->leftSon != NULL ? node->leftSon->height + 1 : node->rightSon->height + 1;
}

int balanceFactor(Node* node)
{
    if (node->leftSon == NULL && node->rightSon == NULL)
    {
        return 0;
    }
    else if (node->leftSon != NULL)
    {
        return -1;
    }
    return 1;
}

Node* rotateLeft(Node* a)
{
    Node* b = a->rightSon;
    a->rightSon->leftSon = a;
    a->rightSon = b->rightSon;
    return b;
}

Node* rotateRight(Node* a)
{
    Node* b = a->leftSon;
    a->leftSon->rightSon = b;
    a->leftSon = b->leftSon;
    return b;
}

Node* bigRotateLeft(Node* a)
{
    a = rotateRight(a->rightSon);
    return rotateLeft(a); 
}

Node* bigRotateRight(Node* a)
{
    a = rotateLeft(a->leftSon);
    return rotateRight(a);
}

Node* balance(Node* node)
{
    if (balanceFactor(node) == 2)
    {
        if (balanceFactor(node->rightSon) <= 0)
        {
            return rotateLeft(node);
        }
        return bigRotateLeft(node);
    }
    if (balanceFactor(node) == -2)
    {
        if (balanceFactor(node->leftSon) <= 0)
        {
            return rotateRight(node);
        }
        return bigRotateRight(node);
    }
    return node;
}

Node* insertRecursive(Node* node, const int key, const char* value)
{
    if (node == NULL)
    {
        Node* newNode = calloc(1, sizeof(Node));
        if (newNode == NULL)
        {
            return NULL;
        }
        newNode->key = key;
        strcpy_s(newNode->value, 50, value);
        newNode->height = 1;
        return newNode;
    }
    if (key < node->key)
    {
        node->leftSon = insertRecursive(node->leftSon, key, value);
        correctHeight(node);
    }
    else if (key > node->key)
    {
        node->rightSon = insertRecursive(node->rightSon, key, value);
        correctHeight(node);
    }
    else
    {
        strcpy_s(node->value, 50, value);
        return node;
    }
    return balance(node);
}

bool insert(Dict* dict, const int key, const char* value)
{
    Node* returnedNode = insertRecursive(dict->root, key, value);
    if (returnedNode == NULL)
    {
        return false;
    }
    dict->root = returnedNode;
    return true;
}

Node* search(Node* root, const int key)
{
    Node* i = root;
    while (i != NULL)
    {
        if (key > i->key)
        {
            i = i->rightSon;
        }
        else if (key < i->key)
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

void fullBalance(Node* x)
{
    if (x == NULL)
    {
        return;
    }
    Node* i = x->leftSon;
    while (i != NULL)
    {
        int oldHeight = i->height;
        correctHeight(i);
        if (oldHeight == i->height || i->parent == NULL)
        {
            break;
        }
        i = i->parent;
    }
}

void deleteNode(Dict* dict, int key)
{
    Node* root = dict->root;
    Node* x = search(root, key);
    if (x == NULL)
    {
        return;
    }
    if (x->rightSon != NULL)
    {
        Node* minimum = searchMin(x->rightSon);
        x->key = minimum->key;
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
        fullBalance(minimum->parent);
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
        fullBalance(x->parent);
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
        fullBalance(x->parent);
        free(x);
    }
    return;
}

char* getValue(Dict* dict, const int key)
{
    Node* wantedNode = search(dict->root, key);
    if (wantedNode != NULL)
    {
        dict->root = wantedNode;
    }
    return wantedNode == NULL ? '\0' : wantedNode->value;
}

bool inDictionary(Dict* dict, const int key)
{
    Node* wantedNode = search(dict->root, key);
    return wantedNode != NULL;
}