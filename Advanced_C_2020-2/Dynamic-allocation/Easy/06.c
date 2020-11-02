#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[8];
	int kor;
	int eng;
	int mat;
	double avg;
}student;

int main() {
	int N = 0;
	student* p = NULL;

	scanf("%d", &N);
	getchar();

	p = (student*)malloc(N * sizeof(student));

	if (p == NULL)
		return -1;

	for (int i = 0;i < N;i++)
	{
		scanf("%s %d %d %d", p[i].name, &p[i].kor, &p[i].eng, &p[i].mat);
		getchar();
		p[i].avg = (p[i].kor + p[i].eng + p[i].mat) / 3.0;
	}

	for (int i = 0; i < N;i++)
	{
		printf("%s %.1lf ", p[i].name, p[i].avg);
		
		if (p[i].kor >= 90 || p[i].mat >= 90 || p[i].eng >= 90)
			printf("GREAT ");
		if (p[i].kor < 70|| p[i].mat < 70 || p[i].eng < 70)
			printf("BAD ");

		printf("\n");
	}

	free(p);

	return 0;
}