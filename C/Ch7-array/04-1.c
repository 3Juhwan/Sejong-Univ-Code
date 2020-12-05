#include<stdio.h>

int main(){
	int N = 0,ar[20];
	int i = 0;
	scanf("%d", &N);	//정수 N입력
	for (i = 0; i < N;i++)scanf("%d", &ar[i]);			//N개만큼 배열에 저장

	for (i = N - 1; i >= 0;i--)printf("%d ", ar[i]);	//배열 거꾸로 출력

	return 0;
}