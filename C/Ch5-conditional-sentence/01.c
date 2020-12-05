#include<stdio.h>

int main(){

	char a;				//문자형 변수 선언
	scanf("%c", &a);	//입력

	if (a >= 'A' && a <= 'Z')			//대문자 입력 받으면
		printf("%c", a + 'a' - 'A');	//소문자로 바꿈
	else if (a >= 'a' && a <= 'z')		//소문자 입력 받으면
		printf("%c", a - 'a' + 'A');	//대문자로 바꿈
	else								//이외의 것을 입력받으면
		printf("%c", a);				//그대로 출력

	return 0;
}