#include<stdio.h>

int main(){
    int arr[101], cnt = 0, tmp = 0;
    int i = 0, j = 0;
    scanf("%d", &arr[0]);               //arr의 첫번째 요소 입력

    while (arr[cnt] >= 0)
        scanf("%d", &arr[++cnt]);       //0 이하의 정수가 입력될 때까지 입력 받음

    for (i = 0; arr[i] >= 0; i++)      // 입력 예시의 2 4 6 .. 들어감
    {
        tmp = 0;
        for (j = 0; j < i + 1; j++)     //arr[i]의 자기 인덱스까지 반복
        {
            if (arr[i] == arr[j])       //arr[j]와 arr[j]가 같다면 
                tmp++;                  //tmp 에 1을 더한다
        }
        if (tmp == 1)                   //tmp가 1이면 자기 자신만 동일하단 의미
            printf("1");                //1출력
        else
            printf("0");                //이외는 0출력
    }

	return 0;
}