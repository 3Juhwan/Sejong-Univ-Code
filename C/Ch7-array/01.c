#include<stdio.h>

int main(){
	int N, arr[100];
	int i = 0, j = 0, cnt = 0, n = 0, er = 0;

	scanf("%d", &N);					//출전자 수 입력
	for (i = 0; i < N;i++, n++)				//점수 입력
		scanf("%d", &arr[i]);

	while (n != 1) {
		for (i = 0; i < N;i++)	//입력 범위가 넘어간 값을 체크
			if(arr[i] < 0 || arr[i] > 100)
				er++;

		if (er != 0) {					//입력 범위 넘어간 값이 있었다면
			printf("ERROR");			//ERROR를 출력하고
			break;						//while문 탈출, 즉 프로그램 종료
		}

		cnt = 0;
		for (i = 0; i < n;) {
			if (i == n - 1 && n % 2 == 1)	//부전승 처리
				arr[cnt++] = arr[i];
			else {
				if (arr[i] >= arr[i + 1])		//두 선수 중 전자의 점수가 높을 때
					arr[cnt++] = arr[i];		//순서대로 배열의 앞부터 저장
				else							//후자의 점수가 더 높을 때
					arr[cnt++] = arr[i + 1];	//순서대로 배열의 앞부터 저장
			}
			i += 2;
		}

		n = (n + 1) / 2;					//라운드마다 올라갈 수 있는 사람의 수는 절반으로 줄어든다 (선수가 홀수 일 때, 예외처리)

		for (i = 0;i < n;i++)				//라운드 올라간 사람의 점수 출력
			printf("%d ", arr[i]);			
		printf("\n");
	}

	return 0;
}