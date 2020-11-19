#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person {
	char name[11];
	int n1;
	int n2;
	double total;
}person;

void swap(person* p, person* q);

int main() {
	int N = 0, M = 0;
	person P[100] = { "" }, * p = NULL, *q = NULL;

	scanf("%d %d", &N, &M);
	getchar();

	for (p = P;p < P + N;p++)
	{
		scanf("%s %d %d", p->name, &p->n1, &p->n2);
		getchar();

		p->total = p->n1 * 0.8 + p->n2 * 0.2;
	}

	for (p = P;p < P + N - 1;p++)
		for (q = p + 1; q < P + N;q++)
			swap(p, q);

	for (p = P;p < P + M;p++)
		printf("%s %.1lf\n", p->name, p->total);

	return 0;
}

void swap(person* p, person* q) {
	person tmp;
	if (p->total < q->total)
	{
		tmp = *p;
		*p = *q;
		*q = tmp;
	}
	else if (p->total == q->total && p->n1 < q->n1)
	{
		tmp = *p;
		*p = *q;
		*q = tmp;
	}
}