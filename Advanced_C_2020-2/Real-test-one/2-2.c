#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char** arr = NULL, temp[101]="";
	char* lstr = NULL, * sstr = NULL;		// 초기화 문제
	char* p = NULL, * q = NULL, * tmp = NULL;
	int N = 0, len = 0;
	int lnum = 0, snum = 101;
	int sword = 101, lword = 0;

	scanf("%d", &N);
	getchar();

	arr = (char**)malloc(N * sizeof(char*));
	if (arr == NULL) {
		printf("Not enough memory!");
		return -1;
	}

	for (char** p = arr; p < arr + N;p++)
	{
		gets(temp);
		len = strlen(temp);
		
		*p = (char*)malloc((len + 1) * sizeof(char));
		if (*p == NULL) {
			printf("Not enough memory!");
			return -1;
		}
		strcpy(*p, temp);

		// 가장 짧은 문장
		if (snum > len)
		{
			sstr = *p;
			snum = len;
		}

		// 가장 긴 문장
		if (lnum < len)
		{
			lstr = *p;
			lnum = len;
		}
	}

	p = sstr;
	q = sstr;
	while (*p)
	{
		if (*p == ' ')
		{
			*p = '\0';
			len = strlen(q);

			if (len < sword)
			{
				tmp = q;
				sword = len;
			}
			q += len + 1;
		}
		p++;
	}
	len = strlen(q);
	if (len < sword)
		tmp = q;
		
	printf("%s\n", tmp);

	p = lstr;
	q = lstr;
	while (*p)
	{
		if (*p == ' ')
		{
			*p = '\0';
			len = strlen(q);

			if (len > lword)
			{
				tmp = q;
				lword = len;
			}
			q += len + 1;
		}
		p++;
	}
	len = strlen(q);
	if (len > lword)
		tmp = q;
	
	printf("%s\n", tmp);

	return 0;
}