#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char arr[100] = "", * p = arr, * q = arr, tmp = '\0';
	char* tarr[51] = { NULL }, * ttmp = NULL;
	int size = 0, cmp = 0;

	gets_s(arr, 100);

	while (*p)
	{
		if (*p == ' ')
		{
			*p = '\0';
			tarr[size] = q;
			size++;
			q += strlen(q) + 1;
		}
		p++;
	}
	tarr[size] = q;
	size++;

	for (int i = 0; i < size; i++)
		printf("%s\n", tarr[i]);

	for (int i = 0; i < size;i++)
	{
		cmp = strcmp(tarr[0], tarr[i]);
		if (cmp > 0)
			tarr[0] = tarr[i];
	}

	printf("%s\n", tarr[0]);

	return 0;
}