#include <stdio.h>

int main()
{
	unsigned int his, liter, art;
	int total = 0;
	double avg = 0;

	printf("����, ����, ���� ������ �Է��ϼ��� : ");
	scanf("%d %d %d", &his, &liter, &art);

	total = his + liter + art;
	avg = (double)total / 3;
	printf("������ %d �̰� ����� %.2lf �Դϴ�.\n", total, avg);
	return 0;
}