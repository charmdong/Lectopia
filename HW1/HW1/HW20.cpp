#include <stdio.h>

int input();
int cal_total(int);
int cal_tax(int);
void output(int, int);

int main()
{
	int time,gloss, tax, net;
	time = input();
	gloss = cal_total(time);
	tax = cal_tax(gloss);
	output(gloss, tax);
	return 0;
}

int input()
{
	int work_time;
	printf("* 1주일간의 근무시간을 입력하시오 : ");
	scanf("%d", &work_time);
	return work_time;
}

int cal_total(int time)
{
	int total;
	
	if (time <= 40)
		total = time * 3000;
	else // time > 40
		total = 40 * 3000 + (time - 40) * 3000 * 15 / 10;
	
	return total;
}

int cal_tax(int total)
{
	int tax;

	if (total <= 100000)
		tax = total * 15 / 100; // 형 변환 하지 않는 버전....
	else // total > 100000
		tax = 100000 * 15 / 100 + (total - 100000) * 25 / 100;

	return tax;
}

void output(int total, int tax)
{
	int net;
	net = total - tax;

	printf("# 총수입 : %d원\n", total);
	printf("# 세  금 : %d원\n", tax);
	printf("# 실수입 : %d원\n", net);

}