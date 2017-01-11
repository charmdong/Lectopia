#include <stdio.h>
#include <string.h>

int input(char*, char*);
int strcheck(char*, char);
void flush();

int main()
{
	char str[100];
	char ch;
	int res,check;
	while (1)
	{
		res = input(str, &ch);
		if (res == 1) // ���� �Է�
		{
			check = strcheck(str, ch);
			if (check != -1)
				printf("\"%s\" ���ڿ� �ȿ� '%c' ���ڴ� %d�� ��ġ�� �����մϴ�.\n\n", str, ch, check);
			else
				printf("\"%s\" ���ڿ� �ȿ� '%c' ���ڴ� �������� �ʽ��ϴ�.\n\n", str, ch);
		}
		else if (res == 0)
			break;
	}
	return 0;
}

int input(char* string, char *ch)
{
	printf("# ���ڿ��� �Է��Ͻÿ� : ");
	scanf("%s", string);
	if (strcmp(string, "end") == 0) // end �Է½�
		return 0;
	printf("# ���ڸ� �Է��Ͻÿ� : ");
	if (scanf(" %c", ch) == 1) // ���ڿ��� end�� �ƴϰ� �����ϳ��� �� �Է��Ѱ��
	{
		if (getchar() == '\n')
			return 1;
		else
		{
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			flush();
			return -1;
		}
	}
}

int strcheck(char* str, char ch)
{
	int i,len;
	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (str[i] == ch)
			return i;
	}
	return -1;
}

void flush()
{
	while (getchar() != '\n') { ; }
}