#pragma warning (disable:4996)
#include <stdio.h>

int arrsum(int* S, int* E);

int main() {
	int N = 0, S = 0, E = 0, sum = 0;
	int arr[100] = { 0, }, * p = NULL;

	scanf("%d %d %d", &N, &S, &E);

	for (p = arr; p < arr + N; p++)
		scanf("%d", p);

	sum = arrsum(arr + S, arr + E);

	printf("%d", sum);

	return 0;
}

int arrsum(int* S, int* E) {
	int sum = 0;
	while (S <= E)
	{
		sum += *S;
		S++;
	}
	return sum;
}