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
			printf("���~ �¾Ҵ�~~~ ��ī��ī~~ %d ���� ���� ���߼̽��ϴ�.\n", cnt);
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
		printf("# ���ڸ� �Է��Ͻÿ� : ");
		if (scanf("%d", &num) == 1) // ���� �Է�
		{
			if (num >= 1 && num <= 100) // 1���� 100 ����
				break;
			else // ���� ��
				myflush();
		}
		else // ���� �Է�
			myflush();
	}
	return num;
}

void output(int rand,int num,int max,int min)
{	
	if (num > rand)
		printf("%d ���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", min, max);
	else if (num < rand)
		printf("%d ���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", min, max);
}

void myflush()
{
	while(getchar() != '\n')
	{
		;
	}
}