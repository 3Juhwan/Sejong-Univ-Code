#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[21];	// 관광지명
	int fee;		// 입장료
	char in_or_out;	// 야외/실내
	char date[9];	// 관광지 시작일
	char city[21];	// 도시명
}tourcity;

typedef struct {
	char name[21];
	int spot;
}city;

int main() {
	int n = 0;
	tourcity** T = NULL, * chosen = NULL;
	city* C = NULL;

	// 도시 수 입력
	scanf("%d", &n);
	getchar();

	// 동적할당
	T = (tourcity**)malloc(n * sizeof(tourcity*));		// 1번
	if (T == NULL)
	{
		printf("Not Enough Memory.");
		return -1;
	}

	C = (city*)malloc(n * sizeof(city));		// 2번
	if (C == NULL)
	{
		printf("Not Enough Memory.");
		return -1;
	}


	// 도시명 입력
	for (int i = 0; i < n; i++)
	{
		scanf("%s", C[i].name);
		getchar();
	}

	for (int i = 0;i < n;i++)
	{
		scanf("%d", &C[i].spot);
		getchar();

		T[i] = (tourcity*)malloc(C[i].spot * sizeof(tourcity));		// 3번
		if (T[i] == NULL)
		{
			printf("Not Enough Memory.");
			return -1;
		}
	}

	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < C[i].spot; j++)
		{
			scanf("%s %d %c %s", T[i][j].name, &T[i][j].fee, &T[i][j].in_or_out, T[i][j].date);
			strcpy(T[i][j].city,C[i].name);
			getchar();
		}
	}

	chosen = T[0];
	// 조건에 맞는 관광지 찾는 코드
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < C[i].spot; j++)
		{
			if (chosen->fee < T[i][j].fee)
				chosen = &T[i][j];
			else if (chosen->fee == T[i][j].fee && strcmp(chosen->date, T[i][j].date) > 0)
				chosen = &T[i][j];
		}
	}

	printf("%s %s %d %s %c", chosen->city, chosen->name, chosen->fee, chosen->date, chosen->in_or_out);

	for (int i = 0;i < n;i++)
		free(T[i]);

	free(C);
	free(T);

	return 0;
}