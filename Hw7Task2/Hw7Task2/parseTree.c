#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "parseTree.h"

typedef struct Node
{
    int value;
    bool isOperation;
    struct Node* leftSon;
    struct Node* rightSon;
    struct Node* parent;
} Node;

Node* createTree()
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

void deleteTree(Node** root)
{
    deleteTreeRecursive(*root);
    *root = NULL;
}

bool addNode(Node** root, int value, bool isOperation)
{
    if (isOperation)
    {
        switch (value)
        {
            case ')':
            {
                (*root) = (*root)->parent == NULL ? (*root) : (*root)->parent;
                break;
            }
            case '+':
            case '-':
            case '*':
            case '/':
            {
                Node* newRoot = calloc(1, sizeof(Node));
                if (newRoot == NULL)
                {
                    return false;
                }
                newRoot->value = value;
                newRoot->parent = *root;
                newRoot->isOperation = true;
                if (*root != NULL)
                {
                    if ((*root)->leftSon == NULL)
                    {
                        (*root)->leftSon = newRoot;
                        *root = (*root)->leftSon;
                    }
                    else
                    {
                        (*root)->rightSon = newRoot;
                        *root = (*root)->rightSon;
                    }
                }
                else
                {
                    *root = newRoot;
                }
                break;
            }
        }
    }
    else
    {
        Node* newRoot = calloc(1, sizeof(Node));
        if (newRoot == NULL)
        {
            return false;
        }
        newRoot->value = value;
        newRoot->parent = *root;
        newRoot->isOperation = false;
        if ((*root)->leftSon == NULL)
        {
            (*root)->leftSon = newRoot;
        }
        else
        {
            (*root)->rightSon = newRoot;
        }
    }
    return true;
}

bool parse(Node** root, FILE* file)
{
    while (!feof(file))
    {
        char ch = fgetc(file);
        if (ch == EOF)
        {
            break;
        }
        switch (ch)
        {
            case '(':
            case ' ':
            {
                continue;
            }
            case ')':
            case '*':
            case '/':
            case '+':
            case '-':
            {
                char temp = fgetc(file);
                if (temp == ' ' || temp == ')' || temp == EOF)
                {
                    ungetc(temp, file);
                    if (!addNode(root, (int)ch, true))
                    {
                        return false;
                    }
                    continue;
                }
                ungetc(temp, file);
            }
            default:
            {
                ungetc(ch, file);
                int value = 0;
                fscanf(file, "%d", &value);
                if (!addNode(root, value, false))
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int eval(Node* root)
{
    if (root->leftSon == NULL && root->rightSon == NULL)
    {
        return root->value;
    }
    int firstOperand = eval(root->leftSon);
    int secondOperand = eval(root->rightSon);
    int result = 0;
    switch (root->value)
    {
        case '*':
        {
            result = firstOperand * secondOperand;
            break;
        }
        case '/':
        {
            result = firstOperand / secondOperand;
            break;
        }
        case '+':
        {
            result = firstOperand + secondOperand;
            break;
        }
        case '-':
        {
            result = firstOperand - secondOperand;
            break;
        }
    }
    return result;
}

void printPreorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->isOperation)
    {
        switch (root->value)
        {
            case '+':
            {
                printf("( + ");
                break;
            }
            case '-':
            {
                printf("( - ");
                break;
            }
            case '*':
            {
                printf("( * ");
                break;
            }
            case '/':
            {
                printf("( / ");
                break;
            }
        }
    }
    else
    {
        printf("%d ", root->value);
        Node* currentNode = root;
        while (currentNode->parent != NULL && currentNode->parent->rightSon == currentNode)
        {
            printf(") ");
            currentNode = currentNode->parent;
        }
    }
    printPreorder(root->leftSon);
    printPreorder(root->rightSon);
}

bool isEmpty(Node* root)
{
    return root == NULL;
}