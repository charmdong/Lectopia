#include <stdio.h>

int main()
{
	int fibo=1,tmp=0;
	int num;
	int i;
	int sum=0;
	printf("피보나치 수열의 항수를 입력하시오 : ");
	scanf("%d", &num);
	
	for (i = 1; i <= num; i++)
	{
		printf("%d + ", fibo);
		sum += fibo;
		fibo = fibo + tmp;	
		tmp = fibo - tmp;		
	}
	
	printf("\b\b= %d\n", sum);
	return 0;
}
