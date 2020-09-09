#pragma warning (disable:4996)
#include <stdio.h>

int main() {
	char str[10], *p = NULL, *q = NULL;
	char ch;		// 빈도수가 가장 높은 문자 저장하는 변수
	int max = 0;	// 가장 높은 빈도수 저장하는 변수

	for (p = str; p < str + 10; p++)
		scanf("%c", p);

	for (p = str; p < str + 9;p++) {
		int cnt = 0;					// p와 같은 문자 빈도수를 세는 변수

		for (q = p; q < str + 10; q++) 
			if (*p == *q) cnt++;

		if (max < cnt) {	
			max = cnt;
			ch = *p;
		}
	}

	printf("%c %d", ch, max);

	return 0;
}