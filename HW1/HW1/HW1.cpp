#include <stdio.h>

void printAge(int);			// printAge �Լ� �����
void printHeight(double); // printHeight �Լ� �����

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

void printAge(int age) // printAge �Լ� ���Ǻ� parameter : int�� ����
{
	printf("���� : %d \n", age);
}

void printHeight(double height) // printHeight �Լ� ���Ǻ� parameter : double�� ����
{
	printf("Ű : %.1lf \n", height);
}