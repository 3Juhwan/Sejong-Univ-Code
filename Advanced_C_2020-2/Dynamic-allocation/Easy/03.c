#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N = 0, D = 0;
	int* p = NULL;

	scanf("%d", &N);

	p = (int*)malloc(N * sizeof(int));

	if (p == NULL)
		return 0;

	for (int i = 0;i < N;i++)
		scanf("%d", &p[i]);

	scanf("%d", &D);

	p = (int*)realloc(p, (N - D) * sizeof(int));

	for (int i = 0;i < N - D;i++)
		printf("%d\n", p[i]);
		
	free(p);

	return 0;
}