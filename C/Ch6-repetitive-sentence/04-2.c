#include<stdio.h>

int main(){
	int T = 0, n = 0, cntUn = 0, cntsam = 0, cntOv = 0;			//변수 선언
	scanf("%d", &T);	//T을 입력 받는다
	scanf("%d", &n);	//n을 입력 받는다

	while (n != 0) {		//n이 0이 아니면 반복
		while (n > 0) {		//n이 0보다 크면 반복
			if (n % 10 == T)cntsam++;	//n의 일의 자릿수가 T와 같을 때, cntsam에 카운트해준다
			if (n % 10 < T)cntUn++;		//n이 일의 자릿수가 T보다 작을 때, cntUn에 카운트해준다
			if (n % 10 > T)cntOv++;		//n이 일의 자릿수가 T보다 클 때, cntOv에 카운트해준다
			n /= 10;		//n을 10으로 나눈 몫으로 n을 초기화
		}
		scanf("%d", &n);	//n을 다시 입력 받는다
	}
	printf("%d %d %d", cntsam, cntUn, cntOv);

	return 0;
}