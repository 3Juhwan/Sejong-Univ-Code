#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N = 0, cnt = 0;
	int* p = NULL, * q = NULL;

	scanf("%d", &N);
	getchar();

	p = (int*)malloc(N * sizeof(int));

	if (p == NULL)
		return -1;

	for (int i = 0; i < N; i++)
		p[i] = i;

	q = (int*)malloc((N - 1) * sizeof(int));

	if (q == NULL)
		return -1;

	for (int i = 0; i < N;i++)
	{
		if (i == N / 2)
			continue;
		q[cnt] = i;
		cnt++;
	}

	for (int i = 0; i < N - 1;i++)
		printf(" %d", q[i]);

	free(p);
	free(q);

	return 0;
}