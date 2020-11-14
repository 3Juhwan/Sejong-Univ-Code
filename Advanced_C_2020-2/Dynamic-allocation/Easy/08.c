#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int N = 0, cnt = 0, t_cnt = 0;
	char* p = NULL, * cat = "cat";

	scanf("%d", &N);
	getchar();

	p = (char*)malloc(N * sizeof(char));
	if (p == NULL)
		return -1;

	for (int i = 0; i < N;i++)
		scanf("%c", &p[i]);

	for (int i = 0; i < N - 2;i++)
	{
		for (int j = 0; j < 3; j++)
			if (p[i + j] == cat[j])
				t_cnt++;
		if (t_cnt == 3)
			cnt++;
		t_cnt = 0;
	}

	printf("%d\n", cnt);

	if (p != NULL)
		free(p);

	return 0;
}