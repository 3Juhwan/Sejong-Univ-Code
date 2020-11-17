#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char* name; // 과목 이름
	double score; // 과목 점수
}subject;

typedef struct {
	char* name; // 학생 이름
	char id[5]; // 학생 학번
	int numSubject; // 과목 개수
	subject* psub; // 과목 구조체 포인터
	double avg; // 모든 과목의 평균 점수
}student;

int main() {
	student* S = NULL, tmp = { NULL };
	int n = 0, m = 0, len = 0, wlen = 0, tcnt = 0;
	char temp[101] = "", ttmp[101] = "", * p = NULL, * q = NULL;
	char flag_sub_name[101] = "";
	int flag_idx = 0;
	double flag_sub_score = 0;

	scanf("%d", &n);
	getchar();

	S = (student*)malloc(n * sizeof(student));		//
	if (S == NULL)
		return -1;
	for (int i = 0; i < n;i++)
	{
		S[i].numSubject = 0;
		S[i].avg = 0.0;
	}

	for (int i = 0;i < n;i++)
	{
		gets(temp);
		wlen = strlen(temp);

		// 공백 단위로 끊기
		p = temp;
		while (*p)
		{
			if (*p == ' ')
				*p = '\0';
			p++;
		}

		// 학생 이름
		p = temp;
		len = strlen(p);
		S[i].name = (char*)malloc((len + 1) * sizeof(student));		//
		if (S[i].name == NULL)
			return -1;

		strcpy(S[i].name, p);
		p += len + 1;

		// 학생 id
		strcpy(S[i].id, p);
		p += 5;

		// 과목 개수
		q = p;
		while (q < temp + wlen)
		{
			S[i].numSubject++;
			q += strlen(q) + 1;
			q += strlen(q) + 1;
		}

		S[i].psub = (subject*)malloc(S[i].numSubject * sizeof(subject));	//
		if (S[i].psub == NULL)
			return -1;

		tcnt = 0;
		while (p < temp + wlen)
		{
			len = strlen(p);

			S[i].psub[tcnt].name = (char*)malloc((len + 1) * sizeof(char));		//
			if (S[i].psub[tcnt].name == NULL)
				return -1;

			// 과목 이름
			strcpy(S[i].psub[tcnt].name, p);
			p += len + 1;

			S[i].psub[tcnt].score = atof(p);
			p += strlen(p) + 1;
			tcnt++;
		}

		for (int j = 0; j < S[i].numSubject; j++)
			S[i].avg += (double)S[i].psub[j].score;

		S[i].avg /= (double)S[i].numSubject;
	}

	for (int i = 0;i < n - 1;i++)
	{
		for (int j = 0;j < n - i - 1;j++)
		{
			if (S[j].avg < S[j + 1].avg)
			{
				tmp = S[j];
				S[j] = S[j + 1];
				S[j + 1] = tmp;
			}
			if (S[j].avg == S[j + 1].avg && strcmp(S[j].id ,S[j + 1].id) > 0)
			{
				tmp = S[j];
				S[j] = S[j + 1];
				S[j + 1] = tmp;
			}
		}
	}

	scanf("%d", &m);

	for (int i = 0;i < S[m - 1].numSubject;i++)
	{
		if (flag_sub_score < S[m - 1].psub[i].score)
		{
			flag_sub_score = S[m - 1].psub[i].score;
			flag_idx = i;
		}
	}
	strcpy(flag_sub_name, S[m - 1].psub[flag_idx].name);

	printf("%s %s %.2lf %s %.2lf\n", S[m - 1].name, S[m - 1].id, S[m - 1].avg, flag_sub_name,flag_sub_score);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < S[i].numSubject;j++)
			free(S[i].psub[j].name);
		free(S[i].psub);
		free(S[i].name);
	}

	free(S);

	return 0;
}