#include <stdio.h>
#include <math.h>

void input(char*, int*);
int primeNumber(int);

int main()
{
	int i,cnt=0;
	int res, num=0;
	input("* 정수값 하나를 입력하시오 : ", &num);
	printf("1~%d까지의 소수 값은 다음과 같습니다.\n",num);
	printf("-----------------------------------\n");
	for (i = 1; i <= num; i++) // num번 반복
	{
		res = primeNumber(i);
		if (res == 1) // 소수인 경우
		{
			printf("%d\t", i);
			cnt++;
			if (cnt % 5 == 0)
				printf("\n");
		}
	}
	printf("\n-----------------------------------\n");
	printf("1~%d까지의 총 소수는 %d개 입니다.\n\n", num, cnt);
	return 0;
}

void input(char* message, int *num)
{
	printf(message);
	scanf("%d", num);
	return;
}

int primeNumber(int number)
{
	int i,rem, root;
	root = sqrt(number);
	
	if (number == 1)
		return 0;
	else
	{
		for (i = 2; i <= root; i++)
		{
			rem = number % i;
			if (rem == 0) // 나누어 떨어지는 순간!!!! 
				return 0;
		}
	}
	return 1;
}