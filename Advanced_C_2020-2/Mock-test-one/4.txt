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
	struct st Student[100] = { '\0' };
	char discard[20] = "";
	int N = 0, size = 0;

	scanf("%d", &N);
	getchar();

	for (int i = 0; i < N; i++)
	{
		scanf("%s", Student[i].name);
		while (size < 6)
		{
			if (size < 5) {
				scanf("%s", Student[i].book[size]);
				if (strcmp(Student[i].book[size], "0") == 0)
					break;
				
				scanf("%d", &Student[i].score[size]);
				if (Student[i].score[size] >= 50)
					Student[i].pcnt++;

				size++;
			}
			else {
				scanf("%s", discard);
				size++;
			}
		}
		if (size >= 6) size--;

		Student[i].cnt = size;
		size = 0;
	}

	for (int i = 0; i < N; i++)
		printf("%s %d%%\n", Student[i].name, (Student[i].pcnt * 20));

	return 0;
}