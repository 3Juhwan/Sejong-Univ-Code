#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct customer {
	char id[5];
	char* name;
	char* phone;
}customer;

int main() {
	int N = 0, len = 0;
	char tname[101] = "", tnum[14] = "";
	char search[101] = "";
	customer* C = NULL;

	scanf("%d", &N);
	getchar();

	C = (customer*)malloc(N * sizeof(customer));
	if (C == NULL) {
		printf("Not enough memory");
		return -1;
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%s %s", tname, tnum);
		getchar();

		len = strlen(tname);
		C[i].name = (char*)malloc((len + 1) * sizeof(char));
		if (C[i].name == NULL) {
			printf("Not enough memory");
			return -1;
		}
		strcpy(C[i].name, tname);

		len = strlen(tnum);
		C[i].phone = (char*)malloc((len + 1) * sizeof(char));
		if (C[i].phone == NULL) {
			printf("Not enough memory");
			return -1;
		}
		strcpy(C[i].phone, tnum);

		strcpy(C[i].id, tnum + 9);
	}

	scanf("%s", search);

	for (int i = 0; i < N; i++)
	{
		if (strcmp(search, C[i].id) == 0)
		{
			printf("%s %s %d", C[i].name, C[i].phone, i + 1);
			break;
		}
	}

	for (int i = 0; i < N;i++)
	{
		free(C[i].phone);
		free(C[i].name);
	}
	free(C);

	return 0;
}