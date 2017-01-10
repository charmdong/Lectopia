#include <stdio.h>

int main()
{
	int num,i, j;

	while (1)
	{
		printf("# 출력 라인수를 입력하시오 : ");
		if (scanf("%d", &num) == 1) // 정상 입력
		{
			for (i = 1; i <= num; i++)
			{
				for (j = 1; j <= num; j++)
				{
					if (j <= i) // 라인 넘버랑 같을 때
						printf("*");
					else
						printf(" ");
				}
				printf(" ");
				for (j = num; j >0; j--)
				{
					if (j > i)
						printf(" ");
					else
						printf("*");
				}
				printf("\n");
			}
		}
		else // 문자 입력시
			break;
	}

	return 0;
}
