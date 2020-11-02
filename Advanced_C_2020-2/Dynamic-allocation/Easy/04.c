#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N = 0, D = 0;
	char A = 'a';
	char** p = NULL;

	scanf("%d %d", &D, &N);

	p = (char**)malloc(N * sizeof(char*));

	if (p == NULL)
		return 0;

	for (int i = 0;i < N;i++)
	{
		p[i] = (char*)malloc(D * sizeof(char));
		if (p[i] == NULL)
			return -1;
	}

	for (int i = 0;i < N;i++)
		for (int j = 0; j < D;j++)
		{
			p[i][j] = A;
			if (A == 'z')
				A = 'A';
			else if (A == 'Z')
				A = 'a';
			else 
				A++;
		}

	for (int i = 0;i < N;i++)
	{
		for (int j = 0; j < D;j++)
			printf("%c ", p[i][j]);
		printf("\n");
	}

	for (int i = 0;i < N;i++)
		free(p[i]);

	free(p);

	return 0;
}