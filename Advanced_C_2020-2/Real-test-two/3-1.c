#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char A[101] = "", B[101] = "", output[101] = "";
	char* Aword[20] = { NULL }, * Bword[20] = { NULL };
	char* p = A, * q = A;
	int Asize = 0, Bsize = 0;
	int cnt = 0;
	int len = 0;

	gets(A);
	gets(B);

	// A 문자열 단어 쪼개기
	while (*p)
	{
		if (*p == ' ')
		{
			*p = '\0';
			Aword[Asize] = q;
			Asize++;
			q += strlen(q) + 1;		/// 
		}
		p++;
	}
	Aword[Asize] = q;
	Asize++;

	p = B;
	q = B;
	// B 문자열 단어 쪼개기
	while (*p)
	{
		if (*p == ' ')
		{
			*p = '\0';
			Bword[Bsize] = q;
			Bsize++;
			q += strlen(q) + 1;		/// 
		}
		p++;
	}
	Bword[Bsize] = q;
	Bsize++;

	for (int i = 0; i < Asize; i++)
	{
		for (int j = 0; j < Bsize;j++)
		{
			if (strcmp(Aword[i], Bword[j]) == 0)
			{
				cnt++;
				if (len < strlen(Aword[i]))
				{
					len = strlen(Aword[i]);
					strcpy(output, Aword[i]);
				}
				else if (len == strlen(Aword[i]) && strcmp(output, Aword[i]) > 0)
				{
					strcpy(output, Aword[i]);
				}
			}
		}
	}

	printf("%d\n", cnt);
	printf("%s\n", output);

	return 0;
}