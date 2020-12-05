#include<stdio.h>

int main(){
	int n;					//변수 선언
	scanf("%d", &n);		//변수 입력 받기

	for (int i = 1; i <= n; i++) {						//다이아몬드 상단 출력하는 코드
		for (int j = 0;j < n - i;j++)printf(" ");		//뒤집힌 계단 공백을 출력
		for (int j = 0;j < 2 * i - 1;j++)printf("*");	//계단식으로 2개씩 늘려나가며 *을 출력
		printf("\n");
	}
	for (int i = 1; i <= n; i++) {		//다이아몬드 하단을 출력, 위의 중첩 반복문 거꾸로 하면 된다
		for (int j = 0;j < i;j++)printf(" ");		//계단식으로 공백을 출력
		for (int j = 0;j < 2 * (n - i) - 1;j++)printf("*");	//뒤집힌 계단 모양으로 2개씩 줄이며 *을 출력
		printf("\n");
	}

	return 0;
}