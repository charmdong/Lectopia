#include <stdio.h>

int input(int *, int*, int*);
int yearCheck(int);
int errorCheck(int year, int month, int day);
int monthCheck(int month);
int totalCalc(int year, int month, int day);
void output(int, int, int, int);
void flush();

int main()
{
	int year, month, day;
	int res_in;
	int total;

	while (1)
	{
		res_in = input(&year, &month, &day);
		if (res_in != 3) // �ϳ��� ���� �Է½�
			break;
		else // ���� �Է½�
		{
			if (errorCheck(year, month, day) == 0) // ���� �Է�
			{
				total = totalCalc(year, month, day);
				output(year, month, day, total);
			}
			else // ���� ������ �Է�
			{
				printf("\n*** ���� �����͸� �Է��ϼ̽��ϴ� ***\n\n");
				flush();
			}
		}
	}
	
	return 0;
}

int input(int *year, int *month, int *day)
{
	int res;
	printf("* �� �� ���� �Է��Ͻÿ� : ");
	res = scanf("%d %d %d", year, month, day);
	return res;
}

int yearCheck(int year) // 1 : ���� , 0 : ���
{
	if (year % 4 == 0) // 4�� ������ �������� ���
	{
		if (year % 100 == 0) // 100���� ������ �������� ���
		{
			if (year % 400 == 0) // ������ ���
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

int errorCheck(int year, int month, int day) // 0 : ����, -1 : ���Է�
{
	if (year < 1900)
		return -1;
	else
	{
		if (month >= 1 && month <= 12)
		{
			if (monthCheck(month) == 1)
			{
				if (day > 31 || day < 0)
					return -1;
				else
					return 0;
			}
			else if (monthCheck(month) == 0)
			{
				if (day > 30 || day < 0)
					return -1;
				else
					return 0;
			}
			else // 2���� ���
			{
				if (yearCheck(year) == 1) // ����
				{
					if (day > 29 || day < 0)
						return -1;
					else
						return 0;
				}
				else // ���
				{
					if (day > 28 || day < 0)
						return -1;
					else
						return 0;
				}
			}
		}
		else
			return -1;
	}
}

int monthCheck(int month) // 31�� - 1, 30�� - 0, 2�� - 2 ����
{
	if (month == 2)
		return -2;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return 0;
	else
		return 1;
}

int totalCalc(int year, int month, int day)
{
	int maxOrigin[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int maxLeap[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int i;
	int total = 0;
	for (i = 1900; i < year; i++)
	{
		if (yearCheck(i) == 1) // ����
			total += 366;
		else
			total += 365;
	}
	
	if (yearCheck(year) == 1) // ��
	{
		for (i = 1; i < month; i++)
			total += maxLeap[i-1];
	}
	else // ��
	{
		for (i = 1; i < month; i++)
			total += maxOrigin[i-1];
	}
	
	total += day;
	return total;
}

void output(int year, int month, int day, int total)
{
	char str[7][3] = { "��","��","ȭ","��","��","��","��" };
	int i;
	int res;
	res = total % 7;
	printf("###################################\n");
	printf("# %d�� %2d�� %2d���� %s�����Դϴ� #\n", year, month, day, str[res]);
	printf("###################################\n\n");
	return;
}

void flush()
{
	while (getchar() != '\n') { ; }
}