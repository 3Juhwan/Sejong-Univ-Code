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
	int N = 0, len = 0, cnt = 1;
	char tname[101] = "", tnum[14] = "";
	char search[101] = "";
	customer* C = NULL, * p = NULL, * q = NULL;

	scanf("%d", &N);
	getchar();

	C = (customer*)malloc(N * sizeof(customer));
	if (C == NULL) {
		printf("Not enough memory");
		return -1;
	}

	// input
	for (p = C;p < C + N;p++)
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

	scanf("%s", search);

	for (p = C;p < C + N - 1;p++)
	{
		for (q = C;q < C + N;q++)
		{
			if (strcmp(&p->id[3], &q->id[3]) == 0)
			{
				p->next = q;
				break;
			}
		}
	}

	for (p = C;p < C + N;p++)
	{
		if (strcmp(search, &p->id[3]) == 0)
		{
			printf("%s %s %d\n", p->name, p->phone, cnt);
			cnt++;
		}
	}

	for (p = C;p < C + N;p++)
	{
		free(p->phone);
		free(p->name);
	}
	free(C);

	return 0;
}