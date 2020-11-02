#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N = 0, cnt = 0;
	char* p = NULL;

	scanf("%d", &N);

	p = (char*)malloc((N + 1) * sizeof(char));

	if (p == NULL)
		return -1;

	scanf("%s", p);
	getchar();

	for (int i = 0;i < N - 2; i++)
		if (strncmp(&p[i], "cat", 3) == 0)
			cnt++;

	printf("%d", cnt);

	free(p);

	return 0;
}