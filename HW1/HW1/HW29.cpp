#include <stdio.h>

int transNumber(int);
void output(int, int, int);
int gozipCnt(int);
int inputUnit(char*);
void myflush();

int main()
{
	int num;
	int start, end;
	
	start = inputUnit("���� ��(P1) : ");
	end = inputUnit("�� ��(P2) : ");
	num = inputUnit("������(N) : ");
	output(start, end, num);

	return 0;
}

int transNumber(int num) // �ڸ��� ���� �� ���� ��ȯ �Լ�
{
	int n1, n2, n3, n4;
	if (num < 1000) // 3�ڸ� ���� ���
	{
		n1 = num / 100;
		n2 = (num - n1 * 100) / 10;
		n3 = num - (n1 * 100 + n2 * 10);
		if (n1 != 0)
			num = n1*n2*n3;
		else if (n2 != 0) // n1==0
			num = n2*n3;
		else // n1==0 , n2==0
			num = n3;
	}
	else if (num < 10000) //4�ڸ� ���� ���
	{
		n1 = num / 1000; // 1000�ڸ�
		n2 = (num - n1 * 1000) / 100;
		n3 = (num - (n1 * 1000 + n2 * 100)) / 10;
		n4 = num - (n1 * 1000 + n2 * 100 + n3 * 10);
	
		if (n1 != 0) // 4�ڸ��� ���
			num = n1*n2*n3*n4;
		else if (n2 != 0) // n1==0 3�ڸ��� ���
			num = n2*n3*n4;
		else if (n3 != 0) // n1==0, n2==0
			num = n3*n4;
		else 
			num = n4;
	}
	else // num == 10000
		return 0;

	return num;
}

int gozipCnt(int num) // ������ ��ȯ�ϴ� �Լ�
{
	int cnt = 0;

	while (num>=10)
	{
		num = transNumber(num);
		cnt++;
	}
	return cnt;
}

void output(int start, int end, int num)
{
	int res;
	int cnt = 0;
	printf("�������� %d�� ���� ���\n",num);
	while (start != (end + 1))
	{
		res = gozipCnt(start); // start~end������ ������
		if (res == num)
		{
			printf("# %d #\n", start);
			cnt++;
		}
		start++;
	}
	printf("�� ���� : %d��\n",cnt);
}

int inputUnit(char* message) // �Է��Լ�
{
	int num;
	while (1)
	{
		printf(message);
		if (scanf("%d", &num) == 1) // ���� �Է�
		{
			if ((num >= 100 && num <= 10000) ||(num>=1&&num<=10)) // ���� �Է� ���
				break;
			else // ���� �� �Է�
				myflush();
		}
		else // ���� �Է�
			myflush();
	}
	return num;
}

void myflush() {
	while (getchar() != '\n') { ;}
}