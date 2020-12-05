#include<stdio.h>

int add_digit(int N);

int main() {
	int N = 0, tmp;
	int min = 10, min_N = 0;			//min값에 따라 
	scanf("%d", &N);					//N 입력

	while (N >= 0) {					//음수 입력 전까지 계속 반복
		tmp = add_digit(N);					//tmp에 함수 호출 및 디지털근 저장

		while (tmp >= 10)					//디지털 근에 10 이상이면 
			tmp = add_digit(tmp);			//함수호출

		if (min > tmp) {				//min보다 해당 디지털 근이 작으면
			min = tmp;					//min에 디지털 근 저장
			min_N = N;					//해당 디지털 근의 정수도 저자
		}
		scanf("%d", &N);					//N 입력
	}
	printf("%d %d", min_N, min);					//디지털근 출력

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