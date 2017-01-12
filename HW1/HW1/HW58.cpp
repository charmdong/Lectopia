#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int inputStr(char*str);
int calcNum(char*str, int *num);
void output(char *str, int sum);

int main()
{
	char str[100];
	int i,res;
	int num[100];

	while (inputStr(str))
	{
		res = calcNum(str, num);
		output(str, res);
	}
	return 0;
}

int inputStr(char *str)
{
	printf("# 문장을 입력하시오 : ");
	scanf("%s", str);
	if (strcmp(str, "end") == 0)
		return 0;
	else
		return 1;
}

int calcNum(char*str,int *num)
{
	int i;
	int k = 0, j = 0, cnt = 0, sum = 0;
	int len = strlen(str);

	for (i = 0; i < len; i++)
	{
		if ('0' <= str[i] && str[i] <= '9')
		{
			num[k] = str[i] - '0';
			for (j = i + 1; j < len; j++)
			{
				if ('0' <= str[j] && str[j] <= '9') // 다음 자리가 숫자인 경우
					cnt++;
				else // 다음 자리가 문자거나 NULL인 경우
					break;
			}
			sum += num[k] * pow(10, cnt);
			k++;
			cnt = 0;
		}
	}
	return sum;
}

void output(char *str, int sum)
{
	printf("\"%s\" 내의 총 숫자는 [%d]입니다.\n\n", str,sum);
	return;
}
