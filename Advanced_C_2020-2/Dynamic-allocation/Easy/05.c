#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N = 0, cnt1 = 0, cnt2 = 0;
	char* p = NULL, str1, str2;

	scanf("%d", &N);
	getchar();

	p = (char*)malloc((N+1) * sizeof(char));

	if (p == NULL)
		return -1;

	scanf("%s", p);
	getchar();
	scanf("%c %c", &str1, &str2);

	for (int i = 0;i < N;i++)
		if (p[i] == str1)
			cnt1++;

	for (int i = 0;i < N;i++)
		if (p[i] == str2)
			cnt2++;

	printf("%d %d", cnt1, cnt2);

	free(p);

	return 0;
}