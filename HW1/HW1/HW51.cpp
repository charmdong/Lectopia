#include <stdio.h>

int main()
{
	int ary[] = { 1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4,5,5,5,5,5 };
	int count[20] = { 0 };
	int size, i,tmp;
	size = sizeof(ary) / sizeof(ary[0]);
	
	for (i = 0; i < size; i++)
	{
		tmp = ary[i];
		if (tmp >= 1 && tmp <= 20)
			count[tmp - 1]++;
	}
	for (i = 0; i < 20; i++)
		printf("%d - %d °³\n", i + 1, count[i]);
	
	return 0;
}

