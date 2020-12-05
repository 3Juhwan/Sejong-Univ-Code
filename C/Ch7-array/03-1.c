#include<stdio.h>

int main(){
	int ar[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	int M, i = 0, tmp = 0;
	scanf("%d", &M);			//M 입력
			
	tmp = ar[19];				//배열의 19번째 요소를 tmp에 저장
	for (i = 19;i > 19 - M;i--)	//배열 요소 오른쪽으로 옮기기
		ar[i] = ar[i - 1];
	ar[20 - M] = tmp;			//위에서 tmp에 저장한 값을 배열 끝에서 M번째 요소에 저장

	for (i = 0; i < 20;i++)
		printf("%d ", ar[i]);			//배열 출력

	return 0;
}