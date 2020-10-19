#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

struct st {
	char name[10]; //학생이름
	char book[5][20]; //인증시험 본 책 이름 (예) History Politics
	int score[5]; //위 책에 대한 인증시험 점수 (예) 60 40
	int cnt, pcnt; //인증시험 본 책의 권수, 통과한 책의 권수
};

int main() {
	struct st Student[100] = { 0, }, * p = NULL;
	char tmp[20] = "";
	int N = 0, i = 0;

	scanf("%d", &N);
	getchar();

	for (p = Student; p < Student + N; p++)
	{
		i = 0;
		scanf("%s", p->name);
		getchar();

		scanf("%s", tmp);
		while (strcmp(tmp, "0"))
		{
			strcpy(p->book[i], tmp);
			scanf("%d", &p->score[i]);
			p->cnt++;

			if (p->score[i] >= 50)
				p->pcnt++;
			i++;

			scanf("%s", tmp);
		}
	}

	for (p = Student; p < Student + N; p++)
		printf("%s %d%%\n", p->name, p->pcnt * 20);


	return 0;
}