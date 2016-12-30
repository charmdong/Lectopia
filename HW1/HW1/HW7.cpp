#include <stdio.h>

int main()
{
	double km;
	double speed;
	double time;
	int hour, min;
	double sec;
	
	printf("* 거리를 입력하시오(km단위) : ");
	scanf("%lf", &km);
	
	printf("* 시속을 입력하시오(km/h단위) : ");
	scanf("%lf", &speed);

	time = km / speed; // 시간

	hour = time;
	
	time -= hour;
	min = time * 60;

	time = time *60 - min;
	sec = time * 60;
	
	printf("%.2lf km => %d시간 %d분 %.3lf초 소요됨\n", km,hour,min,sec);
	return 0;
}