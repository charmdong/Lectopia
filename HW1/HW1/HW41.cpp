#include <stdio.h>

int main()
{
	int i,j;
	int cnt = 0;

	for (i = 0; i < 10; i++)
	{
		for (j =0; j < 100; j+=10)
			printf("%3d", i + j);
		printf("\n");
	}
	return 0;
}