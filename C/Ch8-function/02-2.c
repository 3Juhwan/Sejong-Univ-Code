#include<stdio.h>

char decrypt(char ch, int M);		//함수 원형 선언
char encrypt(char ch, int M);

int main() {
	int M1 = 0, M2 = 0, i = 0, j = 0;
	char ch[100];
	scanf("%c", &ch[0]);					//먼저 ch의 인덱스 0에 값을 저장
	for (i = 1; ch[i - 1] != '*';i++)		//*가 입력되기 전까지 입력 받는다
		scanf("%c", &ch[i]);
	scanf("%d %d", &M1, &M2);				//암호키도 입력받는다

	for (j = 0;j < i - 1;j++) {
		ch[j] = decrypt(ch[j], M1);			//ch배열에 암호가 풀린 문자를 저장한다
		printf("%c", ch[j]);				//암호가 풀린 문자 저장
	}
	printf("\n");							
	for (j = 0;j < i - 1;j++)				
		printf("%c", encrypt(ch[j], M2));	//M2로 다시 암호화한 것을 출력

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

char encrypt(char ch, int M) {
	M %= ('Z' - 'A' + 1);				//M이 Z와 A까지의 크기를 넘어가는 경우 처리
	if (ch >= 'A' && ch <= 'Z') {		//대문자일 때
		if (ch + M > 'Z')					//ch의 암호화한 문자가 대문자 영역을 벗어나는 경우
			ch = ch - ('Z' - 'A' + 1) + M;
		else
			ch += M;
	}
	else if (ch >= 'a' && ch <= 'z') {	//소문자일 때
		if (ch + M > 'z')					//ch의 암호화한 문자가 소문자 영역을 벗어나는 경우
			ch = ch - ('z' - 'a' + 1) + M;
		else
			ch += M;
	}
	return ch;							//대소문자가 아닐 땐 아무 처리 없이 반환
}