#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

struct Student {
	char name[10];
	char number[11];
	char grade;
};

int main() {
	struct Student student[5];
	int i;
	char name[10] = "";

	for (i = 0; i < 5; i++)
	{
		scanf("%s %s %c", student[i].name, student[i].number, &student[i].grade);
		getchar();
	}

	gets_s(name, 10);

	for (i = 0; i < 5; i++)
	{
		if (strcmp(student[i].name, name) == 0)
		{
			printf(" %s %c", student[i].number, student[i].grade);
			break;
		}
	}

	return 0;
}