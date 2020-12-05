#include<stdio.h>

int main(){
	int M = 0, N = 0, cnt = 0;
	scanf("%d %d", & M, &N);	//두 숫자를 입력 받는다

	if (N > M) {		//N이 M보다 클 때
		int max = M;	//N과 M을 바꾸는 부분
		M = N;	
		N = max;
	}
	//어떤 정수의 제곱인 수는 약수의 개수가 홀수이다
	for (int i = N; i <= M; i++)		//i를 N부터 M까지 반복
		for(int j = 1; j <= i / 2 + 1;j++)	//j가 i의 절반보다 1클 때까지 반복
			if (j * j == i) cnt++;		//약수의 개수가 홀수일 때 cnt변수로 카운트해준다
	printf("%d", M - N - cnt + 1);		//N부터 M까지 포함한 범위에서 cnt만큼 뺀다

	return 0;
}