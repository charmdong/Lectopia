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
	printf("���尴�� ���̸� �Է��Ͻÿ� : ");
	scanf("%d", &age);
	return age;
}

int input_num()
{
	int num;
	printf("���尴�� ���� �Է��Ͻÿ� : ");
	scanf("%d", &num);
	return num;
}

void output(int x, int y)
{
	int fee;
	int sale=0;
	int total=0;

	if (x > 0 && x <= 7)
		fee = 500;
	else if (x > 7 && x <= 13)
		fee = 700;
	else if (x > 13 && x <= 19)
		fee = 1000;
	else if (x > 19 && x <= 55)
		fee = 1500;
	else if (x > 55)
		fee = 500;
	else
		printf("ERROR\n");

	if (y < 5)
	{
		fee = fee * y;
		total = fee;
	}
	else
	{
		fee = fee * y;
		total = fee;
		sale = fee * 10 / 100;
		total = total - sale;
	}
	printf("����� => %d��\n", fee);
	printf("���αݾ� => %d��\n", sale);
	printf("�����ݾ� => %d��\n", total);
}