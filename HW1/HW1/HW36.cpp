#include <stdio.h>

int main()
{
	int i;
	int num;
	int sum = 0;
	for (i=1;i<=5;i++)
	{
		printf("0 ���� ū���� �Է��Ͻÿ�(%d ��°) : ",i);
		scanf("%d", &num);
		if (num <= 0)
		{
			i--;
			continue;
		}
		else
			sum += num;
	}
	printf("�Էµ� ���� �� �� : %d\n", sum);
	return 0;
}
