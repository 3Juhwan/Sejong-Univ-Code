#include<stdio.h>

int main(){
	int N = 0, sum = 0;			//변수 선언
	scanf("%d", &N);	//N을 입력 받는다

	while (N > 0){
		sum = sum * 10 + (N % 10);	//sum의 각자리수를 한 칸씩 앞으로 보내고 1의 자리에 새로운 수를 추가
		N /= 10;					//N의 뒷자리를 하나씩 없얘기 위해 10으로 나눈 몫을 구함
	}
	printf("%d", sum * sum);	//sum의 제곱을 출력

	return 0;
}