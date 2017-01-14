#include <stdio.h>

void calc(int (*)[4], int(*)[4], int(*)[4]);
void output(int(*)[4], int(*)[4],int (*)[4]);
void res(int(*a)[4], int(*b)[4], int(*c)[4]);

int main()
{
	int a[4][4] = { {0,1,2,3},{1,-2,1,2},{2,5,-3,2},{0,-3,1,4} };
	int b[4][4] = { {1,-1,2,0} ,{1,-1,1,2},{-1,0,3,1},{2,-1,2,8} };
	int c[4][4] = { 0 };
	calc(a, b, c);
	output(a, b, c);
	return 0;
}

void calc(int(*a)[4], int(*b)[4],int(*c)[4])
{
	int i, j, k;
	int sum = 0;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 4; k++)
			{
				sum += a[i][k] * b[k][j];
			}
			c[i][j] = sum;
			sum = 0;
		}
	}

	return;
}

void output(int(*a)[4],int(*b)[4],int(*c)[4])
{
	printf("%12s\t", "[Matrix A]");
	printf("%12s\t", "[Matrix B]");
	printf("%12s\n", "[C = A * B]");
	res(a, b, c);
	return;
} // 출력 부분 생각해보기

void res(int(*a)[4],int(*b)[4],int(*c)[4])
{
	int i, j, k;
	
	for (j = 0; j < 4; j++)
	{	
		for (k = 0; k < 4; k++)
			printf("%3d", a[j][k]);
		printf("\t");
		for (k = 0; k < 4; k++)
			printf("%3d", b[j][k]);
		printf("\t");
		for (k = 0; k < 4; k++)
			printf("%3d", c[j][k]);
		printf("\n");
	}
	printf("\n");
	return;
}

