#include <stdio.h>

int input();
void output(int);

int main()
{
	int tem;
	tem = input();
	output(tem);
	return 0;
}

int input()
{
	int f_tem;
	printf("ȭ�� �µ��� �Է��ϼ��� : ");
	scanf("%d", &f_tem);
	return f_tem;
}

void output(int tem)
{
	double c_tem;
	c_tem = (double)5 / (double)9 * (tem - 32);
	printf("���� �µ��� %.1lf ���Դϴ�.\n",c_tem);
}