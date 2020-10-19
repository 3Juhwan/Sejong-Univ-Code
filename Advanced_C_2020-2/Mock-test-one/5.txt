#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

struct st {
	char major[51];
	int stNum;
};

int main() {
	struct st Student[100] = { '\0' }, tmp = { '\0',0 };
	int N = 0;

	scanf("%d", &N);
	getchar();

	for (int i = 0; i < N; i++)
	{
		gets_s(Student[i].major, 51);
		scanf("%d", &Student[i].stNum);
		getchar();
		for (int j = 0; j < i; j++)
		{
			if (strcmp(Student[i].major, Student[j].major) < 0)
			{
				tmp = Student[i];
				Student[i] = Student[j];
				Student[j] = tmp;
			}
			if (strcmp(Student[i].major, Student[j].major) == 0)
			{
				if (Student[i].stNum < Student[j].stNum)
				{
					tmp = Student[i];
					Student[i] = Student[j];
					Student[j] = tmp;
				}
			}

		}
	}

	for (int i = 0; i < N; i++)
		printf("%s %d\n", Student[i].major, Student[i].stNum);

	return 0;
}