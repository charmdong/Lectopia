#include <stdio.h>

int input(int *, int*, int*);
int yearCheck(int);
int errorCheck(int year, int month, int day);
int monthCheck(int month);
int totalCalc(int year, int month, int day);
void output(int, int, int, int);
void flush();

int main()
{
	int year, month, day;
	int res_in;
	int total;

	while (1)
	{
		res_in = input(&year, &month, &day);
		if (res_in != 3) // 하나라도 문자 입력시
			break;
		else // 정상 입력시
		{
			if (errorCheck(year, month, day) == 0) // 정상 입력
			{
				total = totalCalc(year, month, day);
				output(year, month, day, total);
			}
			else // 오류 데이터 입력
			{
				printf("\n*** 오류 데이터를 입력하셨습니다 ***\n\n");
				flush();
			}
		}
	}
	
	return 0;
}

int input(int *year, int *month, int *day)
{
	int res;
	printf("* 년 월 일을 입력하시오 : ");
	res = scanf("%d %d %d", year, month, day);
	return res;
}

int yearCheck(int year) // 1 : 윤년 , 0 : 평년
{
	if (year % 4 == 0) // 4로 나누어 떨어지는 경우
	{
		if (year % 100 == 0) // 100으로 나누어 떨어지는 경우
		{
			if (year % 400 == 0) // 윤년의 경우
				return 1;
			else // 평년의 경우
				return 0;
		}
		else // 100으로 나누어 떨어지지 않는 경우 - 윤년
			return 1;
	}
	else // 4로 나누어 떨어지지 않는 경우 - 평년
		return 0;
}

int errorCheck(int year, int month, int day) // 0 : 정상, -1 : 재입력
{
	if (year < 1900)
		return -1;
	else
	{
		if (month >= 1 && month <= 12)
		{
			if (monthCheck(month) == 1)
			{
				if (day > 31 || day < 0)
					return -1;
				else
					return 0;
			}
			else if (monthCheck(month) == 0)
			{
				if (day > 30 || day < 0)
					return -1;
				else
					return 0;
			}
			else // 2월의 경우
			{
				if (yearCheck(year) == 1) // 윤년
				{
					if (day > 29 || day < 0)
						return -1;
					else
						return 0;
				}
				else // 평년
				{
					if (day > 28 || day < 0)
						return -1;
					else
						return 0;
				}
			}
		}
		else
			return -1;
	}
}

int monthCheck(int month) // 31일 - 1, 30일 - 0, 2월 - 2 리턴
{
	if (month == 2)
		return -2;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return 0;
	else
		return 1;
}

int totalCalc(int year, int month, int day)
{
	int maxOrigin[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int maxLeap[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int i;
	int total = 0;
	for (i = 1900; i < year; i++)
	{
		if (yearCheck(i) == 1) // 윤년
			total += 366;
		else
			total += 365;
	}
	
	if (yearCheck(year) == 1) // 윤
	{
		for (i = 1; i < month; i++)
			total += maxLeap[i-1];
	}
	else // 평
	{
		for (i = 1; i < month; i++)
			total += maxOrigin[i-1];
	}
	
	total += day;
	return total;
}

void output(int year, int month, int day, int total)
{
	char str[7][3] = { "일","월","화","수","목","금","토" };
	int i;
	int res;
	res = total % 7;
	printf("###################################\n");
	printf("# %d년 %2d월 %2d일은 %s요일입니다 #\n", year, month, day, str[res]);
	printf("###################################\n\n");
	return;
}

void flush()
{
	while (getchar() != '\n') { ; }
}