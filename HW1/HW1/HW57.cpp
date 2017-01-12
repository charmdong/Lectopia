#include <stdio.h>
#include <string.h>
#include <ctype.h>

int inputStr(char*str);
int checkPalin(char* str, int len);
void output(char *str, int res);
void flush();

int main()
{
	char string[1000];
	char cmp[1000] = { 0 };
	int len, res;
	while (inputStr(string))
	{
		strcpy(cmp, string);
		len = strlen(string);
		res = checkPalin(string, len);
		output(cmp, res);
	}
	
	return 0;
}

int inputStr(char *str)
{
	printf("# �ܾ� �Է� : ");
	scanf("%s", str);
	if (strcmp(str, "end") == 0)
		return 0;
	else
		return 1;
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
			return 0; // ȸ���� �ƴ� ���
	}
	return 1; // ȸ���� ���
}

void output(char *str,int res)
{
	if (res == 1) //ȸ���� ���
		printf(" \"%s\" : ȸ���Դϴ�!\n\n", str);
	else
		printf(" \"%s\" : ȸ���� �ƴմϴ�!\n\n", str);
	return;
}

void flush()
{
	while (getchar() != '\n') { ; }
}