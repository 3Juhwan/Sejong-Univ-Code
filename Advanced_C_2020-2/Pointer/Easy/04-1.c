#pragma warning (disable:4996)
#include <stdio.h>

int main() {
	int arr[3] = { 0, }, tmp = 0;
	int* p = NULL, *q = NULL;

	for (p = arr;p < arr + 3;p++)
		scanf("%d", p);
	
	for (p = arr; p < arr + 2; p++)
	{
		for (q = p + 1; q < arr + 3; q++)
		{
			if (*p > * q)
			{
				tmp = *p;
				*p = *q;
				*q = tmp;
			}
		}
	}

	printf("%d", arr[1]);

	return 0;
}