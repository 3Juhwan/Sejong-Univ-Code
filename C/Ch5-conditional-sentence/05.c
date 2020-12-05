#include<stdio.h>

int main(){

	int n1, n2, n3, n4, n5;		//변수 5개 선언
	int max, min;				//최댓값, 최솟값 변수 선언
	scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);	//5개 숫자를 입력 받는다

	max = n1 < n2 ? n2 : n1;	//n1과 n2를 비교해서 큰 값을 max에 저장
	max = max < n3 ? n3 : max;	//max과 n3를 비교해서 큰 값을 max에 저장
	max = max < n4 ? n4 : max;	//max과 n4를 비교해서 큰 값을 max에 저장
	max = max < n5 ? n5 : max;	//max과 n5를 비교해서 큰 값을 max에 저장

	min = n1 > n2 ? n2 : n1;	//n1과 n2를 비교해서 작은 값을 min에 저장
	min = min > n3 ? n3 : min;	//min과 n3를 비교해서 작은 값을 min에 저장
	min = min > n4 ? n4 : min;	//min과 n4를 비교해서 작은 값을 min에 저장
	min = min > n5 ? n5 : min;	//min과 n5를 비교해서 작은 값을 min에 저장

	printf("max: %d\nmin: %d", max, min);	//최댓값과 최솟값 출력

	return 0;
}