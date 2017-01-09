#include <stdio.h>

int main()
{
	int i;
	
	for (i = 1; i <= 100; i++)
	{
		
		if (i % 3 == 0 && i % 5 != 0)//3의 배수
			printf("%3c", '*');
		else if (i % 5 == 0 && i % 3 != 0)//5의 배수
			printf("%3c", '#');
		else
			printf("%3d", i);
		
		if (i % 10 == 0)
			printf("\n");
	}
	return 0;
}
