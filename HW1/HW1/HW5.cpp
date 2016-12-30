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
	printf("전기 사용량을 입력하세요(kw) : ");
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
	printf("전기 사용요금은 %lf 원 입니다\n", total_use);
}