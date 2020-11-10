#pragma warning (disable:4669)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char arr[100] = "";
	char* p = arr;
	int len = 0, size = 0;
	double num[10] = { 0.0 };

	gets(arr);

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
		if (*p)
		{
			num[size] = atof(p);
			size++;
		}
		p += strlen(p) + 1;
	}

	for (int i = 0; i < size; i++)
		printf(" %.lf", num[i]);

	return 0;
}