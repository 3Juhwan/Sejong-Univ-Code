#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N = 0, cnt = 0, len = 0, i = 0, tcnt = 0;
	int* p[6] = { NULL };

	p[cnt] = (int*)malloc(5 * sizeof(int));

	if (p[cnt] == NULL)
		return -1;

	while (N != -1 && len < 20)
	{
	    
		if (len >= 5 && (len - 5) % 3 == 0)
		{
			cnt++;
			p[cnt] = (int*)malloc(3 * sizeof(int));
			if (p[cnt] == NULL)
				return -1;

			i = 0;
		}
		
		scanf("%d", &N);
		p[cnt][i] = N;
		i++;
		len++;
	}

	for (int i = 0; i < 5 && len - tcnt > 0;i++)
	{
		printf(" %d", p[0][i]);
		tcnt++;
	}

	for (int i = 1; i < cnt + 1;i++)
		for (int j = 0; j < 3 && len - tcnt > 0;j++)
		{
			printf(" %d", p[i][j]);
			tcnt++;
		}

	for (int i = 0;i < cnt;i++)
		free(p[i]);

	return 0;
}