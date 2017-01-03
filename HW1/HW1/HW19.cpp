#include <stdio.h>

int input();
int yearCheck(int);
void output(int, int);

int main()
{
	int year;
	int res;
	year = input();
	res = yearCheck(year);
	output(year, res);
	return 0;
}

int input()
{
	int year;
	printf("년도를 입력하시오 : ");
	scanf("%d", &year);
	return year;
}

int yearCheck(int x)
{
	if (x % 4 == 0) // 4로 나누어 떨어지는 경우
	{
		if (x % 100 == 0) // 100으로 나누어 떨어지는 경우
		{
			if (x % 400 == 0) // 윤년의 경우
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

void output(int year, int result)
{
	if (result == 1) // 윤년의 경우
		printf("%d년은 윤년(Leap year)입니다.\n",year);
	else // 평년의 경우
		printf("%d년은 평년(Common year)입니다.\n",year);
}