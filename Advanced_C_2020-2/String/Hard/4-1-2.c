#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char arr[101] = "", * p = arr;
	double pnum[10] = { 0.0 };
	int len = 0, size = 0;

	gets_s(arr, 101);
	len = strlen(arr);

	while (*p)
	{
		if (*p == ' ' || *p == '+' || *p == '-' || *p == '*' || *p == '/')
			*p = '\0';
		p++;
	}

	p = arr;
	while (p < arr + len)
	{
		pnum[size] = atof(p);
		size++;
		p += strlen(p);
		while (!*p)
			p++;
	}

	for (int i = 0; i < size; i++)
		printf("% .lf", pnum[i]);

	return 0;
}