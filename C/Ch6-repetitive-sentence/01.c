#include<stdio.h>

int main(){
	int M = 0, N = 0, cnt = 0, sum = 0;
	scanf("%d %d", & M, &N);	//두 숫자를 입력 받는다

	if (N > M) {		//N이 M보다 클 때
		int max = M;	//N과 M을 바꾼다
		M = N;	
		N = max;
	}

	for (int i = 2; i <= 3; i++) {		//2의 배수와 3의 배수 따로따로 쓰지 않고 반복문으로 묶는다
		for (int j = N;j <= M; j++) {	
			if (j % i == 0) {			//j가 i의 배수일 때
				printf("%d ", j);		//해당 j 값을 출력
				cnt++;					//갯수를 하나 세준다
				sum += j;				//총합에 j를 더해준다
			}
		}
		printf("cnt=%d sum=%d\n", cnt, sum);		//개수와 총합을 출력
		cnt = 0;						//2의 배수를 처리한 후 그 다음을 위해 갯수를 0으로 초기화
		sum = 0;						//2의 배수를 처리한 후 그 다음을 위해 총합을 0으로 초기화
	}
	
	return 0;
}