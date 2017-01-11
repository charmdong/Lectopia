#include <stdio.h>

void input(double *);
double max_calc(double*);
double min_calc(double *);
void flush();

int main()
{
	double num[5] = { 0 };
	double max,min;
	input(num);
	max = max_calc(num);
	min = min_calc(num);
	
	printf("\n");
	printf("���� ū �� : %.2lf\n", max);
	printf("���� ���� �� : %.2lf\n\n", min);
	return 0;
}

void input(double *num)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		while (1)
		{
			printf("%d �� �� �� : ", i);
			if (scanf("%lf", &num[i]) == 1)
				break;
			else
				flush();
		}
	}
}

double max_calc(double *num)
{
	double max = num[0];
	int i;
	int res = 0;
	for (i = 0; i < 5; i++)
	{
		if (num[i] > max)
		{
			max = num[i];
			res = i;
		}
	}
	return num[res];
}

double min_calc(double *num)
{
	double min = num[0];
	int i;
	int res = 0;
	for (i = 0; i < 5; i++)
	{
		if (num[i] < min)
		{
			min = num[i];
			res = i;
		}
	}
	return num[res];
}

void flush()
{
	while (getchar() != '\n') { ; }
}