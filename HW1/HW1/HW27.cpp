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
			printf("* ���߸��� ������ �峭���� ���ÿ�~ ^^\n");
		else if (gram <= 500)
		{
			cnt++;
			printf("* ���� �ް��� �� : %d\n", cnt);
		}
		else // gram >500
			printf("* Ÿ���� ������ �峭���� ���ÿ�~ ^^\n");

		if (cnt == 10)
		{
			printf("\n*** �ް� ������ �������ϴ�.\n");
			break;
		}
	}
	return 0;
}

int input()
{
	int gram;
	printf("# ����� ���Ը� �Է��ϼ���(���� : g) : ");
	
	while (scanf("%d",&gram)!=1)
	{
		myflush();
		printf("# ����� ���Ը� �Է��ϼ���(���� : g) : ");
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