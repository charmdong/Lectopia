#include <stdio.h>

int main()
{
	int num,i, j;

	while (1)
	{
		printf("# ��� ���μ��� �Է��Ͻÿ� : ");
		if (scanf("%d", &num) == 1) // ���� �Է�
		{
			for (i = 1; i <= num; i++)
			{
				for (j = 1; j <= num; j++)
				{
					if (j <= i) // ���� �ѹ��� ���� ��
						printf("*");
					else
						printf(" ");
				}
				printf(" ");
				for (j = num; j >0; j--)
				{
					if (j > i)
						printf(" ");
					else
						printf("*");
				}
				printf("\n");
			}
		}
		else // ���� �Է½�
			break;
	}

	return 0;
}
