#include <stdio.h>

void flush();

int main()
{
	char ch;
	int i, j;

	while (1)
	{
		printf("* ������ �빮�� �Է�( 'A' ~ 'Z' ) : ");
		if (scanf("%c", &ch) == 1)
		{
			if (ch >= 'A' && ch <= 'Z') // ���� �Է��� ��� for�� ���� ����
			{
				for (i = 0 ; i<= ch-'A' ; i++)
				{
					for (j = 0; j <= i; j++)
						printf("%c", ch - j);
					printf("\n");
				}
			}
			else // �ҹ����� ���
				break;
		}
		else // �ٸ� ���ڵ� �Է� ��
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