#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int);
int input();
void output(int,int);
void myflush();

int main()
{
	int res;
	int num;
	int win=0, lose=0, draw=0;
	
	srand((unsigned int)time(NULL));
	while (1)
	{
		num = input();
		res = random(3);
		output(res, num);
		if ((num == 1 && res == 2) || (num == 2 && res == 3) || (num == 3 && res == 1))
			win += 1;
		else if((num == 2 && res == 1) || (num == 3 && res == 2) || (num == 1 && res == 3))
			lose += 1;
		else
			draw += 1;
		
		if (lose == 1)
			break;
	}
	printf("\n\t############################\n");
	printf("\t### 게임결과 : %d 승 %d 무 ###\n", win, draw);
	printf("\t############################\n");
	return 0;
}

int random(int n)
{
	int res;
	res = rand() % n;
	return res+1;
}

int input()
{
	int num;
	
	while (1)
	{
		printf("# 바위는 1, 가위는 2, 보는 3 중에서 선택하세요 : ");
		if (scanf("%d", &num) == 1) // 정상 입력
		{
			if (num >= 1 && num <= 3) // 정상 입력
				break;
			else
				myflush();
		}
		else // 문자 입력
			myflush();
	}
	return num;
}

void output(int res, int num)
{
	if (num == res) // 비긴 경우
	{
		if (num == 1)
			printf("당신은 바위 선택, 컴퓨터는 바위 선택 : 비겼습니다.\n");
		else if(num ==2)
			printf("당신은 가위 선택, 컴퓨터는 가위 선택 : 비겼습니다.\n");
		else // num ==3
			printf("당신은 보 선택, 컴퓨터는 보 선택 : 비겼습니다.\n");
	}
	else // 승부가 난 경우....
	{
		if(num == 1 && res == 2) 
			printf("당신은 바위 선택, 컴퓨터는 가위 선택 : 이겼습니다.\n");
		else if(num == 2 && res == 3)
			printf("당신은 가위 선택, 컴퓨터는 보 선택 : 이겼습니다.\n");
		else if(num == 3 && res == 1)
			printf("당신은 보 선택, 컴퓨터는 바위 선택 : 이겼습니다.\n");
		//====================================
		else if(num == 2 && res == 1)
			printf("당신은 가위 선택, 컴퓨터는 바위 선택 : 당신이 졌습니다.\n");
		else if(num == 3 && res == 2)
			printf("당신은 보 선택, 컴퓨터는 가위 선택 : 당신이 졌습니다.\n");
		else
			printf("당신은 바위 선택, 컴퓨터는 보 선택 : 당신이 졌습니다.\n");
	}
}

void myflush()
{
	while(getchar() != '\n')
	{
		;
	}
}
