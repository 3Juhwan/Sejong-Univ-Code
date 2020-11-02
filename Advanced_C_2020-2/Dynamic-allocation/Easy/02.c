#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main() {
	int  n = 0;
	float *p = NULL, big = 0.0;

	scanf("%d", &n);

	p = (float*)malloc(n * sizeof(float));

	if (p == NULL)
		return 0;

	for (int i = 0; i < n;i++)
		scanf("%f", &p[i]);

	big = p[0];
	for (int i = 1; i < n;i++)
		if (big < p[i])
			big = p[i];

	printf("%.2f", big);

	free(p);

	return 0;
}