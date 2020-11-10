#pragma warning (disable:4669)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void del(char arr[]);

int main() {
	char arr[100] = "";
	char* p = arr, * q = arr;
	int size = 0;
	int smb[10] = { 0, };
	double num[10] = { 0.0 };

	gets_s(arr, 100);

	del(arr);

	while (*p)
	{
		if (*p == '+' || *p == '*' || *p == '/')
		{
			*p = '\0';
			num[size] = atof(q);
			size++;
			q += strlen(q) + 1;
			smb[size] = 0;
		}
		else if (*p == '-')
		{
			*p = '\0';
			num[size] = atof(q);
			size++;
			q += strlen(q) + 1;
			smb[size] = 1;
		}
		p++;
	}
	num[size] = atof(q);
	size++;

	for (int i = 0; i < size;i++)
		if (smb[i] == 1)
			num[i] *= -1;

	for (int i = 0; i < size; i++)
		printf(" %.lf", num[i]);

	return 0;
}

void del(char arr[]) {
	char* p = arr, * q = NULL;

	while (*p)
	{
		if (*p == ' ')
		{
			q = p;
			while (*q != '\0')
			{
				*q = *(q + 1);
				q++;
			}
			continue;
		}
		p++;
	}
}