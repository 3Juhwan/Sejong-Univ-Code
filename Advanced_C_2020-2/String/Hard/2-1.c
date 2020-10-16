#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char arr[100] = "", tmp = '\0';

	scanf("%s", arr);

	for (char* p = arr; *(p + 1);p++)
	{
		for (char* q = p + 1; *q;q++)
		{

			if (*p > * q)
			{
				tmp = *p;
				*p = *q;
				*q = tmp;
			}
		}
	}

	printf("%s", arr);

	return 0;
}