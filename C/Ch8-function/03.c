#include <stdio.h>

int multiple(int x, int y);
int maximum(int x, int y);
int digit_maximum(int x);

int main() {
	int N, M, K;
	int max = 0, temp1 = 0, temp2 = 0;
	scanf("%d %d %d", &N, &M, &K);		//N과 M과 K를 입력 받는다

	for (int i = N; i <= M;i++) {		//N부터 M까지 실행
		if (multiple(i, K)) {			//i가 K의 배수면
			temp1 = digit_maximum(i);	//각 자릿수 중 최대값을 temp1에 저장
			max = maximum(temp1, max);	//max와  temp1 중 큰 값을 max에 저장
		}
		else {							//i가 k의 배수가 아니라면
			temp2 = i % K;				//i를 k로 나눈 나머지를 temp2에 저장
			max = maximum(temp2, max);	//max와  temp2 중 큰 값을 max에 저장
		}
	}

	printf("%d", max);		//최댓값 출력

	return 0;
}

int multiple(int x, int y) {
	if (x % y == 0)			//x가 y의 배수라면
		return 1;			//1을 반환
	return 0;				//아니라면 0을 반환
}

int maximum(int x, int y) {
	if (x > y)				//x가 y보다 크면
		return x;			//x를 반환
	return y;				//아니라면 y를 반환
}

int digit_maximum(int x) {
	int tmp = 0, max = 0;

	while (x > 0) {					//x가 0보다 클 때까지 반복
		tmp = x % 10;				//tmp에 x의 일의 자릿수를 저장
		max = maximum(tmp, max);	//x의 일의 자릿수를 없얜다
		x /= 10;
	}

	return max;
}