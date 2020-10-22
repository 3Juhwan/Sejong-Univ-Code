#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int input(int* p);
int* sel_next(int* p);
int number(int* p, int* q);

int main() {
	int x[100] = { 0 }, num = 0;
	int* p = x, * S = x, * E = x;
	int result = 0;

	num = input(x);

	while (E < x + num - 1) {
		S = E;
		E = sel_next(S);
		result = number(S, E);
		printf("%d\n", result);
	}

	return 0;
}

int input(int* p) {
	int* q = p;
	int cnt = 0;

	scanf("%d", q);

	while (*q != -1)
	{
		cnt++;
		q++;
		scanf("%d", q);
	}

	return cnt;
}

int* sel_next(int* p) {
	int* q = p;
	int flag = 0;

	if (*q - *(q + 1) > 0)	// 감소
		flag = 0;
	else
		flag = 1;			// 증가

	if (flag == 1)
	{
		while (*q - *(q + 1) < 0)
			q++;

		return q;
	}

	else if (flag == 0)
	{
		while (*q - *(q + 1) > 0)
			q++;

		return q;
	}
}



int number(int* p, int* q) {
	int num = 0;
	int* i = p;

	for (i = p; i <= q; i++)
	{
		if (*i == -1)
			break;

		num = num * 10 + *i;
	}

	return num;
}