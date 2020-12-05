#include<stdio.h>

int main(){
	int N = 0;			//변수 선언
	scanf("%d", &N);	//N을 입력 받는다

	//맨 아랫줄 줄 빼고 출력하는 코드
	for (int i = 0; i < N - 1; i++){		
		for (int j = 0;j < N - i - 1;j++)printf(" ");	//뒤집힌 계단모양으로 공백출력
		if(i != 0)printf("X");				//첫 줄 빼고 각 줄의 시작에 X를 하나 출력
		for (int j = 0; j < 2 * i - 1; j++)	printf("O");	//O를 계단식으로 2개씩 늘려나가며 출력
		printf("X\n");	//각 줄의 마지막에 X를 하나 출력
	}
	for (int i = 0; i < 2 * N - 1;i++)printf("X");	//맨 아랫줄 X출력
	
	return 0;
}