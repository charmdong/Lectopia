#include <stdio.h>

int main()
{
	int time = 54321; // second

	int hour, min, sec; 

	hour = time / 3600;
	time -= hour * 3600;

	min = time / 60;
	time -= min * 60;

	sec = time;

	printf("54321�ʴ� %d�ð� %d�� %d���Դϴ�.\n", hour, min, sec);
	return 0;
	
}