#include <stdio.h>

void printAge(int);
void printHeight(double);

int main()
{
	char name[20] = "정동건";
	int age = 500;
	double height = 181.1;

	printf("성명 : %s \n", name);
	printAge(age);
	printHeight(height);
	return 0;
}

void printAge(int age)
{
	printf("나이 : %d \n", age);
}

void printHeight(double height)
{
	printf("키 : %.1lf \n", height);
}