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
		printf("# �������� �Է��ϼ��� : ");

		if (scanf("%d", &num) == 1) // ���� �Է��� ���
			break;
		else // ���� �Է��� ���
			myflush(); // ���� ����
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