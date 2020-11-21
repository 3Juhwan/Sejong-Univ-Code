#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_u(char* p, char* q);

int main() {
	int N = 0, M1 = 0, M2 = 0;
	int cnt = 0, min = 101;
	char arr[101] = "", output[101]="";

	scanf("%d", &N);
	scanf("%d %d", &M1, &M2);
	getchar();

	for (int i = 0;i < N;i++)
	{
		gets(arr);
		cnt = check_u(arr + M1, arr + M2);
		if (!cnt)
			continue;

		if (min > cnt) {
			min = cnt;
			strcpy(output, arr);
		}
		else if (min == cnt && strlen(output) <= strlen(arr)) {
			strcpy(output, arr);
		}
	}

	printf("%s", output);

	return 0;
}

int check_u(char* p, char* q) {
	char* a = p;
	int cnt = 0;

	for (a = p; a <= q && *a; a++)
		if (*a >= 'A' && *a <= 'Z')
			cnt++;

	return cnt;
}