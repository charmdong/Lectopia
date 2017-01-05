#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int);
int input();
void output(int,int);
int win_case(int, int);
int lose_case(int, int);
int draw_case(int, int);
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
	
		win += win_case(res, num);
		lose += lose_case(res, num);
		draw += draw_case(res, num);
		
		if (lose == 1)
			break;
	}
	printf("\n\t############################\n");
	printf("\t### ���Ӱ�� : %d �� %d �� ###\n", win, draw);
	printf("\t############################\n");
	return 0;
}

int random(int n)
{
	int res;
	res = rand() % (n + 1);

	if (res == 0)
		res = random(n);

	return res;
}

int input()
{
	int num;
	printf("# ������ 1, ������ 2, ���� 3 �߿��� �����ϼ��� : ");
	
	while (1)
	{
		if (scanf("%d", &num) == 1) // ���� �Է�
		{
			if (num >= 1 && num <= 3) // ���� �Է�
				break;
			else
				myflush();
		}
		else // ���� �Է�
			myflush();
	}
	return num;
}

void output(int res, int num)
{
	if (num == res) // ��� ���
	{
		if (num == 1)
			printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n");
		else if(num ==2)
			printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n");
		else // num ==3
			printf("����� �� ����, ��ǻ�ʹ� �� ���� : �����ϴ�.\n");
	}
	else // �ºΰ� �� ���....
	{
		if(num == 1 && res == 2) 
			printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �̰���ϴ�.\n");
		else if(num == 2 && res == 3)
			printf("����� ���� ����, ��ǻ�ʹ� �� ���� : �̰���ϴ�.\n");
		else if(num == 3 && res == 1)
			printf("����� �� ����, ��ǻ�ʹ� ���� ���� : �̰���ϴ�.\n");
		//====================================
		else if(num == 2 && res == 1)
			printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : ����� �����ϴ�.\n");
		else if(num == 3 && res == 2)
			printf("����� �� ����, ��ǻ�ʹ� ���� ���� : ����� �����ϴ�.\n");
		else
			printf("����� ���� ����, ��ǻ�ʹ� �� ���� : ����� �����ϴ�.\n");
	}
}

int win_case(int res, int num)
{
	if ((num == 1 && res == 2) || (num == 2 && res == 3) || (num == 3 && res == 1))
		return 1;
	else
		return 0;
}

int lose_case(int res, int num)
{
	if ((num == 2 && res == 1) || (num == 3 && res == 2) || (num == 1 && res == 3))
		return 1;
	else
		return 0;
}

int draw_case(int res, int num)
{
	if (res == num)
		return 1;
	else
		return 0;
}

void myflush()
{
	while(getchar() != '\n')
	{
		;
	}
}
