#pragma warning (disable:4996)
#include <stdio.h>

int main() {
	int N = 0, cnt = 0, input[50] = { 0, };
	int* p = NULL;

	scanf("%d", &N);

	for (p = input; p < input + N;p++)
	{
		scanf("%d", p);

		if (*p == 0)
			break;
		cnt++;
	}
	printf("%d", cnt);

	return 0;
}