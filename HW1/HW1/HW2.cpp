#include <stdio.h>

int main()
{
	int money = 278970;

	int m50000, m10000;
	int m5000, m1000;
	int m500, m100;
	int m50, m10;

	m50000 = money / 50000; 
	money -= 50000 * m50000;

	m10000 = money / 10000;
	money -= 10000 * m10000;

	m5000 = money / 5000;
	money -= 5000 * m5000;

	m1000 = money / 1000;
	money -= 1000 * m1000;

	m500 = money / 500;
	money -= 500 * m500;

	m100 = money / 100;
	money -= 100 * m100;

	m50 = money / 50;
	money -= 50 * m50;

	m10 = money / 10;
	money -= 10 * m10;

	printf("50000원권 ==> %d\n", m50000);
	printf("10000원권 ==> %d\n", m10000);
	printf("5000원권 ==> %d\n", m5000);
	printf("1000원권 ==> %d\n", m1000);
	printf("500원권 ==> %d\n", m500);
	printf("100원권 ==> %d\n", m100);
	printf("50원권 ==> %d\n", m50);
	printf("10원권 ==> %d\n", m10);

	return 0;
}