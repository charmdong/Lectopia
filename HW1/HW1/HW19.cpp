#include <stdio.h>

int input();
int yearCheck(int);
void output(int, int);

int main()
{
	int year;
	int res;
	year = input();
	res = yearCheck(year);
	output(year, res);
	return 0;
}

int input()
{
	int year;
	printf("�⵵�� �Է��Ͻÿ� : ");
	scanf("%d", &year);
	return year;
}

int yearCheck(int x)
{
	if (x % 4 == 0) // 4�� ������ �������� ���
	{
		if (x % 100 == 0) // 100���� ������ �������� ���
		{
			if (x % 400 == 0) // ������ ���
				return 1;
			else // ����� ���
				return 0;
		}
		else // 100���� ������ �������� �ʴ� ��� - ����
			return 1;
	}
	else // 4�� ������ �������� �ʴ� ��� - ���
		return 0;
}

void output(int year, int result)
{
	if (result == 1) // ������ ���
		printf("%d���� ����(Leap year)�Դϴ�.\n",year);
	else // ����� ���
		printf("%d���� ���(Common year)�Դϴ�.\n",year);
}