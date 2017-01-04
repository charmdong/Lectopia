#include <stdio.h>

int main()
{
	int n1, n2;

	while (1)
	{
		printf("# 두개의 정수를 입력하세요 : ");

		if (scanf("%d %d", &n1, &n2) != 2) // 둘 중 하나 혹은 둘 다 문자인 경우
			break;
		/* 정상 입력의 경우 */
		if (n1 > n2)
			printf("%d - %d = %d\n", n1, n2, n1 - n2);
		else // n2>n1
			printf("%d - %d = %d\n", n2, n1, n2 - n1);
	}
	return 0;
}