#include <stdio.h>

int main()
{
	double hgt;
	double sum = 0;
	int i = 1;
	while (i <= 5)
	{
		printf("- %d �� �л��� Ű�� ? ", i);
		scanf("%lf", &hgt);
		sum += hgt;
		i++;
	}
	printf("�ټ� ���� ��� Ű�� %.1lf cm �Դϴ�.\n", sum/5);
	return 0;
}