#pragma warning (disable:4996)
#include <stdio.h>

int* mid(int arr[]);

int main() {
	int midnum = 0, arr[3] = { 0, };
	int* p = NULL;
	
	for (p = arr; p < arr + 3; p++)
		scanf("%d", p);

	p = mid(arr);

	printf("%d", *p);

	return 0;
}

int* mid(int arr[]) {
	if ((*arr - *(arr + 1)) * (*arr - *(arr + 2)) <= 0) 
		return arr;
	else if ((*(arr + 1) - *(arr + 2)) * (*(arr + 1) - *arr) <= 0) 
		return arr + 1;
	else 
		return arr + 2;
}