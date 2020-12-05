#include<stdio.h>

int count(int N, int M);

int main() {
	int N = 0, arr[10] = { 0, };		//0부터 9까지 각 숫자가 몇 번 나타나는 지 저장할 변수
	
	scanf("%d", &N);			//N을 입력
	while (N >= 0){						//음수가 입력되면 탈출
		for (int i = 0;i < 10;i++) {	//0부터 9까지 실행
			arr[i] += count(N, i);		//각 숫자가 나타는 횟수 저장
		}
		scanf("%d", &N);			//N을 입력
	}

	for (int i = 0;i < 10;i++)
		printf("%d ", arr[i]);		//0부터 9까지 나타는 횟수 출력

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