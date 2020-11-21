#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct job {
	char* name; // 작업명 (공백 없이 최대 100자)
	char* start; // 작업 시작 시간 (HH:MM:SS; 24시간제 시간,분,초 예)15:32:35)
	char* end; // 작업 종료 시간 (위와 동일)
	int money; // 작업 대금 (수익)
}ABC;

int main() {
	int N = 0, len = 0 ;
	char temp[101] = "";
	ABC* J = NULL, *flag = NULL;

	scanf("%d", &N);
	getchar();

	J = (ABC*)malloc(N * sizeof(ABC));
	if (J == NULL) {
		printf("Not enough memory");
		return -1;
	}

	// input
	for (int i = 0; i < N; i++)
	{
		scanf("%s", temp);
		getchar();

		// name
		len = strlen(temp);
		J[i].name = (char*)malloc((len + 1) * sizeof(char));
		if(J[i].name == NULL) {
			printf("Not enough memory");
			return -1;
		}
		strcpy(J[i].name, temp);

		J[i].start = (char*)malloc(9 * sizeof(char));
		if (J[i].start == NULL) {
			printf("Not enough memory");
			return -1;
		}
		scanf("%s", J[i].start);
		getchar();

		J[i].end= (char*)malloc(9 * sizeof(char));
		if (J[i].end== NULL) {
			printf("Not enough memory");
			return -1;
		}
		scanf("%s", J[i].end);

		scanf("%d", &J[i].money);
		getchar();
	}

	flag = J;
	for (int i = 0; i < N;i++)
	{
		if (strcmp(flag->start, J[i].start) > 0)
			flag = &J[i];
	}

	printf("%s %s %s %d", flag->name, flag->start, flag->end, flag->money);

	// free
	for (int i = 0; i < N; i++)
	{
		free(J[i].name);
		free(J[i].start);
		free(J[i].end);
	}
	free(J);

	return 0;
}