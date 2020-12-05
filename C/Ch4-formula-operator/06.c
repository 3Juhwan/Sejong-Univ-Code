#include<stdio.h>

int main(){
	int mid = 0;		//중간값을 저장할 변수 선언 및 초기화
	int a = 0, b = 0, c = 0;		//변수 선언 및 초기화
	scanf("%d %d %d", &a, &b, &c);	//세 수 입력

	
	//세 수를 비교하여 중간값을 mid에 저장
	mid = a < b && a < c ? (b < c ? b : c) : mid;   //a가 가장 작을 때 b와 c를 비교하여 작은 수를 mid에 저장
	mid = b < a && b < c ? (a < c ? a : c) : mid;   //b가 가장 작을 때 a와 c를 비교하여 작은 수를 mid에 저장
	mid = c < a && c < b ? (a < b ? a : b) : mid;   //c가 가장 작을 때 a와 b를 비교하여 작은 수를 mid에 저장

	printf("%d", mid);		//출력

	return 0;
}