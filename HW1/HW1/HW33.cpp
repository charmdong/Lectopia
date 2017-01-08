#include <stdio.h>

int inputUnit(char*);
double inputDouble(char*);
int ipow(int, int);
double fpow(double, int);
void flush();

int main()
{
	int num, n, res,n2;
	double num2,  res2;
	
	num = inputUnit("* ���� ���� ���� �Է� �Ͻÿ� : ");
	n = inputUnit("* ���� ���� �Է� �Ͻÿ� : ");
	res = ipow(num, n);
	printf("%d�� %d���� %d�Դϴ�.\n\n", num, n, res);

	num2 = inputDouble("* ���� �Ǽ� ���� �Է� �Ͻÿ� : ");
	n2 = inputUnit("* ���� ���� �Է� �Ͻÿ� : ");
	res2 = fpow(num2, n2);
	printf("%.2lf�� %d���� %.3lf�Դϴ�.\n\n", num2, n2, res2);

	return 0;
}

int inputUnit(char* message) // ���� ���� �� ����
{
	int num, res;
	printf(message);
	
	while (1)
	{
		while (1)
		{
			res = scanf("%d", &num);
			if (getchar() == '\n') 
				break;
			else
			{
				printf("# �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ��� : ");
				flush();
			}
		}
		if (res == 1 && num >= 0) // ��� �� ���� �Է�
			break;
		else if (res == 1 && num < 0) // ���� �Է� ��
			printf("# �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ��� : ");
		else // ���� �Է½�
		{
			printf("# �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ��� : ");
			flush();
		}
	}
	return num;
}

double inputDouble(char* message) // ���� �Ǽ� �� ����
{
	double num;
	int res;
	printf(message);

	while (1)
	{
		while (1)
		{
			res = scanf("%lf", &num);
			if (getchar() == '\n')
				break;
			else
			{
				printf("# �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ��� : ");
				flush();
			}
		}
		if (res == 1 && num >= 0) // ��� �� ���� �Է�
			break;
		else if (res == 1 && num < 0) // ���� �Է� ��
			printf("# �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ��� : ");
		else // ���� �Է½�
		{
			printf("# �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ��� : ");
			flush();
		}
	}
	return num;
}

int ipow(int num, int n)
{
	int tmp;
	if (num == 0)
		num = 0;
	else if (num != 0 && n == 0)
		num = 1;
	else
	{
		tmp = num;
		while (n-1)
		{
			num *= tmp;
			n--;
		}
	}
	return num;
}

double fpow(double num, int n)
{
	double tmp;
	if (num == 0)
		num = 0;
	else if (num != 0 && n == 0)
		num = 1;
	else
	{
		tmp = num;
		while (n-1)
		{
			num *= tmp;
			n--;
		}
	}
	return num;
}

void flush()
{
	while (getchar() != '\n') { ; }
}