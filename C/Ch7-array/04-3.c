#include<stdio.h>

int main(){
	int N = 0, arr[30], copy[30];
	int  i = 0, j = 0, cnt1 = 0, cnt2 = 0;

	scanf("%d", &N);							//N입력
	for (i = 0; i < N;i++)
		scanf("%d", &arr[i]);				//N크기의 배열을 입력 받는다
	for (i = 0; i < N;i++)
		printf(" %d", arr[N - i - 1]);		//입력 받은 배열을 거꾸로 출력
	printf("\n");								//줄 바꿈
	for (i = 0; i < N;i++)
		copy[i] = arr[i];					//처음 입력 받은 arr 배열을 copy배열에 복사

	while (N >= 1) {
		cnt1 = 0, cnt2 = 0;

		for (i = 0; i < N;) {
			for (j = i; j < N && j < i + 3; j++) {	//세 개를 비교해서 max값을 저장하는 코드
				if (arr[i] < arr[j])
					arr[i] = arr[j];

			}
			arr[cnt1++] = arr[i];					//max값을 arr배열에 저장
			printf(" %d", arr[cnt1 - 1]);			//max값 출력
			i += 3;									//세개 단위로 비교할 수 있게 3을 더해준다
		}
		printf("\n");								//줄 바꿈

		for (i = 0; i < N;) {
			for (j = i; j < N && j < i + 3; j++) {	//세 개를 비교해서 max값을 저장하는 코드
				if (copy[i] > copy[j])
					copy[i] = copy[j];

			}
			copy[cnt2++] = copy[i];					//min값을 copy배열에 저장
			printf(" %d", copy[cnt2 - 1]);			//min값 출력
			i += 3;									//세개 단위로 비교할 수 있게 3을 더해준다
		}
		printf("\n");								//줄 바꿈

		N = (N + 2) / 3;

		if (N == 1)
			N = N - 1;
	}

	return 0;
}