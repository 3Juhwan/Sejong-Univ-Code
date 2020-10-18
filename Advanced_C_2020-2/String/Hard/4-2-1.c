#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char arr[101] = "", * p = arr;
	double pnum[10] = { 0.0 };
	int smb[10] = { 0 };
	int len = 0, size1 = 0, size2 = 1;

	gets_s(arr, 101);
	len = strlen(arr);

	while (*p)
	{
		if (*p == ' ')
			*p = '\0';
		else if (*p == '+' || *p == '*' || *p == '/')
		{
			*p = '\0';
			size2++;
		}
		else if (*p == '-')
		{
			*p = '\0';
			smb[size2] = 1;
			size2++;
		}
		p++;
	}

	p = arr;
	size2 = 0;
	while (p < arr + len)
	{
		if (smb[size2] == 1)
			pnum[size1] = atof(p) * (-1);

		else if (smb[size2] == 0)
			pnum[size1] = atof(p);

		p += strlen(p);
		size1++;
		size2++;

		while (!*p)
			p++;
	}

	for (int i = 0; i < size1; i++)
		printf(" %.lf", pnum[i]);

	return 0;
}