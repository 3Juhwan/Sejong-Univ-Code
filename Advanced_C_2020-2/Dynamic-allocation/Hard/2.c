#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char letters[21];
	int count;
} word;

int main() {
	char** pp = NULL, * p = NULL, * q = NULL;
	char temp[501] = "";
	int N = 0, len = 0, wcnt = 0, cnt = 0, flag = 0, mcnt = 0, flag_line = 0;
	word* warray = NULL, * wp = NULL, fp = {"",0};

	scanf("%d", &N);
	getchar();

	pp = (char**)malloc(N * sizeof(char*));
	if (pp == NULL)
		return -1;

	for (int i = 0; i < N;i++)
	{
		gets_s(temp, 501);
		len = strlen(temp);

		// 문장 소문자 변환
		p = temp;
		while (*p)
		{
			if (*p >= 'A' && *p <= 'Z')
				*p = *p + 'a' - 'A';
			p++;
		}

		// 문자열 메모리 할당 - 문장 저장
		pp[i] = (char*)malloc((len + 1) * sizeof(char));
		if (pp[i] == NULL)
			return -1;

		strcpy(pp[i], temp);

		// 공백에 널문자 삽입
		p = pp[i];
		while (*p)
		{
			if (*p == ' ')
				*p = '\0';
			p++;
		}

		// 단어 갯수 카운트
		for (p = pp[i]; p < pp[i] + len; p++)
		{
			for (q = p;q < pp[i] + len;q++)
			{
				if (strcmp(p, q) == 0)
					wcnt++;
				q += strlen(q);
			}
			if (wcnt == 1)
				cnt++;

			p += strlen(p);
			wcnt = 0;
		}

		// 구조체 메모리 할당 - 단어 저장
		warray = (word*)malloc(cnt * sizeof(word));
		if (warray == NULL)
			return -1;
		for (int i = 0;i < cnt;i++)
			warray[i].count = 1;

		// 구조체 배열에 정보 저장
		mcnt = cnt;
		for (p = pp[i]; p < pp[i] + len; p++)
		{
			// 중복 검사
			for (wp = warray; wp < warray + cnt - mcnt;wp++)
			{
				if (strcmp(p, wp->letters) == 0)
				{
					wp->count++;
					flag++;
				}
			}

			if (!flag)
			{
				//printf("IN\n");
				strcpy(wp->letters, p);
				mcnt--;
			}

			flag = 0;
			p += strlen(p);
		}

		//그리고 가장 긴 문장, 단어, 갯수 저장
			
		for (int j = 0; j < cnt;j++)
			if (fp.count < warray[j].count)
			{
				fp = warray[j];
				flag_line = i;
			}

		cnt = 0;

		free(warray);
		free(pp[i]);
	}
	printf("%d %d %s\n", flag_line, fp.count, fp.letters);
	
	free(pp);

	return 0;
}