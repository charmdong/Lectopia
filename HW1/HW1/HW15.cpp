#include <stdio.h>

double input_weight();
double input_height();
double bmi_ac(double,double);
void output(double);

int main()
{
	double kg;
	double m;
	double bmi_index;
	kg = input_weight();
	m = input_height();
	bmi_index = bmi_ac(kg, m);
	output(bmi_index);
	return 0;
}

double input_weight()
{
	double weight;
	
	printf("몸무게를 입력하세요(kg) : ");
	scanf("%lf", &weight);

	return weight;
}

double input_height()
{
	double height;

	printf("키를 입력하세요(m) : ");
	scanf("%lf", &height);

	return height;
}

double bmi_ac(double x,double y)
{
	double bmi;
	bmi = x / (y*y);

	return bmi;
}

void output(double x)
{
	if (x < 18.5)
		printf("당신은 BMI지수는 %.1lf으로 저체중입니다.\n",x);
	else if(x >=18.5 && x<25.0)
		printf("당신은 BMI지수는 %.1lf으로 정상체중입니다.\n", x);
	else if(x>= 25.0 && x<30.0)
		printf("당신은 BMI지수는 %.1lf으로 과체중입니다.\n", x);
	else if(x>=30.0 && x<40.0)
		printf("당신은 BMI지수는 %.1lf으로 비만입니다.\n", x);
	else if(x>40.0)
		printf("당신은 BMI지수는 %.1lf으로 고도비만입니다.\n", x);
}
