#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include "parseTree.h"

bool programPassedTests()
{
    Node* root = parse("testFile.txt");
    if (root == NULL)
    {
        return false;
    }
    if (eval(root) != 10494)
    {
        deleteTree(&root);
        return false;
    }
    deleteTree(&root);
    return isEmpty(root);
}