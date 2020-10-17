#pragma warning (disable:4996)
#include <stdio.h>

struct Info {
	int N;
	int rank;
};

int main() {
	struct Info I[10] = { 0};
	
	for (int i = 0;i < 10;i++)
		scanf("%d", &I[i].N);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0;j < 10;j++)
		{
			if (I[i].N <= I[j].N)
				I[i].rank++;
		}
	}

	for (int i = 0;i < 10;i++)
	{
		if (I[i].rank == 3)
			printf("%d", I[i].N);
	}
	for (int i = 0;i < 10;i++)
	{
		if (I[i].rank == 7)
			printf(" %d", I[i].N);
	}

	return 0;
}