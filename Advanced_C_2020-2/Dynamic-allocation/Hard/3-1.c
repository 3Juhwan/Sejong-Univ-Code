#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char* studentName; // 학생 이름
	char id[5]; // 학생 학번
	char* subjectName; // 과목 이름
	double subjectScore; // 과목 점수
}student;

int main() {
	int n = 0, m = 0,len = 0;
	char temp[101] = "", * p = NULL;
	student* S = NULL, tmp = { NULL };

	scanf("%d", &n);
	getchar();

	S = (student*)malloc(n * sizeof(student));
	if (S == NULL)
		return -1;

	for (int i = 0;i < n;i++)
	{
		gets(temp);

		p = temp;
		while (*p)
		{
			if (*p == ' ')
				*p = '\0';
			p++;
		}

		p = temp;

		len = strlen(p);
		S[i].studentName = (char*)malloc((len + 1) * sizeof(student));
		if (S[i].studentName == NULL)
			return -1;

		strcpy(S[i].studentName, p);
		p += len + 1;

		strcpy(S[i].id, p);
		p += 5;
		
		len = strlen(p);
		S[i].subjectName = (char*)malloc((len + 1) * sizeof(student));
		if (S[i].subjectName == NULL)
			return -1;

		strcpy(S[i].subjectName, p);
		p += len + 1;

		S[i].subjectScore = atof(p);
	}

	for (int i = 0;i < n - 1;i++)
	{
		for (int j = 0;j < n - i - 1;j++)
		{
			if (S[j].subjectScore < S[j + 1].subjectScore)
			{
				tmp = S[j];
				S[j] = S[j + 1];
				S[j + 1] = tmp;
			}
		}
	}

	scanf("%d", &m);

	printf("%s %s %s %.2lf\n", S[m - 1].studentName, S[m - 1].id, S[m - 1].subjectName, S[m - 1].subjectScore);

	for (int i = 0; i < n;i++)
	{
		free(S[i].studentName);
		free(S[i].subjectName);
	}

	free(S);

	return 0;
}