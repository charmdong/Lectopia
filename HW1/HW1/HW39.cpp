#include <stdio.h>

int main()
{
	int num;
	int total=0;
	int cnt = 0;
	int i,j;

	printf("* ����� �ٹ��ϼ��� �Է��Ͻÿ� : ");
	scanf("%d", &num);
	
	for (i = 1; ; i++)
	{
		for (j = 1; j <= i; j++)
		{
			total += i;
			cnt++;
			if (cnt == num)
				goto END;
		}
	}
END:
		printf("  �ٹ��� : %d �� / �� ��ȭ�� : %d\n\n",num, total);
	return 0;
}