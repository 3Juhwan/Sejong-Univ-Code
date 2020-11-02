#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N = 0, tmp = 0;
	int* p = NULL;

	scanf("%d", &N);
	getchar();

	p = (int*)malloc(N * sizeof(int));

	if (p == NULL)
		return -1;

	for (int i = 0; i < N; i++)
		scanf("%d", &p[i]);

	for (int i = 0;i < N - 1;i++)
		if (p[i] > p[i + 1])
		{
			tmp = p[i];
			p[i] = p[i + 1];
			p[i + 1] = tmp;
		}

	for (int i = 0; i < N;i++)
		printf("%d\n", p[i]);

	free(p);

	return 0;
}