#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_row(int** p, int M, int N);
int check_col(int** p, int M, int N);

int main() {
	int M = 0, N = 0;
	int x = 0, y = 0, z = 0;
	int number = 0, tmp = 0;
	int** p = NULL;

	scanf("%d %d", &M, &N);
	getchar();

	// allocation
	p = (int**)malloc(M * sizeof(int*));
	if (p == NULL) {
		printf("Not enough memory");
		return -1;
	}

	for (int i = 0; i < M; i++)
	{
		p[i] = (int*)malloc(N * sizeof(int));
		if (p[i] == NULL) {
			printf("Not enough memory");
			return -1;
		}

		for (int j = 0;j < N;j++)
			p[i][j] = 0;
	}

	// input
	scanf("%d %d %d", &x, &y, &z);
	while (x != 0 || y != 0 || z != 0)
	{
		p[x][y] = z;

		scanf("%d %d %d", &x, &y, &z);
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			printf(" %d", p[i][j]);
		printf("\n");
	}

	tmp = check_row(p, M, N);
	if (number < tmp)
		number = tmp;

	tmp = check_col(p, M, N);
	if (number < tmp)
		number = tmp;

	printf("%d", number);

	for (int i = 0; i < M; i++)
		free(p[i]);
	free(p);

	return 0;
}


int check_row(int** p, int M, int N) {
	int cnt = 0, tmp = 0;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = j; k < N && p[i][k] == 0; k++)
				tmp++;
			if (cnt < tmp)
				cnt = tmp;
			tmp = 0;
		}
	}

	return cnt;
}

int check_col(int** p, int M, int N) {
	int cnt = 0, tmp = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M ; j++)
		{
			for (int k = j; k < M && p[k][i] == 0; k++)
				tmp++;
			if (cnt < tmp)
				cnt = tmp;
			tmp = 0;
		}
	}

	return cnt;
}