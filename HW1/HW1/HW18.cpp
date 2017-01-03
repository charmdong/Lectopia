#include <stdio.h>

int input_age();
int input_num();
void output(int, int);

int main()
{
	int ag; // age
	int n; // num
	ag = input_age();
	n = input_num();
	output(ag, n);
	return 0;
}

int input_age()
{
	int age;
	printf("입장객의 나이를 입력하시오 : ");
	scanf("%d", &age);
	return age;
}

int input_num()
{
	int num;
	printf("입장객의 수를 입력하시오 : ");
	scanf("%d", &num);
	return num;
}

void output(int x, int y)
{
	int fee; // 입장료
	int sale; // 할인금액 : fee * 0.1
	int total; // 결제금액 : fee-sale

	if (x <= 7)
		fee = 500;
	else if (x <= 13)
		fee = 700;
	else if (x <= 19)
		fee = 1000;
	else if (x <= 55)
		fee = 1500;
	else // x > 55
		fee = 500;
	

	if (y < 5)
	{
		fee = fee * y; 
		sale = 0;
		total = fee;
	}
	else // y >=5 
	{
		fee = fee * y; 
		sale = fee * 10 / 100;
		total = fee - sale;
	}
	printf("입장료 => %d원\n", fee);
	printf("할인금액 => %d원\n", sale);
	printf("결제금액 => %d원\n", total);
}