#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "AVLtree.h"
#include "AVLtreeTests.h"

bool testAddAndGet(Dict* dict)
{
    insert(dict, 6, "enrg");
    if (dict == NULL)
    {
        deleteDictionary(&dict);
        return false;
    }
    //if (!insert(dict, 3, "nbcb")
    //    || !insert(dict, 8, "qwt")
    //    || !insert(dict, 5, "wef")
    //    || !insert(dict, 0, "bnvmv")
    //    || !insert(dict, 3, "zxc")
    //    || !insert(dict, 2, "asfsd")
    //    || !insert(dict, 9, "qwer")
    //    || !insert(dict, 19, "ogmwq")
    //    || !insert(dict, 40, "omogas")
    //    || !insert(dict, 1, "lpwqtp")
    //    || !insert(dict, 13, "mdigm")
    //    || !insert(dict, 20, "zxooqwkero")
    //    || !insert(dict, 14, "ewtkqwo")
    //    || !insert(dict, -1, "fkpodsmgf"))
    //{
    //    return false;
    //}
    insert(dict, 3, "nbcb");
    insert(dict, 8, "qwt");
    insert(dict, 5, "wef");
    insert(dict, 0, "bnvmv");
    insert(dict, 3, "zxc");
    insert(dict, 2, "asfsd");
    insert(dict, 9, "qwer");
    insert(dict, 19, "ogmwq");
    insert(dict, 40, "omogas");
    insert(dict, 1, "lpwqtp");
    insert(dict, 13, "mdigm");
    insert(dict, 20, "zxooqwkero");
    insert(dict, 14, "ewtkqwo");
    insert(dict, -1, "fkpodsmgf");
    if (strcmp(getValue(dict, 3), "zxc") != 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, 9) == NULL || strcmp(getValue(dict, 9), "qwer") != 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, 2) == NULL || strcmp(getValue(dict, 2), "asfsd") != 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, 3) == NULL || strcmp(getValue(dict, 3), "nbcb") == 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, 0) == NULL || strcmp(getValue(dict, 0), "bnvmv") != 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, 8) == NULL || strcmp(getValue(dict, 8), "qwt") != 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, 5) == NULL || strcmp(getValue(dict, 5), "wef") != 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, 35) != NULL)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, 6) == NULL || strcmp(getValue(dict, 6), "enrg") != 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    return true;
}

bool testDeleteAndInDictionary(Dict* dict)
{
    deleteNode(&dict, 0);
    if (inDictionary(dict, 0))
    {
        deleteDictionary(&dict);
        return  false;
    }
    if (inDictionary(dict, 10))
    {
        deleteDictionary(&dict);
        return false;
    }
    deleteNode(&dict, 2);
    deleteNode(&dict, 19);
    deleteNode(&dict, 9);
    deleteNode(&dict, 3);
    if (inDictionary(dict, 2) || inDictionary(dict, 5)
        || inDictionary(dict, 9) || inDictionary(dict, 3)
        || !inDictionary(dict, 8) || !inDictionary(dict, 6))
    {
        deleteDictionary(&dict);
        return false;
    }
    deleteNode(&dict, 8);
    deleteNode(&dict, 6);
    if (inDictionary(dict, 8) || inDictionary(dict, 6))
    {
        deleteDictionary(&dict);
        return false;
    }
    deleteDictionary(&dict);
    return dict == NULL;
}

bool testDeleteDictionary(Dict* dict)
{
    dict = createDictionary();
    if (dict == NULL)
    {
        return false;
    }
    if (!insert(dict, 3, "nbcb")
        || !insert(dict, 8, "qwt")
        || !insert(dict, 5, "wef")
        || !insert(dict, 0, "bnvmv")
        || !insert(dict, 3, "zxc")
        || !insert(dict, 2, "asfsd")
        || !insert(dict, 9, "qwer"))
    {
        return false;
    }
    deleteDictionary(&dict);
    return dict == NULL;
}

bool AVLtreePassedTests()
{
    Dict* dict = createDictionary();
    return testAddAndGet(dict) && testDeleteAndInDictionary(dict) && testDeleteDictionary(dict);
}