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
	
	num = inputUnit("* 양의 정수 밑을 입력 하시오 : ");
	n = inputUnit("* 양의 승을 입력 하시오 : ");
	res = ipow(num, n);
	printf("%d의 %d승은 %d입니다.\n\n", num, n, res);

	num2 = inputDouble("* 양의 실수 밑을 입력 하시오 : ");
	n2 = inputUnit("* 양의 승을 입력 하시오 : ");
	res2 = fpow(num2, n2);
	printf("%.2lf의 %d승은 %.3lf입니다.\n\n", num2, n2, res2);

	return 0;
}

int inputUnit(char* message) // 양의 정수 값 리턴
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
				printf("# 잘못 입력하셨습니다. 다시 입력해주세요 : ");
				flush();
			}
		}
		if (res == 1 && num >= 0) // 양수 값 정상 입력
			break;
		else if (res == 1 && num < 0) // 음수 입력 시
			printf("# 잘못 입력하셨습니다. 다시 입력해주세요 : ");
		else // 문자 입력시
		{
			printf("# 잘못 입력하셨습니다. 다시 입력해주세요 : ");
			flush();
		}
	}
	return num;
}

double inputDouble(char* message) // 양의 실수 값 리턴
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
				printf("# 잘못 입력하셨습니다. 다시 입력해주세요 : ");
				flush();
			}
		}
		if (res == 1 && num >= 0) // 양수 값 정상 입력
			break;
		else if (res == 1 && num < 0) // 음수 입력 시
			printf("# 잘못 입력하셨습니다. 다시 입력해주세요 : ");
		else // 문자 입력시
		{
			printf("# 잘못 입력하셨습니다. 다시 입력해주세요 : ");
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