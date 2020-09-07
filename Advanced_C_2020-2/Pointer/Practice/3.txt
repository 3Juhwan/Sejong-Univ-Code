#pragma warning (disable:4996)
#include <stdio.h>

int main(){
	int arr[50] = { 0, } , N = 0, cnt = 0;	// cnt는 정수 개수를 세는 변수
	int *p = NULL;

	scanf("%d", &N);

	for (p = arr; p < arr + N && *(p - 1) != 0;p++, cnt++)
		scanf("%d", p);

	printf("%d", cnt - 1);		// 한 개 더 세지기 때문에 -1 해준다

	return 0;
}