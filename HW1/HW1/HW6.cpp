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
	printf("화씨 온도를 입력하세요 : ");
	scanf("%d", &f_tem);
	return f_tem;
}

void output(int tem)
{
	double c_tem;
	c_tem = (double)5 / (double)9 * (tem - 32);
	printf("섭씨 온도는 %.1lf 도입니다.\n",c_tem);
}