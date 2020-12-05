#include<stdio.h>

int main(){	
	int n1, n2, n3, total = 0;			//변수 선언, total 가격 저장하는 변수로 0으로 초기화한다.
	scanf("%d %d %d", &n1, &n2, &n3);	//선택 메뉴 입력

	switch (n1)				//첫번째 선택 메뉴에 대해...
	{
	case 0:					//선택하지 않았을 때
		printf("None\n");	//none을 출력
		break;
	case 1:					//1번 메뉴를 선택했을 때
		total += 15000;		//total가격에 15000원 더하기
		printf("Pizza\n");	//Pizza를 출력
		break;
	case 2:					//2번 메뉴를 선택했을 때
		total += 5000;		//total가격에 5000원 더하기
		printf("Burger\n");	//Burger를 출력
		break;
	case 3:					//3번 메뉴를 선택했을 때
		total += 4500;		//total가격에 4500원 더하기
		printf("Salad\n");	//Salad를 출력
		break;
	case 4:					//4번 메뉴를 선택했을 때
		total += 800;		//total가격에 800원 더하기
		printf("Ice cream\n");	//Ice cream를 출력
		break;
	case 5:					//5번 메뉴를 선택했을 때
		total += 500;		//total가격에 500원 더하기
		printf("Beverage\n");	//Beverage를 출력
		break;
	}
	switch (n2)				//두번째 선택 메뉴도...
	{						//첫번째 선택 메뉴와 동일한 과정을 거친다
	case 0:					//선택하지 않았을 때
		printf("None\n");	//None을 출력
		break;
	case 1:					//1번 메뉴를 선택했을 때
		total += 15000;
		printf("Pizza\n");	//Pizza를 출력
		break;
	case 2:					//2번 메뉴를 선택했을 때
		total += 5000;
		printf("Burger\n");	//Burger를 출력
		break;
	case 3:					//3번 메뉴를 선택했을 때
		total += 4500;
		printf("Salad\n");	//Salad를 출력
		break;
	case 4:					//4번 메뉴를 선택했을 때
		total += 800;
		printf("Ice cream\n");	//Ice cream를 출력
		break;
	case 5:					//5번 메뉴를 선택했을 때
		total += 500;
		printf("Beverage\n");	//Beverage를 출력
		break;
	}
	switch (n3)				//세번째 선택 메뉴도...
	{						//첫번째 선택 메뉴와 동일한 과정을 거친다
	case 0:					//선택하지 않았을 때
		printf("None\n");
		break;
	case 1:					//1번 메뉴를 선택했을 때
		total += 15000;
		printf("Pizza\n");
		break;
	case 2:					//2번 메뉴를 선택했을 때
		total += 5000;
		printf("Burger\n");
		break;
	case 3:					//3번 메뉴를 선택했을 때
		total += 4500;
		printf("Salad\n");
		break;
	case 4:					//4번 메뉴를 선택했을 때
		total += 800;
		printf("Ice cream\n");
		break;
	case 5:					//5번 메뉴를 선택했을 때
		total += 500;
		printf("Beverage\n");
		break;
	}
	printf("Total:%dwon", total);	//총금액 출력

	return 0;
}