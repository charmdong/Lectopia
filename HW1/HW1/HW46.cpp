#include <stdio.h>

void input(char*,int*);
void odd_even(char *, int , int );
void output(char, int, int);
void flush();

int main()
{
	int start, end;
	int i,res;
	char choice;

	input("# 시작 값을 입력하시오 : ", &start);
	while (1)
	{
		input("# 끝 값을 입력하시오 : ", &end);
		if (end > start)
			break;
	}
	odd_even(&choice, start, end);
	output(choice, start, end);
	return 0;
	
}

void input(char* message,int *num)
{
	printf(message);
	if (scanf("%d", num) != 1)
	{
		flush();
		input(message,num);
	}
	return;
}

void odd_even(char *choice,int start, int end)
{
	while (1)
	{
		printf("* %d~%d 까지의 짝수의 합을 구할까요?", start, end);
		printf(" 홀수의 합을 구할까요?(짝수:e/홀수:o) : ");
		if (scanf(" %c", choice) == 1)
		{
			if (*choice == 'o' || *choice == 'e')
				break;
			else
				flush();
		}
		else
			flush();
	}
	return;
}

void output(char choice, int start, int end)
{
	int i;
	int total = 0;

	if (choice == 'e') // 짝수 합 계산
	{
		printf("  %d~%d 까지의 짝수(",start,end);
		for (i = start; i <= end; i++)
		{
			if (i % 2 == 0)
			{
				printf("%d ", i);
				total += i;
			}
		}
		printf("\b)의 합은 %d 입니다.\n", total);
	}
	else
	{
		printf("  %d~%d 까지의 홀수(",start,end);
		for (i =start; i <= end; i++)
		{
			if (i % 2 != 0)
			{
				printf("%d ", i);
				total += i;
			}
		}
		printf("\b)의 합은 %d 입니다.\n", total);
	}
	return;
}


void flush()
{
	while (getchar() != '\n') { ; }
}