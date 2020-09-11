#pragma warning (disable:4996)
#include <stdio.h>

int isOverlap(int* p, int arr[]);

int main() {
	int arr[6] = { 0, }, overlap[3] = { 0, };		// 배열 overlap에 중복되는 숫자 저장
	int* p = NULL, * q = NULL;
	int none = 0;									// 중복된 숫자가 없는 경우

	for (p = arr; p < arr + 6; p++)
	{
		scanf("%d", p);
	}

	for (p = arr; p < arr + 6; p++)
	{
		// 중복 검사
		if (isOverlap(p, overlap))
		{
			continue;
		}


		int cnt = 0;
		for (q = p; q < arr + 6; q++)
		{
			if (*p == *q)
			{
				cnt++;
			}
		}

		if (cnt - 1)
		{
			none++;							// 중복된 숫자가 있음을 카운트

			printf("%d %d\n", *p, cnt);

			// overlap 배열에 넣기
			for (q = overlap; *q;q++);
			*q = *p;
		}
	}

	if (!none)
	{
		printf("0");
	}

	return 0;
}

int isOverlap(int* p, int arr[]) {
	for (int* q = arr; q < arr + 3;q++)
	{
		if (*q == *p)
		{
			return 1;
		}
	}
	return 0;
}