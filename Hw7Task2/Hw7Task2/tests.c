#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include "parseTree.h"

bool programPassedTests()
{
	FILE* testFile = fopen("testFile.txt", "r");
	if (testFile == NULL)
	{
		return false;
	}
	Node* root = createTree();
	if (!parse(&root, testFile))
	{
		fclose(testFile);
		deleteTree(&root);
		return false;
	}
	fclose(testFile);
	if (eval(root) != 10494)
	{
		fclose(testFile);
		deleteTree(&root);
		return false;
	}
	deleteTree(&root);
	return isEmpty(root);
}