#include<stdio.h>

int main(){
	int T = 0, n = 0, cntUn = 0, cntsam = 0, cntOv = 0;			//변수 선언
	scanf("%d", &T);	//T을 입력 받는다
	scanf("%d", &n);	//n을 입력 받는다

	while (n != 0) {		//n이 0이 아니면 반복
		if (n == T)cntsam++;	//입력받은 n이 T와 같을 때, cntsam에 카운트해준다
		if (n < T)cntUn++;		//입력받은 n이 T보다 작을 때, cntUn에 카운트해준다
		if (n > T)cntOv++;		//입력받은 n이 T보다 클 때, cntOv에 카운트해준다
		scanf("%d", &n);	//n을 입력 받는다
	}
	printf("%d %d %d", cntsam, cntUn, cntOv);

	return 0;
}