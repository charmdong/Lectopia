#pragma once
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <conio.h>

int inputStr(char *);
int transNum(char *);
void changeStr(int num, char *str);

int main()
{
	int total = 0, menu;
	char str[1000] = { 0 };
	while (menu = inputStr(str))
	{
		if (menu == 0)
			break;
		else if (menu == 2)
			printf("* 범위를 벗어났습니다.\n");
		else			
			total += menu;
	}
	changeStr(total,str);

	return 0;
}

int inputStr(char* str)
{
	int num;
	
		printf("금액 입력 : ");
		scanf("%s", str);
		if (strcmp(str, "0000") == 0)
			return 0;
		num = transNum(str);
		if (num>=1 && num <= 2000000000)
			return num;
		else
			return 2;
}

int transNum(char *str)
{
	int i, len,coCnt=0;
	int num = 0;
	int tmp=0;
	len = strlen(str);

	for (i = 0; i < len; i++)
	{
		if (str[i] == ',')
			coCnt++;		
	}

	tmp = len - coCnt - 1;
	for (i = 0; i < len; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			num += (str[i] - '0') * pow(10, tmp--);
	}
	return num;
}

void changeStr(int num, char *str)  // str[11]
{
	int len = 0;
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
			for (i = 0; i < len + comma; i++)
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
			for (i = 0; i < len + comma; i++)
			{
				if (i == (3 + 4 * cnt))
				{
					res[i] = ',';
					cnt++;
				}
				else
					res[i] = str[i - cnt];
			}
		}
	}
	else
		sprintf(res, "%d", num);

	printf("\n총합 : %s\n\n", res);
	return;
}