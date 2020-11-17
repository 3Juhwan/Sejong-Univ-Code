#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct subject {
	char* name; // 과목 이름
	double score; // 과목 점수
}subject;

typedef struct student {
	char* name;		// 학생 이름
	char id[5];		// 학생 학번
	int numSubject;	// 과목 개수
	subject* psub;	// 과목 구조체 포인터
	double avg;		// 모든 과목의 평균 점수
	//char* subjectName; // 과목 이름
	//double subjectScore; // 과목 점수
}student;

int main() {
	int N = 0, K = 0, len = 0;
	int cnt = 0;
	double total = 0.0;
	char temp[101] = "", * p = NULL, * q = NULL;
	student* S = NULL, tmp = { "" };
	subject Top = { "",0.0 };

	scanf("%d", &N);
	getchar();

	S = (student*)malloc(N * sizeof(student));
	if (S == NULL) {
		printf("Not enough Memory");
		return -1;
	}

	for (int i = 0;i < N;i++)
	{
		gets_s(temp, 101);
		len = strlen(temp);

		for (int j = 0; j < len; j++)
		{
			if (temp[j] == ' ')
				temp[j] = '\0';
		}

		// 학생 이름
		p = temp;
		S[i].name = (char*)malloc((strlen(p) + 1) * sizeof(char));
		if (S[i].name == NULL) {
			printf("Not enough Memory");
			return -1;
		}

		strcpy(S[i].name, p);
		p += strlen(p) + 1;

		// 학생 학번
		strcpy(S[i].id, p);
		p += strlen(p) + 1;

		// 과목 개수 카운트
		q = p;
		cnt = 0;
		while (q <= temp + len)
		{

			cnt++;
			q += strlen(q) + 1;
		}
		cnt /= 2;
		S[i].numSubject = cnt;

		S[i].psub = (subject*)malloc(cnt * sizeof(subject));
		if (S[i].psub == NULL) {
			printf("Not enough Memory");
			return -1;
		}

		total = 0;
		for (int j = 0; j < cnt;j++)
		{
			S[i].psub[j].name = (char*)malloc((strlen(p) + 1) * sizeof(char));
			if (S[i].psub[j].name == NULL) {
				printf("Not enough Memory");
				return -1;
			}

			strcpy(S[i].psub[j].name, p);
			p += strlen(p) + 1;

			S[i].psub[j].score = atof(p);
			p += strlen(p) + 1;

			total += S[i].psub[j].score;
		}

		S[i].avg = total / S[i].numSubject;
	}

	for (int i = 0;i < N - 1;i++)
	{
		for (int j = 0;j < N - i - 1;j++)
		{
			if (strcmp(S[j].id, S[j + 1].id) > 0)
			{
				tmp = S[j];
				S[j] = S[j + 1];
				S[j + 1] = tmp;
			}
		}
	}
	for (int i = 0;i < N - 1;i++)
	{
		for (int j = 0;j < N - i - 1;j++)
		{
			if (S[j].avg < S[j + 1].avg)
			{
				tmp = S[j];
				S[j] = S[j + 1];
				S[j + 1] = tmp;
			}
		}
	}

	scanf("%d", &K);

	Top = S[K - 1].psub[0];

	for (int i = 1; i < S[K - 1].numSubject;i++)
	{
		if (Top.score < S[K - 1].psub[i].score)
		{
			Top = S[K - 1].psub[i];
		}
	}

	printf("%s %s %.2lf %s %.2lf", S[K - 1].name, S[K - 1].id, S[K - 1].avg, Top.name, Top.score);

	for (int i = 0; i < N;i++)
	{
		for (int j = 0; j < S[i].numSubject;j++)
			free(S[i].psub[j].name);
		free(S[i].psub);
		free(S[i].name);
	}

	free(S);

	return 0;
}