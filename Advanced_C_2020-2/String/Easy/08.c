#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char str1[101] = "", str2[101] = "";
	int cmp = 0;

	scanf("%s", str1);
	scanf("%s", str2);

	cmp = strcmp(str1, str2);

	if (cmp > 0)
	{
		strcat(str1, str2);
		printf("%s", str1);
	}
	else
	{
		strcat(str2, str1);
		printf("%s", str2);
	}

	return 0;
}