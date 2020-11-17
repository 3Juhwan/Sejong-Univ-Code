#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct customer {
	char id[5];
	char* name;
	char* phone;
	struct customer* next;
}customer;

int main() {
	int N = 0, len = 0, cnt = 0;
	char tname[101] = "", tnum[14] = "";
	char search[101] = "", flag[5] = "";
	customer* C = NULL, * p = NULL, * q = NULL;

	scanf("%d", &N);
	getchar();

	C = (customer*)malloc(N * sizeof(customer));
	if (C == NULL) {
		printf("Not enough memory");
		return -1;
	}

	// input
	for (p = C; p < C + N; p++)
	{
		scanf("%s %s", tname, tnum);
		getchar();

		len = strlen(tname);
		p->name = (char*)malloc((len + 1) * sizeof(char));
		if (p->name == NULL) {
			printf("Not enough memory");
			return -1;
		}
		strcpy(p->name, tname);

		len = strlen(tnum);
		p->phone = (char*)malloc((len + 1) * sizeof(char));
		if (p->phone == NULL) {
			printf("Not enough memory");
			return -1;
		}
		strcpy(p->phone, tnum);

		strcpy(p->id, tnum + 9);
	}

	// connect NODES
	for (p = C; p < C + N; p++)
	{
		for (q = C + 1; q < C + N; q++)
		{
			if (strcmp(&p->id[3], &q->id[3]) == 0)
			{
				p->next = q;
				break;
			}
		}
	}

	scanf("%s", search);

	// print input data
	for (p = C; p < C + N; p++)
	{
		if (strcmp(search, p->id) == 0)
		{
			printf("%s %s ", p->name, p->phone);
			strcpy(flag, &p->phone[9]);
			break;
		}
	}

	for (p = C; p < C + N; p++)
	{
		if (strcmp(&flag[3], &p->id[3]) == 0)
		{
			cnt++;
			if (strcmp(flag, p->id) == 0)
			{
				printf("%d", cnt);
				break;
			}
		}
	}

	// free
	for (p = C; p < C + N; p++)
	{
		free(p->phone);
		free(p->name);
	}
	free(C);

	return 0;
}