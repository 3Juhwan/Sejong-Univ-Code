#pragma warning (disable:4996)
#include <stdio.h>

int main() {
	int n = 0, m = 0;						// 입력 개수 카운트하는 변수
	int a[10] = { 0, }, b[10] = { 0, };
	int* p = NULL, * q = NULL;				// q 없어도 될 것 같은데
	
	for (p = a; *(p - 1) || p == a;p++)		// 조건식 p == a 일때 에러 발생할 수도 있어서 p == a 라는 조건을 추가해줬다.
	{
		scanf("%d", p);
		n++;
	}
	n--;	// 0이 입력되는 것도 카운트 되었기 때문에 1을 빼준다

	for (q = b; *(q - 1) || q == b;q++)
	{
		scanf("%d", q);
		m++;
	}
	m--;	// 0이 입력되는 것도 카운트 되었기 때문에 1을 빼준다

	// 배열a와 b의 큰 숫자부터 내림차순으로 배열 a에 저장한다.

	for (p = a; p < a + n;p++)
	{
		for (q = p + 1; q < a + n; q++)
		{
			if (*p < *q)
			{
				int tmp = *p;
				*p = *q; 
				*q = tmp;
			}
		}
		for (q = b; q < b + m; q++)
		{
			if (*p < *q)
			{
				int tmp = *p;
				*p = *q;
				*q = tmp;
			}
		}
	}

	// 이제 배열 b에는 작은 숫자들만 남아 있다.

	for (p = b; p < b + m;p++)
	{
		for (q = p + 1; q < b + m; q++)
		{
			if (*p > *q)
			{
				int tmp = *p;
				*p = *q;
				*q = tmp;
			}
		}
	}

	// 출력

	for (p = a; p < a + n;p++)
	{
		printf("%d ", *p);
	}

	printf("\n");
	
	for (p = b; p < b + m;p++)
	{
		printf("%d ", *p);
	}

	return 0;
}