#include <stdio.h>

int input();

int main()
{
	int i;
	int n; // num
	int cnt = 0;
	
	n = input();
	for (i = 0; i < n; i++)
	{
		printf("*");
		cnt++;
		if (cnt == 5)
		{
			printf("\n");
			cnt = 0;
		}
	}
	printf("\n");
	return 0;

}

int input() // ���� �Է� ���� ó�� �ʿ���
{
	int num;
	printf("# �������� �Է��ϼ��� : ");
	scanf("%d", &num);
	return num;
}
