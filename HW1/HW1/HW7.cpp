#include <stdio.h>

int main()
{
	double km;
	double speed;
	double time;
	int hour, min;
	double sec;
	
	printf("* �Ÿ��� �Է��Ͻÿ�(km����) : ");
	scanf("%lf", &km);
	
	printf("* �ü��� �Է��Ͻÿ�(km/h����) : ");
	scanf("%lf", &speed);

	time = km / speed; // �ð�

	hour = time;
	
	time -= hour;
	min = time * 60;

	time = time *60 - min;
	sec = time * 60;
	
	printf("%.2lf km => %d�ð� %d�� %.3lf�� �ҿ��\n", km,hour,min,sec);
	return 0;
}