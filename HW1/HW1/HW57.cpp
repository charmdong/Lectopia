#include <stdio.h>
#include <string.h>
#include <ctype.h>

void inputStr(char*str);
int checkPalin(char* str, int len);
void output(char *str, int res);
void flush();

int main()
{
	char string[1000];
	char cmp[1000] = { 0 };
	int len, res;
	while (1)
	{
		inputStr(string);
		strcpy(cmp, string);
		if (strcmp(string, "end") == 0)
			break;
		else
		{
			len = strlen(string);
			res = checkPalin(string, len);
			output(cmp, res);
		}
		printf("\n");
	}
	return 0;
}

void inputStr(char *str)
{
	printf("# 단어 입력 : ");
	scanf("%s", str);
	return;
}

int checkPalin(char *str,int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = (char)toupper(str[i]);
	}
	for (i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - 1 - i])
			return 0; // 회문이 아닌 경우
	}
	return 1; // 회문인 경우
}

void output(char *str,int res)
{
	if (res == 1) //회문인 경우
		printf(" \"%s\" : 회문입니다!\n", str);
	else
		printf(" \"%s\" : 회문이 아닙니다!\n", str);
	return;
}

void flush()
{
	while (getchar() != '\n') { ; }
}