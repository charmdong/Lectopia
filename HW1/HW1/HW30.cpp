#include <stdio.h>

int main()
{
	int num;
	int i = sizeof(num) * 8 - 1;
	printf("* 10���� ������ �Է��Ͻÿ� : ");
	scanf("%d", &num);

	printf("%d(10) = ", num);
	while (i + 1)
	{
		printf("%d", (num >> i) & 1);
		i--;
	}
	printf("(2)\n");
	return 0;
}
