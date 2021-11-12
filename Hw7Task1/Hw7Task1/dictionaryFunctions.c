#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "dictionaryFunctions.h"

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
        parent->leftSon = child;
    else
        parent->rightSon = child;
    if (child != NULL)
        child->parent = parent;
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

Node* addNode(Node* root, int key, char* value)
{
    if (root == NULL)
    {
        Node* newRoot = calloc(1, sizeof(Node));
        newRoot->key = key;
        strcpy(newRoot->value, value);
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
            strcpy(i->value, value);
            return splay(i);
        }
        else
        {
            if (i->leftSon == NULL)
            {
                Node* newRoot = calloc(1, sizeof(Node));
                newRoot->key = key;
                strcpy(newRoot->value, value);
                i->leftSon = newRoot;
                newRoot->parent = i;
                return splay(newRoot);
            }
            i = i->leftSon;
        }
    }
    return root;
}

Node* search(Node* root, int key)
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
    return i;
}

Node* deleteNode(Node* root, int key)
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
            x->rightSon = i->rightSon;
        }
        else
        {
            i->parent->leftSon = i->rightSon;
        }
        if (i->rightSon != NULL)
        {
            i->rightSon->parent = i->parent;
        }
        root = x == root ? root : splay(x->parent);
        free(i);
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
            root = splay(x->parent);
        }
        else
        {
            x->leftSon->parent = x->parent;
            root = x->leftSon;
        }
        free(x);
    }
    else if (x->parent == NULL)
    {
        deleteDictionary(&root);
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
        root = splay(x->parent);
        free(x);
    }
    return root;
}

char* getValue(Node** root, int key)
{
    Node* wantedNode = search(*root, key);
    if (wantedNode != NULL)
    {
        *root = splay(wantedNode);
    }
    return wantedNode == NULL ? '\0' : wantedNode->value;
}

bool inDictionary(Node** root, int key)
{
    Node* wantedNode = search(*root, key);
    if (wantedNode != NULL)
    {
        *root = splay(wantedNode);
    }
    return wantedNode != NULL;
}