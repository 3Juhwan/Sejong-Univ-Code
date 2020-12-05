#include<stdio.h>

int main(){
	int n = 0, num = 0;	//변수 선언

	scanf("%d", &n);	//입력

	//각자리수에 해당하는 변수 선언과 초기화
	int thu = n / 1000;			//천의 자리
	int hun = n % 1000 / 100;	//백의 자리
	int ten = n % 100 / 10;		//십의 자리
	int one = n % 10;			//일의 자리

	num = one * 1000 + ten * 100 + hun * 10 + thu;	//hun을 입력받은 수가 뒤집힌 수로 초기화
	num -= n;										//두 수의 차
	num = num < 0 ? -num : num;						//절댓값 처리

	printf("%d", num);			//출력


	return 0;
}