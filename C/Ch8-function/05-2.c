#include<stdio.h>

int add_digit(int N);

int main() {
	int N = 0, tmp;
	scanf("%d", &N);					//N 입력
	tmp = add_digit(N);					//tmp에 함수 호출 및 디지털근 저장

	while (tmp >= 10)					//디지털 근에 10 이상이면 
		tmp = add_digit(tmp);			//함수호출

	printf("%d", tmp);					//디지털근 출력

	return 0;
}

int add_digit(int N) {
	int temp = 0;			//디지털 근을 저장할 변수
	while (N > 0) {			//N이 0보다 클 때까지 반복
		temp += N % 10;		//N의 1의 자릿수를 temp에 저장
		N /= 10;			//N의 1의 자릿수를 없얨
	}

	return temp;			//디지털근 반환
}