#pragma warning (disable:4996)
#include <stdio.h>

int main() {
	int arr[6] = { 0, }, overlap[3] = { 0, };
	int cnt = 0, size = 0;
	int* p = NULL, * q = NULL;

	for (p = arr; p < arr + 6;p++)
		scanf("%d", p);

	for (p = arr;p < arr + 5;p++)
	{
		for (q = arr; q < arr + 6;q++)
		{
			if (*p == *q)
				cnt++;
		}
		if (cnt > 1)
		{
			for (q = overlap; q < overlap + size; q++)
				if (*p == *q)
					break;
			if (q == overlap + size)
			{
				printf("%d %d\n", *p, cnt);
				overlap[size] = *p;
				size++;
			}
		}
		cnt = 0;
	}
	if (!size)
		printf("0\n");

	return 0;
}