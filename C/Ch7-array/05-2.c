#include<stdio.h>

int main(){
    int arr[3][200], cnt = 0, tmp = 0;
    int i = 0, j = 0, k = 0;

    scanf("%d", &arr[0][0]);						//arA배열의 첫 인덱스에 저장
    for (i = 1; arr[0][i - 1] > 0; i++)			//arA배열의 두번째 인덱스부터 음수가 입력되기 전까지 저장
        scanf("%d", &arr[0][i]);
    scanf("%d", &arr[1][0]);						//arA배열의 첫 인덱스에 저장
    for (i = 1; arr[1][i - 1] > 0; i++)			//arA배열의 두번째 인덱스부터 음수가 입력되기 전까지 저장
        scanf("%d", &arr[1][i]);

    for (i = 0; i < 2; i++)             // 집합을 두 번 입력 받는다
    {
        for (j = 0; arr[i][j] > 0; j++)      //0보다 작은 요소가 입력되기 전까지 반복
        {
            tmp = 0;                            //계속 tmp은 0으로 초기화
            for (k = 0; k < j + 1; k++)     
            {
                if (arr[i][j] == arr[i][k])     //j번째 요소와 k번째 요소를 계속 비교하며 같다면
                    tmp++;                      //tmp에 1을 더한다
            }
            if (tmp == 1)                       //tmp가 1이라는 것은 자기 자신을 제외하고 동일한 요소가 없다는것
                arr[2][cnt++] = arr[i][j];      //arr[2][] 배열에 합집합을 저장
        }
    }

    for (i = 0; i < cnt; i++)             // 오름차순 정렬하는 코드
        for (j = 0; j < i; j++)
            if (arr[2][i] < arr[2][j]) {    //비교하는 요소들이 i번째 요소보다 크다면
                tmp = arr[2][i];            //둘의 자리를 바꾼다
                arr[2][i] = arr[2][j];
                arr[2][j] = tmp;
            }

    for (i = 0; i < cnt; i++) {             //중복되는 요소 한 번만 출력하는 코드
        tmp = 0;
        for (j = 0; j < i + 1; j++) {
            if (arr[2][i] == arr[2][j])      //i번째 요소와 겹치는 요소가 이전에 있었다면
                tmp++;                      //tmp에 1을 더한다
        }
        if (tmp == 1)                       //tmp가 1이면 i번째 요소는 자기 자신을 제외하곤 존재하지 않음
            printf(" %d", arr[2][i]);       //위의 경우에 i번째 요소 출력
    }

	return 0;
}