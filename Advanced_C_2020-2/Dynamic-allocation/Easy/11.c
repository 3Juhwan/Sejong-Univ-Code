#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int* p = NULL, q[20] = { 0 };
	int N = 0, cnt = 0;

	p = (int*)malloc(5 * sizeof(int));
	if (p == NULL)
		return -1;

	scanf("%d", &p[cnt]);
	while (p[cnt] != -1 && cnt < 20)
	{
		cnt++;

		if (cnt >= 5 && (cnt - 5) % 3 == 0)
		{
			for (int i = 0; i < cnt;i++)
				q[i] = p[i];

			free(p);

			p = (int*)malloc((cnt + 3) * sizeof(int));
			if (p == NULL)
				return -1;

			for (int i = 0; i < cnt;i++)
				p[i] = q[i];
		}

		scanf("%d", &p[cnt]);
	}
	cnt++;

	for (int i = 0; i < cnt;i++)
		printf(" %d", p[i]);

	free(p);

	return 0;
}