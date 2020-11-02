#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main() {
	int* p = NULL;
	int  n = 0,sum=0;

	scanf("%d", &n);

	p = (int*)malloc(n * sizeof(int));

	if (p == NULL)
		return 0;

	for(int i = 0; i < n;i++)
		scanf("%d", &p[i]);

	for (int i = 0; i < n;i++)
		sum += p[i];

	printf("%d", sum);

	free(p);

	return 0;
}