#include <stdio.h>

int num_digit(int);		
int convert_top(int, int);
int convert_bottom(int);

int main() {
	int N = 0, is_num = 0;
	scanf("%d", &N);						//N 입력

	if (num_digit(N) % 2 == 1)				//N이 홀수일 때
		while (N > 0) {
			is_num = num_digit(N);			//N의 자릿수를 구함
			N = convert_top(N, is_num);		//convert_top 함수 호출		
		}
		
	else									//N이 짝수일 때
		while (N > 0)
			N = convert_bottom(N);			//convert_bottom 함수 호출

	return 0;
}

int num_digit(int N) {
	int cnt = 0;
	while (N > 0) {
		N /= 10;
		cnt++;						//N의 자릿수만큼 cnt에 저장
	}					
									
	return cnt;
}

int convert_top(int N, int x) {
	int tmp = 1;						//N의 자릿수보다 2자리 작은 만큼 tmp에 저장
	for (int i = 0; i < x - 2;i++)		//예) N 이 5자리면
		tmp *= 10;						//tmp는 1000

	int a = N / tmp;					//N의 앞자리 2개 짜르기

	if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))	//a가 대문자나 소문자면
		printf("%c", a);
	else
		printf("*");										//아니라면 * 출력

	//예외처리 (1000000이 입력되면 예외가 발생한다)
	
	int under_tmp = tmp / 10;
	int copy_N = N;

	while (under_tmp > 0) {							
		if ((copy_N / under_tmp) % 10 == 0)			//앞에 두 자리를 자르고 남은 수의 맨 앞자리가 0일 때
			printf("*");							// * 출력
		else
			break;
		under_tmp /= 100;							//계속해서 두자리 뒤의 숫자가 0이라면
	}

	return N % tmp;						//앞에 두자리 짜르고 남은 수 리턴
}

int convert_bottom(int N) {
	int tmp = N % 100;					//뒤에 두자리 짜르기

	if ((tmp >= 'A' && tmp <= 'Z') || (tmp >= 'a' && tmp <= 'z'))	//a가 대문자나 소문자면
		printf("%c", tmp);
	else
		printf("*");										//아니라면 * 출력

	return N / 100;						//뒤에 두자리 짜르고 남은 수 리턴
}