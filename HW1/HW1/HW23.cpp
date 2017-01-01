#include <stdio.h>

int main()
{
	int i;
	int a, b;
	
	for (;;)
	{
		printf("# 두개의 정수를 입력하세요 : ");
		scanf("%d %d", &a, &b);
		
		if() // a나 b 혹은 둘다 문자가 입력되었을 때 예외 처리 해야함. break;
		{ }
		
		if (a > b)
			printf("%d - %d = %d\n", a, b, a - b);
		else
			printf("%d - %d = %d\n", b, a, b - a);
	}
	return 0;
}