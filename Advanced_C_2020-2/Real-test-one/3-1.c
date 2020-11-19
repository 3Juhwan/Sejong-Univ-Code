#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char arr[151] = "", word[11] = "";
	char* p = arr, * q = arr;

	gets_s(arr, 151);
	gets_s(word, 11);

	while (*p)
	{
		if (*p == ' ')
		{
			*p = '\0';
			if (strcmp(word, q) != 0)
				printf("%s ", q);
			q += strlen(q) + 1;
		}
		p++;
	}
	if (strcmp(word, q) != 0)
		printf("%s ", q);

	return 0;
}