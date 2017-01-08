#include <stdio.h>

char menu();
int deposit(int, int);
int withdraw(int, int);
void flush();

int main()
{
	char choice;
	int num=0;
	int total = 0;
	
	printf("* 현재 잔액은 %d원 입니다.\n\n",total);
	while (1)
	{
		choice = menu();
		switch (choice)
		{
			case 'i' : total = deposit(num, total); break;
			case 'o': total = withdraw(num, total); break;
			case 'q': printf("\n## 프로그램을 종료합니다. ##\n\n"); break;
			default : printf("이 경우가 걸릴 일은 없다.\n");
		}
		flush();
		if (choice == 'q')
			break;
	}
	return 0;
}

char menu()
{
	char choice;
	
	while (1)
	{
		printf("# 메뉴를 선택하시오(i-입금, o-출금, q-종료) : ");
		if (scanf("%c", &choice) == 1)
		{
			if (choice == 'i' || choice == 'o' || choice == 'q') // 정상 입력
				break;
			else
			{
				printf("* 잘못 입력하셨습니다.\n\n");
				flush();
			}
		}
		else
		{
			printf("* 잘못 입력하셨습니다.\n\n");
			flush();
		}
	}

	return choice;
}

int inputInt(char* message) // 정수값만 리턴
{
	int num;
	printf(message);
	
	while (scanf("%d", &num) != 1) // 문자 입력시
	{
		flush();
		printf("* 잘못 입력하셨습니다. 다시 입력하십시오 : ");
	}
	
	return num;
}

int deposit(int num, int total)
{
	num = inputInt("# 입금액을 입력하세요 : ");
	
	while (num < 0)
		num = inputInt("* 잘못 입력하셨습니다. 다시 입력하십시오 : ");
	
	total += num;
	printf("* 현재 잔액은 %d원 입니다.\n\n", total);
	return total;
}

int withdraw(int num, int total) // 출금
{
	num = inputInt("# 출금액을 입력하세요 : ");
	
	while (num < 0)
		num = inputInt("* 잘못 입력하셨습니다. 다시 입력하십시오 : ");

	if (total < num)
		printf("* 잔액이 부족합니다.\n");
	else
		total -= num;

	printf("* 현재 잔액은 %d원 입니다.\n\n", total);
	return total;
}

void flush()
{
	while (getchar() != '\n') {
		;
	}
}