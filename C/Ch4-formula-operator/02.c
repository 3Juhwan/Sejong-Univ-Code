#include<stdio.h>

int main() {
	int n = 0;			//변수 선언 및 초기화

	scanf("%d", &n);	//입력

	//윤년이면 L을 출력하도록 조건을 달아준다
	n % 4 == 0 && n % 100 != 0 || n % 400 == 0 ? printf("L") : printf("C");	
	//그 이외는 C를 출력하도록 한다

	return 0;
}