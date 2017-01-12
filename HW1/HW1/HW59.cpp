#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int num);
void resetRand(int (*)[4]);
void output(int(*)[4]);

int main()
{
	int ary[3][4];
	int i;
	
	srand((unsigned int)time(NULL));
	resetRand(ary);
	output(ary);
	printf("\n");
	return 0;
}

int random(int num)
{
	int res;
	res = rand() % num;
	return res + 1;
}

void resetRand(int (*ary)[4])
{
	int i,j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			ary[i][j] = random(9);
		}
	}
	return;
}

void output(int(*ary)[4])
{
	int row=0, column=0;
	int i, j;
	for (i = 0; i < 3; i++)
	{
		printf("%d행\t: ",i);
		for (j = 0 ; j < 4; j++)
		{
			row += ary[i][j];
			printf("%4d",ary[i][j]);
		}
		printf("\t %d 행의 합 : %d\n", i, row);
		row = 0;
	}
	printf("열의 합\t: ");
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 3; j++)
		{
			column += ary[j][i];
		}
		printf("%4d", column);
		column = 0;
	}
	printf("\n");
}