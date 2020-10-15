#pragma warning (disable:4996)
#include <stdio.h>

int main() {
	char arr[10] = { 0, };
	char* p = NULL,* q = NULL, mch = '\0';
	int  cnt = 0, mcnt = 0;

	for (p = arr; p < arr + 10; p++)
		scanf("%c", p);

	for (p = arr; p < arr + 10; p++)
	{
		for (q = arr; q < arr + 10; q++)
		{
			if(*p == *q)
				cnt++;
		}
		if (cnt > mcnt)
		{
			mcnt = cnt;
			mch = *p;
		}
		cnt = 0;
	}

	printf("%c %d", mch, mcnt);

	return 0;
}