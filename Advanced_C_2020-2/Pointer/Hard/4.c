#pragma warning (disable:4996)
#include <stdio.h>

int main() {
	int arr1[11] = { 0, }, arr2[11] = { 0, };
	int* p = arr1, * q = arr2;
	int n = 0, m = 0, tmp = 0;

	scanf("%d", p);
	while (*p)
	{
		p++;
		n++;
		scanf("%d", p);
	}

	scanf("%d", q);
	while (*q)
	{
		q++;
		m++;
		scanf("%d", q);
	}
	
	for (p = arr1; p < arr1 + n; p++)
	{
		for (q = arr2; q < arr2 + m; q++)
		{
			if (*p < *q)
			{
				tmp = *p; 
				*p = *q;
				*q = tmp;
			}
		}
	}

	// 정렬
	for (p = arr1; p < arr1 + n - 1; p++)
	{
		for (q = p + 1; q < arr1 + n; q++)
		{
			if (*p < *q)
			{
				tmp = *p;
				*p = *q;
				*q = tmp;
			}
		}
	}

	for (p = arr2; p < arr2 + m - 1; p++)
	{
		for (q = p + 1; q < arr2 + m; q++)
		{
			if (*p > *q)
			{
				tmp = *p;
				*p = *q;
				*q = tmp;
			}
		}
	}
	
	for (p = arr1; p < arr1 + n; p++)
		printf("%d ", *p);
	printf("\n");
	for (p = arr2; p < arr2 + m; p++)
		printf("%d ", *p);


	return 0;
}