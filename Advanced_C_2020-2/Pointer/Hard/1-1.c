#pragma warning (disable:4996)
#include <stdio.h>

int* MAX(int ar[]);
int* MIN(int ar[]);

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
		printf("%d %d\n", *pmax, *pmin);
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