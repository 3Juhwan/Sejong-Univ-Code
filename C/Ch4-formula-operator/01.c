#includestdio.h

int main(){
	char str;			문자형 변수 선언
	scanf(%c, &str);	문자를 입력

	입력 받는 값이 Z의 아스키 코드 값보다 작거나 같으면 그대로 출력, 크면 소문자를 대문자로 바꾸어 출력
	str = 'Z'  printf(%c, str)  printf(%c, str - 'a' + 'A');
	return 0;
}