#include <stdio.h>

int input();
void output(int);

int main()
{
	int kw;
	kw = input();
	output(kw);
	return 0;
}

int input()
{
	int use;
	printf("���� ��뷮�� �Է��ϼ���(kw) : ");
	scanf("%d", &use);
	return use;
}

void output(int kw)
{
	int base = 660;
	double total_fee, total_use;
	double kw_fee = 88.5;
	total_fee = base + (kw * kw_fee);
	total_use = total_fee + total_fee * 9 / 100;
	printf("���� ������� %lf �� �Դϴ�\n", total_use);
}