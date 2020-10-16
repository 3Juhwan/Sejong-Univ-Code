#pragma warning (disable:4996)
#include <stdio.h>

int correct(int arr[]);
int newnum(int arr[]);

int main() {
	int arr[6] = { 0, }, overlap[3] = { 0, };
	int flag = 0;
	int* p = NULL;

	for (p = arr; p < arr + 6;p++)
		scanf("%d", p);

	flag = correct(arr);

	printf("%d\n", flag);
	for (p = arr; p < arr + 6;p++)
		printf("%d ", *p);

	return 0;
}

int correct(int arr[]) {
	int flag = 0;

	for (int* p = arr; p < arr + 5;p++)
	{
		for (int* q = p + 1; q < arr + 6;q++)
		{
			if (*p == *q)
			{
				*p = newnum(arr);
				flag++;
				break;
			}
		}
	}
	if (flag)
		return 1;
	return 0;
}

int newnum(int arr[]) {
	int S = 1;

	for (int i = 0;i < 6; i++)
		for (int* p = arr; p < arr + 6;p++)
			if (S == *p)
			{
				S++;
				break;
			}
	return S;
}