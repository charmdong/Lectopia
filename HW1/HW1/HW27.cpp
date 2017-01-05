#include <stdio.h>

int input();
void myflush();

int main()
{
	int gram;
	int cnt = 0;

	while (1)
	{
		gram = input();
		if (gram < 150)
			printf("* 메추리알 가지고 장난하지 마시오~ ^^\n");
		else if (gram <= 500)
		{
			cnt++;
			printf("* 현재 달걀의 수 : %d\n", cnt);
		}
		else // gram >500
			printf("* 타조알 가지고 장난하지 마시오~ ^^\n");

		if (cnt == 10)
		{
			printf("\n*** 달걀 포장이 끝났습니다.\n");
			break;
		}
	}
	return 0;
}

int input()
{
	int gram;
	printf("# 계란의 무게를 입력하세요(단위 : g) : ");
	
	while (scanf("%d",&gram)!=1)
	{
		myflush();
		printf("# 계란의 무게를 입력하세요(단위 : g) : ");
	}
	return gram;
}

void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}