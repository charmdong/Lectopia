#include <stdio.h>

void printAge(int);			// printAge 함수 선언부
void printHeight(double); // printHeight 함수 선언부

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

void printAge(int age) // printAge 함수 정의부 parameter : int형 변수
{
	printf("나이 : %d \n", age);
}

void printHeight(double height) // printHeight 함수 정의부 parameter : double형 변수
{
	printf("키 : %.1lf \n", height);
}