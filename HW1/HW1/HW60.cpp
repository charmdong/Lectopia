#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int num);
void resetRand(int(*)[5]);
void calcSum(int(*)[5],int* sum);
void output(int(*)[5], int *sum);

int main()
{
	int ary[5][5];
	int sum[3] = { 0 };
	srand((unsigned int)time(NULL));
	resetRand(ary);
	calcSum(ary, sum);
	output(ary, sum);
	return 0;
}

int random(int num)
{
	int res;
	res = rand() % num;
	return res + 1;
}

void resetRand(int(*ary)[5])
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
			ary[i][j] = random(20) ;
	}
	return;
}

void calcSum(int(*ary)[5],int *sum)
{
	int i, j;
	
	for (i = 0; i < 5; i++)
		sum[0] += ary[i][i];

	for (i = 1; i < 5; i++)
	{
		for (j = 0; j < i; j++)
			sum[1] += ary[i][j];
	}
	for (i = 0; i < 4; i++)
	{
		for (j = i + 1; j < 5; j++)
			sum[2] += ary[i][j];
	}
	return;
}

void output(int(*ary)[5], int *sum)
{
	int i, j;

	for (i = 0; i < 5; i++)
	{
		printf("%d¹ø Çà : ",i);
		for (j = 0; j < 5; j++)
			printf("%3d", ary[i][j]);
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < 3; i++)
		printf("sum%d = %d\n", i + 1, sum[i]);
	printf("\n");
	return;
}