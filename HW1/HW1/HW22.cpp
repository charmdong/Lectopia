#include <stdio.h>

int input();
void myflush();

int main()
{
	int num;
	int cnt = 0;
	
	num = input();

	while (num)
	{
		printf("*");
		cnt++;
		
		if (cnt == 5)
		{
			printf("\n");
			cnt = 0;
		}
		num--;
	}
	printf("\n");
	return 0;
	
}

int input() 
{
	int num;
	
	while (1)
	{
		printf("# 정수값을 입력하세요 : ");

		if (scanf("%d", &num) == 1) // 정상 입력의 경우
			break;
		else // 문자 입력의 경우
			myflush(); // 버퍼 비우기
	}
	return num;
}

void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}