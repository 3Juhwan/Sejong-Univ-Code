#pragma warning (disable:4996)
#include <stdio.h>

int* MAX(int* ar);
int* MIN(int* ar);

//각 줄의 끝은 0이다. 0까지를 한 단위로 입출력했다.

int main() {
	int N = 0, arr[100] = { 0, };
	int* p = arr;

	scanf("%d", &N);

	for (int i = 0;i < N;i++, p++)
		for (;;p++) {				// while 문으로 바꿀까...?
			scanf("%d", p);
			if (!*p)break;			// break 문을 안 쓰고 처리할 순 없을까?
		}

	p = arr;

	for (int i = 0;i < N;i++) {
		printf("%d %d\n", *MAX(p), *MIN(p));
		while (*p++);							// p를 arr배열의 다음 줄로 넘김
	}

	return 0;
}

int* MAX(int* ar) {
	int* max = ar;
	while(*++ar) if (*max < *ar)max = ar;
	return max;
}

int* MIN(int* ar) {
	int* min = ar;
	while(*++ar) if (*min > * ar)min = ar;
	return min;
}