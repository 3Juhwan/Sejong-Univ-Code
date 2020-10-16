#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convert(char p[], char q[], int N);

int main() {
	char arr[21] = "", result[201] = "";
	int N = 0;

	scanf("%s", arr);
	scanf("%d", &N);

	convert(arr, result, N);

	printf("%s", result);	

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