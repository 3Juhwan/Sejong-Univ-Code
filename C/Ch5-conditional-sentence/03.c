#include<stdio.h>

int main(){
	int a, b, c, tmp = 0;				//입력할 변수 a,b,c 선언 그리고 사칙연산이 시행됐는지 확인해줄 tmp변수 선언
	scanf("%d %d %d", &a, &b, &c);		//a,b,c 값을 입력 받는다

	if (a + b == c) {					//a와b사이에 +가 성립할 때
		printf("+");					//"+"를 출력
		tmp++;							//tmp를 1 증가시켜서 사칙연산이 성립했다는 것을 표시
	}
	if (a - b == c) {					//a와 b사이에 -가 성립할 때
		tmp != 0 ? printf("\n") : 0;	//앞에서 사칙연산이 시행됐다면 개행문자("\n")출력
		printf("-");					//"-"를 출력
		tmp++;					
	}
	if (a * b == c) {					//a와 b사이에 *가 성립할 때
		tmp != 0 ? printf("\n") : 0;
		printf("*");					//"*"를 출력
		tmp++;
	}
	if (b != 0 && a / b == c) {			//a와 b사이에 /가 성립할 때, 그리고 분모 b 는 0이면 아닐 때
		tmp != 0 ? printf("\n") : 0;
		printf("/");					//"/"를 출력
		tmp++;	
	}
	if (tmp == 0)						//사칙연산이 한번도 성립하지 않았다면 tmp는 0
		printf("Incorrect");			//Incorrect를 출력

	return 0;
}