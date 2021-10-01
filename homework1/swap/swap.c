#include <stdio.h>

int main()
{
	int first = 0;
	int second = 0;

	printf("Enter the numbers:\n");
	scanf("%d %d", &first, &second);
	printf("\n");

	first = first ^ second;
	second = first ^ second;
	first = first ^ second;

	printf("%d\n%d", first, second);
}