#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convert(char p[], char q[], int N);

int main() {
	char arr1[21] = "", arr2[21] = "", result[201] = "";
	int N = 0, flag = 0;

	gets(arr1);
	gets(arr2);
	
	for (int i = 1; i <= 10; i++)
	{
		convert(arr1, result, i);
		if (strcmp(arr2, result) == 0)
			flag += 1;

		convert(arr2, result, i);
		if (strcmp(arr1, result) == 0)
			flag += 2;
	}

	printf("%d", flag);	

	return 0;
}

void convert(char p[], char q[], int N) {
	int tmp = 0;

	while (*p)
	{
		if (*p >= 'A' && *p <= 'Z')
			*q = *p + N;
		else if (*p >= 'a' && *p <= 'z')
			*q = *p - N;
		else if (*p >= '0' && *p <= '9')
		{
			if (*(p + 1) >= '0' && *(p + 1) <= '9')
			{
				tmp = (*p - '0') * 10 + *(p + 1) - '0';
				p++;
			}
			else
				tmp = *p - '0';
			for (int i = 0; i < N;i++)
			{
				*q = tmp + 'A' - 1;
				q++;
			}
			q--;
		}
		else
			*q = ' ';
		p++;
		q++;
	}
	*q = '\0';
}