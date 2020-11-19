#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int N = 0, len = 0, flag = 0, cnt = 0, x_len = 0, t_cnt = 0;
	char X[101] = "", temp[101] = "";
	char** Y = NULL, * flag_str = NULL;			// 초기화
	char* p = NULL;

	scanf("%d", &N);
	getchar();
	scanf("%s", X);
	getchar();

	x_len = strlen(X);

	Y = (char**)malloc(N * sizeof(char*));
	if (Y == NULL) {
		printf("Not enough memory");
		return -1;
	}
	flag_str = *Y;

	for (int i = 0; i < N; i++)
	{
		gets_s(temp, 101);
		len = strlen(temp);

		Y[i] = (char*)malloc((len + 1) * sizeof(char));
		if (Y[i] == NULL) {
			printf("Not enough memory");
			return -1;
		}

		strcpy(Y[i], temp);

		p = Y[i];
		t_cnt = 0;
		while (p < Y[i] + len)
		{
			if (strncmp(p, X, x_len) == 0)
			{
				t_cnt++;
				p += x_len - 1;
			}
			p++;
		}

		if (cnt < t_cnt) {
			flag_str = Y[i];
			cnt = t_cnt;
			flag++;
		}
	}

	if (flag)
		printf("%s", flag_str);
	else
		printf("NONE");

	for (int i = 0; i < N; i++)
		free(Y[i]);

	free(Y);

	return 0;
}