#include<stdio.h>

int main(){
	int M1 = 0, M2 = 0, N1 = 0, N2 = 0;
	scanf("%d %d", &M1, &M2);
	scanf("%d %d", &N1, &N2);

	for (int i = N1; i <= N2; i++)
	{
		for (int j = M1; j <= M2;j++)
			printf(" %d", i * j);
		printf("\n");
	}

	return 0;
}