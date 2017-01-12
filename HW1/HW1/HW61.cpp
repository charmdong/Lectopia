#include <stdio.h>
#include <string.h>

void inputStr(char(*)[20]);
void sortString(char(*)[20]);
void output(char(*)[20]);

int main()
{
	char str[5][20];
	inputStr(str);
	sortString(str);
	output(str);
}

void inputStr(char(*str)[20])
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("# %d번 문자열을 입력하시오 : ", i + 1);
		scanf("%s", str[i]);
	}
	return;
}

void sortString(char(*str)[20])
{
	int i,j;
	char tmp[20] = { 0 };
	char tmp2[20] = { 0 };
	for (i = 0; i < 4; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			if (strcmp(str[i],str[j])>0)
			{
				strcpy(tmp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], tmp);
			}
		}
	}
}

void output(char(*str)[20] )
{
	int i;
	int len[5];
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		len[i] = strlen(str[i]);
		printf("str[%d] = %s  %c  %c\n", i, str[i], str[i][0], str[i][len[i] - 1]);
	}
	printf("\n");
	return;
}


