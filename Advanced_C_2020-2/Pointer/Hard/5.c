#pragma warning (disable:4996)
#include <stdio.h>

void print_word(char* p, char q[]);

int main() {
	char arr[1000];
	char* p = arr;

	while ((*(p - 1) != '!' && *(p - 1) != '.' && *(p - 1) != '?') || p == arr)
	{
		scanf("%c", p++);
	}
	p--;

	// 여기까지 마치면 p에는 문장의 끝주소가 저장되어 있다

	print_word(p, arr);

	printf("%c", *p);		// 마지막 마침표/느낌표/물음표 출력

	return 0;
}

void print_word(char* p, char q[]) {
	char* bump = p;

	while (p != q - 1)
	{
		bump = p - 1;

		while (*bump != ' ' && bump != q - 1)       // 앞 공백의 주소로 bump 포인터 이동
		{
			bump--;
		}

		for (char* tmp = bump + 1;tmp < p;tmp++)	// 단어 출력
		{
			printf("%c", *tmp);
		}

		if (bump > q)		// 단어 간 공백 출력
		{
			printf(" ");
		}

		p = bump;       // 앞 공백의 주소로 p 포인터 이동

	}

}