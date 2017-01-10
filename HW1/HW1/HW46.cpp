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

	input("# ���� ���� �Է��Ͻÿ� : ", &start);
	while (1)
	{
		input("# �� ���� �Է��Ͻÿ� : ", &end);
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
		printf("* %d~%d ������ ¦���� ���� ���ұ��?", start, end);
		printf(" Ȧ���� ���� ���ұ��?(¦��:e/Ȧ��:o) : ");
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

	if (choice == 'e') // ¦�� �� ���
	{
		printf("  %d~%d ������ ¦��(",start,end);
		for (i = start; i <= end; i++)
		{
			if (i % 2 == 0)
			{
				printf("%d ", i);
				total += i;
			}
		}
		printf("\b)�� ���� %d �Դϴ�.\n", total);
	}
	else
	{
		printf("  %d~%d ������ Ȧ��(",start,end);
		for (i =start; i <= end; i++)
		{
			if (i % 2 != 0)
			{
				printf("%d ", i);
				total += i;
			}
		}
		printf("\b)�� ���� %d �Դϴ�.\n", total);
	}
	return;
}


void flush()
{
	while (getchar() != '\n') { ; }
}