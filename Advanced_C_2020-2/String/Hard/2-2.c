#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char arr[100] = "", * p = arr, * q = arr, tmp = '\0';
	char* tarr[51] = { NULL }, * ttmp = NULL;
	int size = 0;

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

	for (int i = 0; i < size - 1;i++)
	{
		for (int j = 0; j < size - i - 1;j++)
		{
			if (*tarr[j] > * tarr[j + 1])
			{
				ttmp = tarr[j];
				tarr[j] = tarr[j + 1];
				tarr[j + 1] = ttmp;
			}
		}
	}

	for (int i = 0; i < size; i++)
		puts(tarr[i]);

	return 0;
}