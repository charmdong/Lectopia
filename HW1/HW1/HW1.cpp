#include <stdio.h>

void printAge(int);
void printHeight(double);

int main()
{
	char name[20] = "������";
	int age = 500;
	double height = 181.1;

	printf("���� : %s \n", name);
	printAge(age);
	printHeight(height);
	return 0;
}

void printAge(int age)
{
	printf("���� : %d \n", age);
}

void printHeight(double height)
{
	printf("Ű : %.1lf \n", height);
}