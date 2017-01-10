#include <stdio.h>

void flush();

int main()
{
	char ch;
	int i, j;

	while (1)
	{
		printf("* 영문자 대문자 입력( 'A' ~ 'Z' ) : ");
		if (scanf("%c", &ch) == 1)
		{
			if (ch >= 'A' && ch <= 'Z') // 정상 입력인 경우 for문 실행 ㄱㄱ
			{
				for (i = 0 ; i<= ch-'A' ; i++)
				{
					for (j = 0; j <= i; j++)
						printf("%c", ch - j);
					printf("\n");
				}
			}
			else // 소문자의 경우
				break;
		}
		else // 다른 문자들 입력 시
			break; 
		flush();
		printf("\n");
	}
	return 0;
}

void flush()
{
	while (getchar() != '\n') { ; }
}