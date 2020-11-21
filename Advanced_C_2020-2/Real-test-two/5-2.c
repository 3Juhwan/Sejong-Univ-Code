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

int check_dup(ABC job1, ABC job2, ABC job3);
char* get_start_end(ABC job1, ABC job2, ABC job3);

int main() {
	int N = 0, len = 0, fflag = 0, tmp = 0, t_tmp = 0;
	int max = 0;
	char temp[101] = "", * max_J = NULL;
	ABC* J = NULL, * flag = NULL;
	ABC AA, BB, CC;

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
		if (J[i].name == NULL) {
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

		J[i].end = (char*)malloc(9 * sizeof(char));
		if (J[i].end == NULL) {
			printf("Not enough memory");
			return -1;
		}
		scanf("%s", J[i].end);

		scanf("%d", &J[i].money);
		getchar();
	}

	for (int i = 0; i < N;i++)
	{
		for (int j = i + 1; j < N;j++)
		{
			for (int k = j + 1; k < N;k++)
			{
				tmp = check_dup(J[i], J[j], J[k]);

				if (tmp)
				{
					t_tmp = J[i].money + J[j].money + J[k].money;
					if (t_tmp > max)
					{
						AA = J[i];
						BB = J[j];
						CC = J[k];
						max = t_tmp;
						max_J = get_start_end(J[i], J[j], J[k]);
						fflag++;
					}
				}
			}
		}
	}

	// flag
	if (fflag)
	{
		printf("%s %s %s\n", AA.name, BB.name, CC.name);
		printf("%d\n", max);
		printf("%s", max_J);
	}
	else
		printf("NONE");

	printf("%s %s %s %d", flag->name, flag->start, flag->end, flag->money);

	// free
	for (int i = 0; i < N; i++)
	{
		free(J[i].name);
		free(J[i].start);
		free(J[i].end);
	}
	free(J);

	// free 해주기

	return 0;
}

int check_dup(ABC job1, ABC job2, ABC job3) {
	if (strcmp(job1.end, job2.start) < 0 && strcmp(job2.end, job3.start) < 0)
		return 1;
	if (strcmp(job1.end, job3.start) < 0 && strcmp(job3.end, job2.start) < 0)
		return 1;
	if (strcmp(job2.end, job1.start) < 0 && strcmp(job1.end, job3.start) < 0)
		return 1;
	if (strcmp(job2.end, job3.start) < 0 && strcmp(job3.end, job1.start) < 0)
		return 1;
	if (strcmp(job3.end, job1.start) < 0 && strcmp(job1.end, job2.start) < 0)
		return 1;
	if (strcmp(job3.end, job2.start) < 0 && strcmp(job2.end, job1.start) < 0)
		return 1;
	return 0;
}

char* get_start_end(ABC job1, ABC job2, ABC job3) {
	char* time = NULL; 

	time = (char*)malloc(17 * sizeof(char));
	if(time ==NULL) {
		printf("Not enough memory");
		return -1;
	}

	if (strcmp(job1.start, job2.start) < 0 && strcmp(job1.start, job3.start) < 0)
		strcpy(time, job1.start);
	else if (strcmp(job2.start, job1.start) < 0 && strcmp(job2.start, job3.start) < 0)
		strcpy(time, job2.start);
	else if (strcmp(job3.start, job1.start) < 0 && strcmp(job3.start, job2.start) < 0)
		strcpy(time, job3.start);

	strcat(time, " ");

	if (strcmp(job1.end, job2.end) > 0 && strcmp(job1.end, job3.end) > 0)
		strcat(time, job1.end);
	else if (strcmp(job2.end, job1.end) > 0 && strcmp(job2.end, job3.end) > 0)
		strcat(time, job2.end);
	else if (strcmp(job3.end, job1.end) > 0 && strcmp(job3.end, job2.end) > 0)
		strcat(time, job3.end);

	return time;
}


/*
4
Remove 09:45:00 13:00:00 50
Cleaning 08:27:45 10:00:00 50
Painting 13:00:15 18:00:00 100
Checking 15:00:00 18:00:00 10

4
BasicPaint 09:45:00 10:30:00 10
Drawing 08:27:45 13:10:00 20
Paint 11:00:00 14:00:00 40
Remove 14:00:15 16:00:00 30

7
BasicPaint 09:45:00 10:30:00 50
Drawing 08:27:45 13:10:00 50
Paint 09:27:45 10:00:00 50
Remove 13:00:15 14:00:00 100
Cleaning 13:00:15 18:00:00 100
Finish1 15:00:00 16:00:00 10
Waste 16:00:00 18:00:00 30

4
BasicPaint 09:45:00 16:30:00 50
Drawing 10:33:45 16:10:00 50
Paint 13:27:45 16:10:00 50
Remove 13:00:15 16:10:00 100
*/