#include <stdio.h>
#include <string.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define RESIDENT_NUMBER_LENGTH  13 /* 주민등록번호 길이*/
int availabilityCheck(char *resident_number);
int checkLengthCharacter(char *resident_number);
int checkDate(char *resident_number);
int checkIdentification(char *resident_number);
int checkGender(char *resident_number);
int checkYear(int year);

int main()
{
	/* 테스트할 주민등록번호 저장 배열*/
	char resident_number[][20] = { "0402291000008", "870401102321", "00031541949179",
		"0003154194917", "801203#201122", "7804155328845", "7804150328840",
		"9612241068382", "9902292194322", "0230174326176", "8811391042219",
		"8100122042213", "8112002042213", "9210101069415", "0802294012345",
		"8806311069417","8807311069418" };
	int i, count;
	/* 검사할 주민등록번호의 개수 계산*/
	count = sizeof(resident_number) / sizeof(resident_number[0]);
	for (i = 0; i<count; i++) /* 주민등록번호 유효성 검사를 반복적으로 수행 함*/
	{
		if (availabilityCheck(resident_number[i]) == TRUE)
		{
			printf("(+) 주민번호%s는(은) 유효한 번호입니다.\n", resident_number[i]);
		}
		else
		{
			printf("(-) 주민번호%s는(은) 유효하지 않은 번호입니다.\n", resident_number[i]);
		}
	}
	return 0;
}

int availabilityCheck(char *resident_number)
{
	int res = 0;
	res += checkLengthCharacter(resident_number);
	res += checkDate(resident_number);
	res += checkGender(resident_number);
	res += checkIdentification(resident_number);
	if (res == 4)
		return TRUE;
	else
		return FALSE;
}

int checkLengthCharacter(char *resident_number)
{
	int len, i;
	len = strlen(resident_number);
	if (len == RESIDENT_NUMBER_LENGTH)
	{
		for (i = 0; i < RESIDENT_NUMBER_LENGTH; i++)
		{
			if (resident_number[i] >= '0' && resident_number[i] <= '9')
				return TRUE;
			else
				return FALSE;
		}
	}
	else
		return FALSE;
}

int checkDate(char *resident_number) // 윤평년 계산 후, 월 일 판단
{
	int year=0,month,day;
	int i;
	
	if (resident_number[0] == '0') // 0으로 시작하는 주민번호
	{
		if (resident_number[6] == '1' || resident_number[6] == '2') // 1900년대생
			year = 1900 + (resident_number[1] - '0');
		else // 2000년대생
			year = 2000 + (resident_number[1] - '0');
	}
	else if (resident_number[0] == 1) // 1로 시작하는 주민번호
	{
		if (resident_number[1] - '0' < 8) 
		{
			if (resident_number[6] == '1' || resident_number[6] == '2') // 1900년대생
				year = 1910 + (resident_number[1] - '0');
			else // 2000년대생
				year = 2010 + (resident_number[1] - '0');
		}
	}
	else // 1900년대생
		year = 1900 + (resident_number[0] - '0') * 10 + (resident_number[1] - '0');
	
	month = (resident_number[2] - '0') * 10 + (resident_number[3] - '0');
	day = (resident_number[4] - '0') * 10 + (resident_number[5] - '0');
	if (month>=1 && month <= 12) // 월 정상 입력인 경우
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			// 31일인 달의 경우
		{
			if (day>=1 && day <= 31)
				return TRUE;
			else
				return FALSE;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) // 30일인 경우
		{
			if (day>=1 && day <= 30)
				return TRUE;
			else
				return FALSE;
		}
		else // 2월의 경우
		{
			if (checkYear(year)) // 윤년
			{
				if (day>=1 && day < 30)
					return TRUE;
				else
					return FALSE;
			}
			else // 평년
			{
				if (day>=1 && day < 29)
					return TRUE;
				else
					return FALSE;
			}
		}
	}
	else // 월 비정상입력
		return FALSE;
}

int checkIdentification(char *resident_number) // 
{
	int i;
	int iden=0;
	for (i = 0; i < RESIDENT_NUMBER_LENGTH-1; i++)
		iden += (resident_number[i] - '0');
	if (resident_number[12]-'0' == iden % 10)
		return TRUE;
	else
		return FALSE;
}

int checkGender(char *resident_number) // 7번째 자리가 1~4이면 TRUE
{
	if (resident_number[6] >= '1' && resident_number[6] <= '4')
		return TRUE;
	else
		return FALSE;
}


int checkYear(int year)
{
	if (year % 4 == 0) // 4로 나누어 떨어지는 경우
	{
		if (year % 100 == 0) // 100으로 나누어 떨어지는 경우
		{
			if (year % 400 == 0) // 윤년의 경우
				return TRUE;
			else // 평년의 경우
				return FALSE;
		}
		else // 100으로 나누어 떨어지지 않는 경우 - 윤년
			return TRUE;
	}
	else // 4로 나누어 떨어지지 않는 경우 - 평년
		return FALSE;
}