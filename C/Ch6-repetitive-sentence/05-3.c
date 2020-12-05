#include<stdio.h>

int main(){
	int N = 0, sumOdd = 0, sumEven = 0;			//변수 선언
	scanf("%d", &N);	//N을 입력 받는다

	while (N > 0) {
		if (N % 2 == 0)		//N의 일의 자릿수가 짝수일 때
			sumEven = sumEven * 10 + (N % 10);	//sumEven의 각자리수를 한 칸씩 앞으로 보내고 일의 자리에 새로운 수를 추가
		if (N % 2 == 1)		//N의 일의 자릿수가 홀수일 때
			sumOdd = sumOdd * 10 + (N % 10);	//sumOdd의 각자리수를 한 칸씩 앞으로 보내고 일의 자리에 새로운 수를 추가
		N /= 10;					//N의 뒷자리를 하나씩 없얘기 위해 10으로 나눈 몫을 구함
	}
	printf("%d %d", sumEven, sumOdd);	//sumEven과 sumOdd를 순서대로 출력

	return 0;
}