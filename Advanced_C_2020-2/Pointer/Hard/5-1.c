#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int main() {
	char arr[1001] = "", * p = arr, * q = arr;
	char* tarr[500] = { NULL };
	char endsmb = '\0';
	int size = 0;

	gets_s(arr, 1001);

	while (*p)
	{
		if (*p == ' ' || *p == '.' || *p == '?' || *p == '!')
		{
			endsmb = *p;
			*p = '\0';
			tarr[size] = q;
			size++;
			q = q + strlen(q) + 1;
		}
		p++;
	}

	for (int i = size - 1; i >= 0; i--)
	{
		printf("%s", tarr[i]);
		if (i != 0) printf(" ");
	}
	printf("%c", endsmb);


	return 0;
}