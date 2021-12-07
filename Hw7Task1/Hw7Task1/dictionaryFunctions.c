#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "dictionaryFunctions.h"

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
} Node;

Node* createDictionary()
{
    return NULL;
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

void deleteDictionary(Node** root)
{
    deleteTreeRecursive(*root);
    *root = NULL;
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

void zig(Node* x)
{
    Node* p = x->parent;
    if (x == p->leftSon)
    {
        Node* b = x->rightSon;
        attach(x, p, right);
        attach(p, b, left);
    }
    else
    {
        Node* b = x->leftSon;
        attach(x, p, left);
        attach(p, b, right);
    }
    x->parent = NULL;
}

void zigZig(Node* x)
{
    Node* ggp = x->parent->parent->parent;
    Node* gp = x->parent->parent;
    Node* p = x->parent;
    if (p->leftSon == x)
    {
        Node* pRight = p->rightSon;
        Node* xRight = x->rightSon;
        attach(x, p, right);
        attach(p, gp, right);
        attach(gp, pRight, left);
        attach(p, xRight, left);
    }
    else
    {
        Node* pLeft = p->leftSon;
        Node* xLeft = x->leftSon;
        attach(x, p, left);
        attach(p, gp, left);
        attach(gp, pLeft, right);
        attach(p, xLeft, right);
    }
    if (ggp != NULL)
    {
        if (ggp->rightSon == gp)
        {
            ggp->rightSon = x;
        }
        else
        {
            ggp->leftSon = x;
        }
    }
    x->parent = ggp;
}

void zigZag(Node* x)
{
    Node* ggp = x->parent->parent->parent;
    Node* gp = x->parent->parent;
    Node* p = x->parent;
    Node* xLeft = x->leftSon;
    Node* xRight = x->rightSon;
    if (x == p->leftSon)
    {
        attach(x, p, right);
        attach(x, gp, left);
        attach(p, xRight, left);
        attach(gp, xLeft, right);
    }
    else
    {
        attach(x, p, left);
        attach(x, gp, right);
        attach(p, xLeft, right);
        attach(gp, xRight, left);
    }
    if (ggp != NULL)
    {
        if (ggp->rightSon == gp)
        {
            ggp->rightSon = x;
        }
        else
        {
            ggp->leftSon = x;
        }
    }
    x->parent = ggp;
}

Node* splay(Node* x)
{
    if (x == NULL || x->parent == NULL)
    {
        return x;
    }
    if (x->parent->parent == NULL)
    {
        zig(x);
        return x;
    }
    if ((x->parent->leftSon == x && x->parent->parent->leftSon == x->parent)
        || (x->parent->rightSon == x && x->parent->parent->rightSon == x->parent))
    {
        zigZig(x);
    }
    else
    {
        zigZag(x);
    }
    return splay(x);
}

Node* addNode(Node* root, const int key, const char* value)
{
    if (root == NULL)
    {
        Node* newRoot = calloc(1, sizeof(Node));
        if (newRoot == NULL)
        {
            return NULL;
        }
        newRoot->key = key;
        strcpy_s(newRoot->value, 50, value);
        return newRoot;
    }
    Node* i = root;
    while (i != NULL)
    {
        if (key > i->key)
        {
            if (i->rightSon == NULL)
            {
                Node* newRoot = calloc(1, sizeof(Node));
                if (newRoot == NULL)
                {
                    return NULL;
                }
                newRoot->key = key;
                strcpy(newRoot->value, value);
                i->rightSon = newRoot;
                newRoot->parent = i;
                return splay(newRoot);
            }
            i = i->rightSon;
        }
        else if (key == i->key)
        {
            strcpy_s(i->value, 50, value);
            return splay(i);
        }
        else
        {
            if (i->leftSon == NULL)
            {
                Node* newRoot = calloc(1, sizeof(Node));
                if (newRoot == NULL)
                {
                    return NULL;
                }
                newRoot->key = key;
                strcpy_s(newRoot->value, 50, value);
                i->leftSon = newRoot;
                newRoot->parent = i;
                return splay(newRoot);
            }
            i = i->leftSon;
        }
    }
    return root;
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
            i = splay(i);
            return i;
        }
    }
    return NULL;
}

Node* deleteNode(Node* root, const int key)
{
    Node* x = search(root, key);
    if (x == NULL)
    {
        return root;
    }
    if (x->rightSon != NULL)
    {
        Node* i = x->rightSon;
        while (i->leftSon != NULL)
        {
            i = i->leftSon;
        }
        x->key = i->key;
        strcpy(x->value, i->value);
        if (i == x->rightSon)
        {
            attach(x, i->rightSon, right);
        }
        else
        {
            attach(i->parent, i->rightSon, left);
        }
        free(i);
    }
    else if (x->leftSon != NULL)
    {
        Node* temp = x->leftSon;
        free(x);
        temp->parent = NULL;
        x = temp;
    }
    else
    {
        free(x);
        x = NULL;
    }
    return x;
}

char* getValue(Node** root, const int key)
{
    Node* wantedNode = search(*root, key);
    if (wantedNode != NULL)
    {
        *root = wantedNode;
    }
    return wantedNode == NULL ? '\0' : wantedNode->value;
}

bool inDictionary(Node** root, const int key)
{
    Node* wantedNode = search(*root, key);
    return wantedNode != NULL;
}