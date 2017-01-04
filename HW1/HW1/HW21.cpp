#include <stdio.h>

int main()
{
	double hgt;
	double sum = 0;
	int i = 1;
	while (i <= 5)
	{
		printf("- %d 번 학생의 키는 ? ", i);
		scanf("%lf", &hgt);
		sum += hgt;
		i++;
	}
	printf("다섯 명의 평균 키는 %.1lf cm 입니다.\n", sum/5);
	return 0;
}