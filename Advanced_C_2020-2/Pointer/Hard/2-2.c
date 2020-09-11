#pragma warning (disable:4996)
#include <stdio.h>

int correct(int* arr);
int upper(int* arr);

int main() {
	int arr[6] = { 0, };		// 배열 overlap에 중복되는 숫자 저장
	int* p = NULL;

	for (p = arr; p < arr + 6; p++)
	{
		scanf("%d", p);
	}

	printf("%d\n", correct(arr));

	for (p = arr;p < arr + 6;p++)
	{
		printf("%d ", *p);
	}

	return 0;
}

int correct(int* arr) {
	int* p = NULL, * q = NULL;
	int isSame = 0;

	for (p = arr; p < arr + 6; p++)
	{
		for (q = p + 1; q < arr + 6; q++)
		{
			if (*p == *q)
			{
				*p = upper(arr);
				isSame = 1;
			}
		}
	}
	
	if (isSame) return 1;
	return 0;
}

int upper(int* arr) {
	int i = 1, *p = NULL;

	for (i = 1; i < 46;i++)
	{
		p = arr;
		while (p < arr + 6 && *p != i)
		{
			p++;
		}

		if (p == arr + 6)
		{
			return i;
		}
	}

	return 0;
}