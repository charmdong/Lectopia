#include <stdio.h>

unsigned char openFan(unsigned char);
unsigned char closeFan(unsigned char);
unsigned char reverseFan(unsigned char);
int inputStr(char*);
int menu();
void displayFan(unsigned char);
int getBit(unsigned char, int);
unsigned char setBit(unsigned char, int);
unsigned char clearBit(unsigned char, int);
void flush();

int main()
{
	int choice;
	unsigned char ch=0;
	
	while (1)
	{
		choice = menu();
		switch (choice)
		{
		case 1: ch = openFan(ch); displayFan(ch); break;
		case 2: ch = closeFan(ch); displayFan(ch); break;
		case 3: ch = reverseFan(ch); displayFan(ch); break;
		case 4: printf("\n# 프로그램을 종료합니다 #\n\n"); break;
		}
		if (choice == 4)
			break;
	}
	return 0;
}

int menu()
{
	int choice,res;
	
	printf("1. 환풍구 열기 / 2. 환풍구 닫기 / 3. 환풍구 전체 전환 / 4. 종료 : ");
	while (1)
	{
		while (1)
		{
			res = scanf("%d", &choice);
			if (res == 1 && getchar() == '\n') // 정상 입력
				break;
			else
			{
				printf("\n## 1~4번 중에서 선택해주십시오 : ");
				flush();
			}
		}
		if (choice >= 1 && choice <= 4) 
			break;
		else 
			printf("\n## 1~4번 중에서 선택해주십시오 : ");
	}
	return choice; // 1~4번만 리턴된다.
}

unsigned char openFan(unsigned char fan)
{
	printf("---------------------------------------------------------------\n");
	printf("\t\tFan 열기 작업 실행 화면\n");
	printf("---------------------------------------------------------------\n");
	int i = inputStr("* OPEN할 FAN 번호를 입력하시오(1-8) : ");
	printf("---------------------------------------------------------------\n");
	if ((fan & (1 << (i-1))) == 0)
	{
		fan |= (1 << (i-1));
		return fan;
	}
	else
		return fan;
}

unsigned char closeFan(unsigned char fan)
{
	printf("---------------------------------------------------------------\n");
	printf("\t\tFan 닫기 작업 실행 화면\n");
	printf("---------------------------------------------------------------\n");
	int i = inputStr("* CLOSE할 FAN 번호를 입력하시오(1-8) : ");
	printf("---------------------------------------------------------------\n");
	if ((fan & (1 << (i-1))) == 0)
		return fan;
	else
	{
		fan ^= (1 << (i-1));
		return fan;
	}
}

int inputStr(char* message)
{
	int num,res;
	printf(message);
	while (1)
	{
		while (1)
		{
			res = scanf("%d", &num);
			if (res == 1 && getchar() == '\n') // 정상 입력
				break;
			else
			{
				printf("\n## 1~8번째 중에서 선택해주십시오 : ");
				flush();
			}
		}
		if (num >= 1 && num <= 8)
			break;
		else
			printf("\n## 1~8번째 중에서 선택해주십시오 : ");
	}
	return num; // 1~8번만 리턴된다.
}

unsigned char reverseFan(unsigned char ch) // on,off 상태를 바꿔버리는 함수
{
	int res;
	int cnt=7;
	printf("---------------------------------------------------------------\n");
	printf("\t\tFan 전체 전환 작업 실행 화면\n");
	printf("---------------------------------------------------------------\n");
	while (cnt>=0)
	{
		res = getBit(ch, cnt); // 각자리의 비트 확인 0 or 1
		if (res == 0) // 특정 위치 비트가 0인 경우
			ch = setBit(ch, cnt); // 1로 변경
		else
			ch = clearBit(ch, cnt);
		cnt--;
	}
	return ch;
}

int getBit(unsigned char num, int i) // 특정 위치 비트 체크 ( 0 또는 1 )
{
	if ((num >> i) & 1 == 1) // 특정 비트가 1인 경우
		return 1;
	else 
		return 0;
}

void displayFan(unsigned char ch)
{
	int res;
	int cnt = 7;
	int i = 8;
	
	while (i)
	{
		printf("%d번 FAN\t", i);
		i--;
	}
	printf("\n");
	
	while (cnt >= 0)
	{
		res = getBit(ch, cnt);
		if (res == 1)
			printf("%4s\t", "ON");
		else
			printf("%5s\t", "OFF");
		cnt--;
	}
	printf("\n---------------------------------------------------------------\n\n");
	return;
}

unsigned char setBit(unsigned char num, int i) // 특정 자리 비트를 1로 변경하는 함수
{
	if ((num & (1 << i)) == 0) // 특정 비트가 0인 경우
	{
		num |= (1 << i);
		return num;
	}
	else // 특정 비트가 1인 경우
		return num;
}

unsigned char clearBit(unsigned char num, int i) // 특정 자리 비트를 0으로 변경하는 함수
{
	if ((num & (1 << i)) == 0) // 특정 비트가 0인 경우
		return num;
	else // 특정 비트가 1인 경우
	{
		num ^= (1 << i);
		return num;
	}
}

void flush()
{
	while (getchar() != '\n') { ; }
}