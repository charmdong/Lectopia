#include <stdio.h>

int main()
{
	int n1, n2;

	while (1)
	{
		printf("# �ΰ��� ������ �Է��ϼ��� : ");

		if (scanf("%d %d", &n1, &n2) != 2) // �� �� �ϳ� Ȥ�� �� �� ������ ���
			break;
		/* ���� �Է��� ��� */
		if (n1 > n2)
			printf("%d - %d = %d\n", n1, n2, n1 - n2);
		else // n2>n1
			printf("%d - %d = %d\n", n2, n1, n2 - n1);
	}
	return 0;
}