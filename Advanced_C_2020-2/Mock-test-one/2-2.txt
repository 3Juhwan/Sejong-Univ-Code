#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int main() {
	char arr[101] = "", * pch[100] = { NULL };
	char* p = arr, * q = arr, * first = arr;
	int N = 0, size = 0;

	gets(arr);
	scanf("%d", &N);

	while (*p)
	{
		if (*p == ' ')
		{
			*p = '\0';
			pch[size] = q;
			size++;
			q += strlen(q) + 1;
		}
		p++;
	}
	pch[size] = q;
	size++;

	for (int i = 0; i < size; i++)
	{
		if (strcmp(first, pch[i]) > 0)
			first = pch[i];
	}

	printf("%s\n%s", pch[N - 1],first);


	return 0;
}