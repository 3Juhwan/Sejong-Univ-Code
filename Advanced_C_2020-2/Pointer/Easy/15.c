#pragma warning (disable:4996)
#include <stdio.h>

void ABC(int arr[], int N);

int main() {
	int arr[10] = { 0, }, *p = arr;

	for(p = arr; p < arr + 10; p++)
		scanf("%d", p);

	for (p = arr; p < arr + 9;p++)
		ABC(p, arr + 10 - p);

	for (p = arr; p < arr + 10; p++)
		printf(" %d", *p);

	return 0;
}

void ABC(int arr[], int N) {
	int tmp = 0;
	for (int* p = arr + 1; p < arr + N; p++)
	{
		if (*arr < *p)
		{
			tmp = *p;
			*p = *arr;
			*arr = tmp;
		}
	}
}