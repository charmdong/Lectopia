#include <stdio.h>

int main()
{
	int i;
	int a, b;
	
	for (;;)
	{
		printf("# �ΰ��� ������ �Է��ϼ��� : ");
		scanf("%d %d", &a, &b);
		
		if() // a�� b Ȥ�� �Ѵ� ���ڰ� �ԷµǾ��� �� ���� ó�� �ؾ���. break;
		{ }
		
		if (a > b)
			printf("%d - %d = %d\n", a, b, a - b);
		else
			printf("%d - %d = %d\n", b, a, b - a);
	}
	return 0;
}