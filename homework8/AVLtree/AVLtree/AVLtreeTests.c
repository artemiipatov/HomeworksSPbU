#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "AVLtree.h"
#include "AVLtreeTests.h"

bool insertItems(Dict* dict)
{
    return insert(dict, "3", "nbcb")
        && insert(dict, "8", "qwt")
        && insert(dict, "5", "wef")
        && insert(dict, "0", "bnvmv")
        && insert(dict, "3", "zxc")
        && insert(dict, "2", "asfsd")
        && insert(dict, "9", "qwer")
        && insert(dict, "19", "ogmwq")
        && insert(dict, "40", "omogas")
        && insert(dict, "1", "lpwqtp")
        && insert(dict, "13", "mdigm")
        && insert(dict, "20", "zxooqwkero")
        && insert(dict, "14", "ewtkqwo")
        && insert(dict, "-1", "fkpodsmgf");
}

bool testAddAndGet(void)
{
    Dict* dict = createDictionary();
    insert(dict, "6", "enrg");
    if (dict == NULL)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (!insertItems(dict))
    {
        deleteDictionary(&dict);
        return false;
    }
    if (strcmp(getValue(dict, "3"), "zxc") != 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, "19") == "" || strcmp(getValue(dict, "19"), "ogmwq") != 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, "1") == "" || strcmp(getValue(dict, "1"), "lpwqtp") != 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, "14") == "" || strcmp(getValue(dict, "14"), "ewtkqwo") != 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, "20") == "" || strcmp(getValue(dict, "20"), "zxooqwkero") != 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, "13") == "" || strcmp(getValue(dict, "13"), "mdigm") != 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, "40") == "" || strcmp(getValue(dict, "40"), "omogas") != 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, "-1") == "" || strcmp(getValue(dict, "-1"), "fkpodsmgf") != 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, "9") == "" || strcmp(getValue(dict, "9"), "qwer") != 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, "2") == "" || strcmp(getValue(dict, "2"), "asfsd") != 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, "3") == "" || strcmp(getValue(dict, "3"), "nbcb") == 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, "0") == "" || strcmp(getValue(dict, "0"), "bnvmv") != 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, "8") == "" || strcmp(getValue(dict, "8"), "qwt") != 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, "5") == "" || strcmp(getValue(dict, "5"), "wef") != 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, "35") != "")
    {
        deleteDictionary(&dict);
        return false;
    }
    if (getValue(dict, "6") == "" || strcmp(getValue(dict, "6"), "enrg") != 0)
    {
        deleteDictionary(&dict);
        return false;
    }
    int balanceFactor14 = getBalanceByKey(dict, "14");
    int balanceFactor0 = getBalanceByKey(dict, "0");
    int balanceFactor6 = getBalanceByKey(dict, "6");
    int balanceFactor9 = getBalanceByKey(dict, "9");
    if (!(balanceFactor14 >= -1 && balanceFactor14 <= 1
        && balanceFactor0 >= -1 && balanceFactor0 <= 1
        && balanceFactor6 >= -1 && balanceFactor6 <= 1
        && balanceFactor9 >= -1 && balanceFactor9 <= 1))
    {
        deleteDictionary(&dict);
        return false;
    }
    deleteDictionary(&dict);
    return true;
}

bool testDeleteAndInDictionary(void)
{
    Dict* dict = createDictionary();
    insertItems(dict);
    deleteNode(&dict, "0");
    if (inDictionary(dict, "0"))
    {
        deleteDictionary(&dict);
        return false;
    }
    if (inDictionary(dict, "10"))
    {
        deleteDictionary(&dict);
        return false;
    }
    deleteNode(&dict, "2");
    deleteNode(&dict, "19");
    deleteNode(&dict, "9");
    deleteNode(&dict, "3");
    if (inDictionary(dict, "2") || inDictionary(dict, "19")
        || inDictionary(dict, "9") || inDictionary(dict, "3")
        || !inDictionary(dict, "8"))
    {
        deleteDictionary(&dict);
        return false;
    }
    deleteNode(&dict, "8");
    if (inDictionary(dict, "8"))
    {
        deleteDictionary(&dict);
        return false;
    }
    deleteDictionary(&dict);
    return dict == NULL;
}

bool testDeleteDictionary(void)
{
    Dict* dict = createDictionary();
    if (dict == NULL)
    {
        return false;
    }
    if (!insertItems(dict))
    {
        deleteDictionary(&dict);
        return false;
    }
    deleteDictionary(&dict);
    return dict == NULL;
}

bool AvlTreePassedTests()
{
    return testAddAndGet() && testDeleteAndInDictionary() && testDeleteDictionary();
}