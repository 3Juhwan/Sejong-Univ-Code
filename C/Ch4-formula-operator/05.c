#include<stdio.h>

int main(){
	int n = 0;				//입력 받을 변수 선언
	
	scanf("%d", &n);		//입력
	
	int hun = n / 100;		//백의 자리수
	int ten = n % 100 / 10;	//십의 자리수
	int one = n % 10;		//일의 자리수

	hun = hun < ten ? ten : hun;	//hun ten 중 더 큰 수를 hun에 저장
	hun = hun < one ? one : hun;	//hun one 중 더 큰 수를 hun에 저장

	printf("%d", hun);		//hun 출력

	return 0;
}