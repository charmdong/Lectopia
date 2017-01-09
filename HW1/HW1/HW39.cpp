#include <stdio.h>

int main()
{
	int num;
	int total=0;
	int cnt = 0;
	int i,j;

	printf("* 기사의 근무일수를 입력하시오 : ");
	scanf("%d", &num);
	
	for (i = 1; ; i++)
	{
		for (j = 1; j <= i; j++)
		{
			total += i;
			cnt++;
			if (cnt == num)
				goto END;
		}
	}
END:
		printf("  근무일 : %d 일 / 총 금화수 : %d\n\n",num, total);
	return 0;
}