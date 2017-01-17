#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

int random(int num);
int *** myAlloc(int plane, int row, int col);
void dataInput(int ***p, int plane, int row, int col);
void dataOutput(int ***p, int plane, int row, int col);
void myDelete(int ***p, int row, int col);

int main()
{
	int ***ip;
	int plane, row, col;

	printf("plane 수 입력 : ");
	scanf("%d", &plane);
	printf("row 수 입력 : ");
	scanf("%d", &row);
	printf("col 수 입력 : ");
	scanf("%d", &col);

	ip = myAlloc(plane, row, col);
	srand((unsigned int)time(NULL));
	dataInput(ip, plane, row, col);
	dataOutput(ip, plane, row, col);
	myDelete(ip, plane, row);
	return 0;
}

int*** myAlloc(int plane, int row, int col)
{
	int ***p;
	int i, j;
	p = (int***)malloc(sizeof(int**)*plane);
	assert(p != NULL);
	for (i = 0; i < plane; i++)
	{
		p[i] = (int**)malloc(sizeof(int*)*row);
		assert(p[i] != NULL);
	}
	for (i = 0; i < plane; i++)
	{
		for (j = 0; j < row; j++)
		{
			p[i][j] = (int*)malloc(sizeof(int)*col);
			assert(p[i][j] != NULL);
		}
	}
	return p;
}

void dataInput(int ***p, int plane, int row, int col)
{
	int i, j, k;
	for (i = 0; i < plane; i++)
		for (j = 0; j < row; j++)
			for (k = 0; k < col; k++)
				p[i][j][k] = random(101);
	return;
}

void dataOutput(int ***p, int plane, int row, int col)
{
	int i, j, k;
	printf("\n");
	for (i = 0; i < plane; i++)
	{
		for (j = 0; j < row; j++)
		{
			for (k = 0; k < col; k++)
				printf("%4d", p[i][j][k]);
			printf("\n");
		}
		printf("\n");
	}
	return;
}

void myDelete(int ***p, int plane, int row)
{
	int i, j;
	for (i = 0; i < plane; i++) 
	{
		for (j = 0; j < row; j++) 
		{
			free(p[i][j]);
		}
		free(p[i]);
	}
	free(p);
	return;
}

int random(int num)
{
	int res;
	res = rand() % num;
	return res;
}