#include <stdio.h>

int main()
{
	int n1, n2;

	printf("두개의 정수를 입력하시오 : ");
	scanf("%d %d", &n1, &n2);

	printf("%d + %d = %d\n", n1, n2, n1 + n2);
	printf("%d - %d = %d\n", n1, n2, n1 - n2);
	printf("%d * %d = %d\n", n1, n2, n1 * n2);
	printf("%d / %d = %.2lf\n", n1, n2, (double)n1 / n2);
	return 0;
}