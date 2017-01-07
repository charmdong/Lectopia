#include <stdio.h>

int transNumber(int);
void output(int, int, int);
int gozipCnt(int);
int inputUnit(char*);
void myflush();

int main()
{
	int num;
	int start, end;
	
	start = inputUnit("시작 값(P1) : ");
	end = inputUnit("끝 값(P2) : ");
	num = inputUnit("고집수(N) : ");
	output(start, end, num);

	return 0;
}

int transNumber(int num) // 자릿수 분할 및 곱값 반환 함수
{
	int n1, n2, n3, n4;
	if (num < 1000) // 3자리 수인 경우
	{
		n1 = num / 100;
		n2 = (num - n1 * 100) / 10;
		n3 = num - (n1 * 100 + n2 * 10);
		if (n1 != 0)
			num = n1*n2*n3;
		else if (n2 != 0) // n1==0
			num = n2*n3;
		else // n1==0 , n2==0
			num = n3;
	}
	else if (num < 10000) //4자리 수인 경우
	{
		n1 = num / 1000; // 1000자리
		n2 = (num - n1 * 1000) / 100;
		n3 = (num - (n1 * 1000 + n2 * 100)) / 10;
		n4 = num - (n1 * 1000 + n2 * 100 + n3 * 10);
	
		if (n1 != 0) // 4자리인 경우
			num = n1*n2*n3*n4;
		else if (n2 != 0) // n1==0 3자리의 경우
			num = n2*n3*n4;
		else if (n3 != 0) // n1==0, n2==0
			num = n3*n4;
		else 
			num = n4;
	}
	else // num == 10000
		return 0;

	return num;
}

int gozipCnt(int num) // 고집수 반환하는 함수
{
	int cnt = 0;

	while (num>=10)
	{
		num = transNumber(num);
		cnt++;
	}
	return cnt;
}

void output(int start, int end, int num)
{
	int res;
	int cnt = 0;
	printf("고집수가 %d인 숫자 출력\n",num);
	while (start != (end + 1))
	{
		res = gozipCnt(start); // start~end까지의 고집수
		if (res == num)
		{
			printf("# %d #\n", start);
			cnt++;
		}
		start++;
	}
	printf("총 개수 : %d개\n",cnt);
}

int inputUnit(char* message) // 입력함수
{
	int num;
	while (1)
	{
		printf(message);
		if (scanf("%d", &num) == 1) // 정상 입력
		{
			if ((num >= 100 && num <= 10000) ||(num>=1&&num<=10)) // 정상 입력 경우
				break;
			else // 범위 외 입력
				myflush();
		}
		else // 문자 입력
			myflush();
	}
	return num;
}

void myflush() {
	while (getchar() != '\n') { ;}
}