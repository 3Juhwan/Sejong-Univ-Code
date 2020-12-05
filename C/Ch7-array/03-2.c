#include<stdio.h>

int main(){
	int ar[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	int F = 0, R = 0, M = 0;
	int i = 0, tmp = 0, cnt = 0;
	scanf("%d %d %d", &F, &R, &M);		//F R M 입력

	if (R - F + 1 >= M) {				//M이 F와 R까지의 갯수보다 같거나 작을 때
		tmp = ar[R];					//배열의 R번째 요소를 tmp에 저장
		for (i = R;i > R - M + 1;i--)	//배열 요소 오른쪽으로 옮기기
			ar[i] = ar[i - 1];
		ar[R - M + 1] = tmp;			
	}
	else {								//M이 F와 R까지의 갯수보다 클 때
		tmp = ar[R];					//배열의 R번째 요소를 tmp에 저장
		for (i = R;i > F;i--)			//배열 요소 오른쪽으로 옮기기
			ar[i] = ar[i - 1];
		ar[F] = tmp;					//배열의 R번째 요소를 F번째에 저장
	}

	for (i = 0; i < 20;i++)
		printf("%d ", ar[i]);			//배열 출력

	return 0;
}