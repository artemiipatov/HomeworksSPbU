#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "dictionaryFunctions.h"
#include "dictTests.h"

bool testAddAndGet(Node** dict)
{
    *dict = addNode(*dict, 6, "enrg");
    if (*dict == NULL)
    {
        return false;
    }
    *dict = addNode(*dict, 3, "nbcb");
    *dict = addNode(*dict, 8, "qwt");
    *dict = addNode(*dict, 5, "wef");
    *dict = addNode(*dict, 0, "bnvmv");
    *dict = addNode(*dict, 3, "zxc");
    *dict = addNode(*dict, 2, "asfsd");
    *dict = addNode(*dict, 9, "qwer");
    if (strcmp(getValue(dict, 3), "zxc") != 0)
    {
        return false;
    }
    if (getValue(dict, 9) == NULL || strcmp(getValue(dict, 9), "qwer") != 0)
    {
        return false;
    }
    if (getValue(dict, 2) == NULL || strcmp(getValue(dict, 2), "asfsd") != 0)
    {
        return false;
    }
    if (getValue(dict, 3) == NULL || strcmp(getValue(dict, 3), "nbcb") == 0)
    {
        return false;
    }
    if (getValue(dict, 0) == NULL || strcmp(getValue(dict, 0), "bnvmv") != 0)
    {
        return false;
    }
    if (getValue(dict, 8) == NULL || strcmp(getValue(dict, 8), "qwt") != 0)
    {
        return false;
    }
    if (getValue(dict, 5) == NULL || strcmp(getValue(dict, 5), "wef") != 0)
    {
        return false;
    }
    if (getValue(dict, 35) != NULL)
    {
        return false;
    }
    return  getValue(dict, 6) != NULL && strcmp(getValue(dict, 6), "enrg") == 0;
}

bool testDeleteAndInDictionary(Node** dict)
{
    *dict = deleteNode(*dict, 0);
    if (inDictionary(dict, 0))
    {
        return false;
    }
    if (inDictionary(dict, 10))
    {
        return false;
    }
    *dict = deleteNode(*dict, 2);
    *dict = deleteNode(*dict, 5);
    *dict = deleteNode(*dict, 9);
    *dict = deleteNode(*dict, 3);
    if (inDictionary(dict, 2) || inDictionary(dict, 5)
        || inDictionary(dict, 9) || inDictionary(dict, 3)
        || !inDictionary(dict, 8) || !inDictionary(dict, 6))
    {
        return false;
    }
    *dict = deleteNode(*dict, 8);
    *dict = deleteNode(*dict, 6);
    if (inDictionary(dict, 8) || inDictionary(dict, 6))
    {
        return false;
    }
    deleteDictionary(dict);
    return *dict == NULL;
}

bool testDeleteDictionary(Node* dict)
{
    dict = addNode(dict, 3, "nbcb");
    dict = addNode(dict, 8, "qwt");
    dict = addNode(dict, 5, "wef");
    dict = addNode(dict, 0, "bnvmv");
    dict = addNode(dict, 3, "zxc");
    dict = addNode(dict, 2, "asfsd");
    dict = addNode(dict, 9, "qwer");
    deleteDictionary(&dict);
    return dict == NULL;
}

bool programPassedTests()
{
    Node* dict = createDictionary();
    return testAddAndGet(&dict) && testDeleteAndInDictionary(&dict) && testDeleteDictionary(dict);
}