#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "parseTree.h"
#include "tests.h"

int main()
{
    if (!programPassedTests())
    {
        printf("tests failed");
        return -1;
    }
    Node* root = parse("input.txt");
    if (root == NULL)
    {
        return -1;
    }
    printf("expression: ");
    printPreorder(root);
    printf("\nresult: %d", eval(root));
    deleteTree(&root);
    return 0;
}