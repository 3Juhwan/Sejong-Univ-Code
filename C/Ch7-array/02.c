#include<stdio.h>

int main(){
	int ar[10], tmp[10] = { 0, };
	int  i = 0, j = 0, cnt = 0;
	for (i = 0;i < 10;i++) scanf("%d", &ar[i]);		//10개의 양의 정수 입력
	for (i = 0;i < 10;i++)							//i가 0부터 9까지 반복
		if (ar[i] % 2 == 1)tmp[cnt++] = ar[i];		//i번째의 요소가 홀수면 tmp 배열에 순서대로 저장
	for (i = 9;i >= 0;i--)							//i가 9부터 0까지 반복
		if (ar[i] % 2 == 0)tmp[cnt++] = ar[i];		//i번째의 요소가 짝수면 tmp 배열에 이어서 저장
	for (i = 0;i < 10;i++) 
		printf("%d ", tmp[i]);		//tmp배열 출력

	return 0;
}