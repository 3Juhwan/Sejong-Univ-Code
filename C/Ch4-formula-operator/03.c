#include<stdio.h>

int main() {
	int n = 0, count = 1;	//변수 선언과 초기화

	scanf("%d", &n);		//입력

	//각자리 수의 변수 선언 및 초기화
	int hun = n / 100;		//백의 자리
	int ten = n % 100 / 10;	//십의 자리
	int one = n % 10;		//일의 자리

	//각자리 수가 서로 같으면 count변수에 1을 더해준다
	count += hun == ten;
	count += hun == one;
	count += ten == one;
	count -= count == 4;	//각자리수가 모두 동일한 경우 count변수는 4가 된다 따라서 이 경우 1을 빼준다

	printf("%d", count);	//출력

	return 0;
}