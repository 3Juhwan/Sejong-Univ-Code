#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

// 중복되는 단어 제거하고 모음/자음 그리고 내림차순 정렬

int main() {
	char arr[1010] = "", * pstr[10] = { NULL }, * ptmp = NULL;
	char* p = arr, * q = arr;
	int idx = 0, size = 0, vlen = 0, flag = 0;

	gets_s(arr, 1010);

	while (*p)
	{
		if (*p == ' ')
		{
			*p = '\0';

			flag = 0;
			for (int i = 0; i < idx; i++)
				if (strcmp(q, pstr[i]) == 0)
					flag = 1;
			
			if (flag == 0)
			{
				pstr[idx] = q;
				idx++;
			}

			q += strlen(q) + 1;
		}
		p++;
	}
	pstr[idx] = q;
	idx++;

	printf("\n");

	for (int i = 0; i < idx; i++)
		printf("%s\n", pstr[i]);

	for (int i = 0; i < idx - 1; i++)
	{
		for (int j = 0;j < idx - i - 1; j++)
		{
			if (*pstr[j + 1] == 'a' || *pstr[j + 1] == 'e' || *pstr[j + 1] == 'i' || *pstr[j + 1] == 'o' || *pstr[j + 1] == 'u')
			{
				ptmp = pstr[j];
				pstr[j] = pstr[j + 1];
				pstr[j + 1] = ptmp;
			}
		}
	}

	while (*pstr[vlen] == 'a' || *pstr[vlen] == 'e' || *pstr[vlen] == 'i' || *pstr[vlen] == 'o' || *pstr[vlen] == 'u')
		vlen++;

	for (int i = 0; i < vlen - 1; i++)
	{
		for (int j = 0; j < vlen - i - 1;j++)
		{
			if (strcmp(pstr[j], pstr[j + 1]) < 0)
			{
				ptmp = pstr[j];
				pstr[j] = pstr[j + 1];
				pstr[j + 1] = ptmp;
			}
		}
	}

	for (int i = 0; i < idx - vlen - 1; i++)
	{
		for (int j = vlen; j < idx - i - 1;j++)
		{
			if (strcmp(pstr[j], pstr[j + 1]) < 0)
			{
				ptmp = pstr[j];
				pstr[j] = pstr[j + 1];
				pstr[j + 1] = ptmp;
			}
		}
	}

	for (int i = 0; i < idx; i++)
		printf("%s\n", pstr[i]);

	return 0;
}