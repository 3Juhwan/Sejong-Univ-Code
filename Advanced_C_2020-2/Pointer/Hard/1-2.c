#pragma warning (disable:4996)
#include <stdio.h>

int* MAX(int ar[]);
int* MIN(int ar[]);
void printMid(int* p, int* q);

int main() {
	int arr[100] = { 0, };
	int N = 0, * p = arr, * pmax = NULL, * pmin = NULL;

	scanf("%d", &N);
	for (int i = 0;i < N;i++)
	{
		p = arr;
		scanf("%d", p);
		while(*p)
		{
			p++;
			scanf("%d", p);
		}
		pmax = MAX(arr);
		pmin = MIN(arr);
		printMid(pmax, pmin);
	}

	return 0;
}

int* MAX(int ar[]) {
	int* pmax = ar;
	while (*ar)
	{
		if (*ar > * pmax)
			pmax = ar;
		ar++;
	}
	return pmax;
}

int* MIN(int ar[]) {
	int* pmin = ar;
	while (*ar)
	{
		if (*ar < *pmin)
			pmin = ar;
		ar++;
	}
	return pmin;
}

void printMid(int* p, int* q) {
	int* tmp = NULL, cnt = 0;

	if (p > q)
	{
		tmp = p;
		p = q;
		q = tmp;
	}

	for (tmp = p + 1; tmp < q; tmp++)
	{
		printf("%d ", *tmp);
		cnt++;
	}
	if (!cnt)
		printf("none");
	printf("\n");
}