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
			printf("* ���Է� �ϼ���. \n");
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
		printf("# �ݾ� �Է� : ");
		res = scanf("%d", num);
		if (res== 1 && getchar() == '\n') // ���� �Է� 
			break;
		else
		{
			printf("* �߸� �Է��ϼ̽��ϴ�.\n");
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
	len = strlen(str); // ���ڿ� ����
	loca = len % 3; //	�޸� ������ �����ϴ� ��ġ
	
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
		else // loca == 0 �� ���
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