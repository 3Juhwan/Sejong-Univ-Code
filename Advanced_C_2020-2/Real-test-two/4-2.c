#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num_of_divisors(int M, int* arr);
int cal_sum(int* onearr, int size);

int main() {
	int N = 0, M = 0, K = 0, sum = 0, fine = 0;
	int** darr, * num, temp[20];

	scanf("%d", &N);

	darr = (int**)malloc(N * sizeof(int*));
	if (darr == NULL) {
		printf("not enough memory");
		return -1;
	}

	num = (int*)malloc(N * sizeof(int));
	if (num == NULL) {
		printf("not enough memory");
		return -1;
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &M);
		num[i] = num_of_divisors(M, temp);

		if (num[i] != -1) {
			darr[i] = (int*)malloc(num[i] * sizeof(int));
			if (darr[i] == NULL) {
				printf("not enough memory");
				return -1;
			}
			for (int j = 0; j < num[i];j++)
				darr[i][j] = temp[j];
		}
	}

	scanf("%d", &K);

	if (num[K] == -1)
		printf("-1");
	else
		for (int i = num[K] - 1; i >= 0;i--)
		printf("%d ", darr[K][i]);
	printf("\n");

	for (int i = 0; i < N; i++)
	{
		if (num[i] != -1)
		{
			sum = cal_sum(darr[i], num[i]);

			if (sum > fine) {
				fine = sum;
			}
		}
	}

	printf("%d\n", fine);

	for (int i = 0; i < N; i++)
		free(darr[i]);
	free(num);
	free(darr);

	return 0;
}

int num_of_divisors(int M, int* arr) {
	int cnt = 0, size = 0;

	for (int i = 1;i <= M;i++)
	{
		if (M % i == 0)
		{
			arr[size] = i;
			size++;
		}
		if (size > 20)
			return -1;
	}
	return size;
}

int cal_sum(int* onearr, int size) {
	int* p = onearr, sum = 0;

	for (p = onearr; p < onearr + size; p++)
		sum += *p;

	return sum;
}