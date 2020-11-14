#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[10];
	char stNum[11];
	char grade;
}STUDENT;

int main() {
	STUDENT S[5] = { "" }, * p_input = NULL;
	char input[10] = "";
	int flag = 0;

	for (int i = 0; i < 5; i++)
	{
		scanf("%s %s %c", S[i].name, S[i].stNum, &S[i].grade);
		getchar();
	}

	gets_s(input,10);

	for (int i = 0; i < 5;i++)
	{
		if (strcmp(input, S[i].name) == 0)
		{
			p_input = &S[i];
			break;
		}
	}

	for (int i = 0; i < 5;i++)
	{
		if (strncmp(p_input->stNum, S[i].stNum, 4) == 0 && p_input->grade == S[i].grade && p_input != &S[i])
		{
			printf(" %s", S[i].name);
			flag++;
		}
	}

	if (flag == 0)
		printf("0");

	return 0;
}