#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i;
	int result = 0;
	char a[15] = { 0 }, b[15] = { 0 };
	int n1, n2;
	for (;;)
	{
		printf("# �ΰ��� ������ �Է��ϼ��� : ");
		scanf("%s %s", a, b);

		n1 = atoi(a);
		n2 = atoi(b);
		
		for (i = 0; i < strlen(a); i++)
		{
			if (a[i] >= '0' && a[i] <= '9' && b[i] >= '0' && b[i] <= '9' || a[i] == '-' || b[i]=='-') 
				continue;
			else
			{
				result = 1;
				break;
			}
		}
		if (result == 1)
			return 0;
		else
		{
			if (n1 > n2)
				printf("%d - %d = %d\n", n1, n2, n1 - n2);
			else
				printf("%d - %d = %d\n", n2, n1, n2 - n1);
		}
		
	}
	return 0;
}