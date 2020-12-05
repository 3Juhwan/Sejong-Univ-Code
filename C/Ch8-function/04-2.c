#include<stdio.h>

int count(int N, int M);

int main() {
	int N = 0, M = 0, cnt = 0;		

	scanf("%d", &M);			//M을 입력
	scanf("%d", &N);			//N을 입력
	while (N >= 0){	
		cnt += count(N, M);		//각 정수에 M이 나타난 횟수를 cnt에 더함
		scanf("%d", &N);			//N을 입력
	}

	printf("%d ", cnt);		//카운트한 값 출력

	return 0;
}

int count(int N, int M) {
	int cnt = 0;					//M이 N에 반복되는 횟수를 저장할 변수

	while (N > 0) {					//N이 0크면 반복
		if (N % 10 == M)			//N의 일의 자리가 M이면
			cnt++;					//cnt에 카운트
		N /= 10;					//N의 1의 자리를 없얨
	}

	return cnt;						//카운트한 값을 반환
}