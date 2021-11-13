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
	FILE* file = fopen("input.txt", "r");
	if (file == NULL)
	{
		return -1;
	}
	Node* root = createTree();
	if (!parse(&root, file))
	{
		fclose(file);
		deleteTree(&root);
		return -1;
	}
	fclose(file);
	printf("expression: ");
	printPreorder(root);
	printf("\nresult: %d", eval(root));
	deleteTree(&root);
	return 0;
}