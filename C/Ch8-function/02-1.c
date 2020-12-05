#include<stdio.h>

char decrypt(char ch, int M);

int main() {
	int M = 0;
	char ch[10];
	for (int i = 0; i < 10;i++)		//10번 반복
		scanf("%c", &ch[i]);		//암호화된 문자들을 입력 받는다
	scanf("%d", &M);				//암호키 입력

	for (int i = 0;i < 10;i++)				//10번 반복
		printf("%c", decrypt(ch[i], M));	//암호화를 푸는 decrypt함수를 호출하고 출력

	return 0;
}

char decrypt(char ch, int M) {
	M %= ('Z' - 'A' + 1);				//M이 Z와 A까지의 크기를 넘어가는 경우 처리
	if (ch >= 'A' && ch <= 'Z') {		//대문자일 때
		ch -= M;
		if (ch < 'A')					//ch가 대문자 영역을 벗어나는 경우
			ch += 'Z' - 'A' + 1;		
	}
	else if (ch >= 'a' && ch <= 'z') {	//소문자일 때
		ch -= M;	
		if (ch < 'a')					//ch가 소문자 영역을 벗어나는 경우
			ch += 'z' - 'a' + 1;
	}
	return ch;							//대소문자가 아닐 땐 아무 처리 없이 반환
}