#include <stdio.h>

int main()
{
	double year = 365.2422;
	int day, hour, min;
	double sec;

	day = year / 1;
	year -= day;

	hour = year * 24;
	year = year * 24 - hour;
	
	min = 60 * year;
	year = year * 60 - min;
	
	sec = 60 * year;

	year = 365.2422;

	printf("%.4lf ���� %d �� %d �ð� %d �� %.2lf �� �Դϴ�.\n", year, day, hour, min, sec);
	return 0;
}