#include <stdio.h>
#include <string.h>
#include <math.h>

void inputNum(int *);
void changeStr(int num, char*str);
void flush();

int main()
{
	char str[11];
	int num;
	while (1)
	{
		inputNum(&num);
		if (num > 0)
			changeStr(num, str);
		else if (num == 0)
			printf("* 재입력 하세요. \n");
		else
			break;
	}
	return 0;
}

void inputNum(int *num)
{
	int res;
	while (1)
	{
		printf("# 금액 입력 : ");
		res = scanf("%d", num);
		if (res== 1 && getchar() == '\n') // 정상 입력 
			break;
		else
		{
			printf("* 잘못 입력하셨습니다.\n");
			flush();
		}
	}
	return;
}

void changeStr(int num, char *str)  // str[11]
{
	int len=0;
	int i, j, comma, loca, tmp;
	int cnt = 0;
	char res[14] = { 0 };
	sprintf(str, "%d", num);
	len = strlen(str); // 문자열 길이
	loca = len % 3; //	콤마 찍히기 시작하는 위치
	
	if (len > 3)
	{	
		if (loca != 0) 
		{
			comma = len / 3;
			for (i = 0; i < len+comma ; i++)
			{
				if (i == (loca + 4 * cnt))
				{
					res[i] = ',';
					cnt++;
				}
				else
					res[i] = str[i - cnt];
			}
		}
		else // loca == 0 인 경우
		{
			comma = len / 3 - 1;
			for (i = 0; i < len+comma; i++)
			{
				if (i == (3 + 4 * cnt))
				{
					res[i] = ',';
					cnt++;
				}
				else
					res[i] = str[i-cnt];
			}
		}
	}
	else
		sprintf(res, "%d", num);

	printf("%s -> %s\n\n", str, res);
	return;
}

void flush()
{
	while (getchar() != '\n') { ; }
}