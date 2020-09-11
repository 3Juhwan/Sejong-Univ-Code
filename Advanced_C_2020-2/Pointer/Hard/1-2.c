#pragma warning (disable:4996)
#include <stdio.h>

int* MAX(int ar[]);
int* MIN(int ar[]);

//각 줄의 끝은 0이다. 0까지를 한 단위로 입출력했다.

int main() {
	int N = 0, arr[100] = { 0, };
	int* p = arr;

	scanf("%d", &N);

	for (int i = 0;i < N;i++)
	{
		do {
			scanf("%d", p++);
		} while (*(p - 1));
	}

	p = arr;

	for (int i = 0;i < N;i++) {
		int* begin = MAX(p), * end = MIN(p), * tmp = NULL;

		if (begin > end)	// 시작주소를 begin으로 끝주소를 end로 초기화 
		{
			tmp = begin;
			begin = end;
			end = tmp;
		}

		if ((end - begin) <= 1)		// 예외 처리
		{
			printf("none");	
		}

		else	// 일반 처리
		{
			for (p = begin + 1;p < end;p++)
			{
				printf("%d ", *p);	
			}
		}
		printf("\n");

		while (*p++);							// p를 arr배열의 다음 줄로 넘김
	}

	return 0;
}

int* MAX(int ar[]) {
	int* max = ar;

	while (*++ar)
	{
		if (*max < *ar)
		{
			max = ar;
		}
	}
	return max;
}

int* MIN(int ar[]) {
	int* min = ar;

	while (*++ar)
	{
		if (*min > * ar)
		{
			min = ar;
		}
	}
	return min;
}