#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int random(int);
int input();
void output(int,int,int,int);
void myflush();

int main()
{
	int res,num;
	int max = 101, min = 0, cnt = 1;

	srand((unsigned int)time(NULL));
	res = random(100);

	while (1)
	{
		num = input();
		if (num == res)
		{
			printf("우와~ 맞았당~~~ 추카추카~~ %d 번쨰 만에 맞추셨습니다.\n", cnt);
			break;
		}
		else if (num > res)
			(num < max) ? max = num : max = max;
		else
			(num > min) ? min = num : min = min;
		output(res,num,max,min);
		cnt++;
	}
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
		printf("# 숫자를 입력하시오 : ");
		if (scanf("%d", &num) == 1) // 정상 입력
		{
			if (num >= 1 && num <= 100) // 1에서 100 사이
				break;
			else // 범위 밖
				myflush();
		}
		else // 문자 입력
			myflush();
	}
	return num;
}

void output(int rand,int num,int max,int min)
{	
	if (num > rand)
		printf("%d 보다는 크고 %d 보다는 작습니다.\n", min, max);
	else if (num < rand)
		printf("%d 보다는 크고 %d 보다는 작습니다.\n", min, max);
}

void myflush()
{
	while(getchar() != '\n')
	{
		;
	}
}