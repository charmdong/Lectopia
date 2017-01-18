#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

int random(int num);	// ���� �߻� �Լ�
void menu(int *num); // �޴� �Լ�
int** bingAlloc(int *num); // ������ ���� �Լ�
void inputRand(int **p,int num); // �ߺ����� �ʴ� ���� ���� �� ���� �Լ�
void displayBing(int**p,int num); // ������ ��� �Լ�
void delBing(int **p,int num); // ������ �޸� �Ҵ� ���� �Լ�(���� ������)
int checkNum(int**p, int num, int tmp); // �ߺ��Ǵ� �� üũ �Լ�
void trainBing(int**p, int num);
int checkdel(int **bing, int num, int del); // ���������� �ƴ��� Ȯ���ϴ� �Լ�
int checkBing(int**bing, int num);
void flush();

int main()
{
	int num;
	srand((unsigned int)time(NULL));
	menu(&num);
	return 0;
}

void menu(int *num)
{
	int choice;
	int **bingo;
	while (1)
	{
		printf("-------------BINGO------------\n");
		printf("1. �������� (���� ������)\n");
		printf("2. �������� (��ǻ�Ϳ� ������)\n");
		printf("3. ����\n\n");
		printf("# �޴� ���� : ");
		if (scanf("%d", &choice))
		{
			switch (choice) {
			case 1:
				printf("\n<<< ������ ��������� �����մϴ� >>>\n\n");
				bingo = bingAlloc(num);
				displayBing(bingo, *num);
				trainBing(bingo, *num);
				break;
			case 2:
				printf("\n<<< ��ǻ�Ϳ� ���� ��������� �����մϴ� >>>\n\n"); 
				
				break;
			case 3:printf("\n<<< ���� ������ �����մϴ� >>>\n\n"); break;
			default: printf("### 1~3�� �߿��� ������ �ֽʽÿ� ###\n\n");
			}
			if (choice == 3)
				break;
		}
		else {
			printf("### 1~3�� �߿��� ������ �ֽʽÿ� ###\n\n");
			flush();
		}
	}
}
/*--------------------------------------------------*\
|| �������� ũ�⸦ �Է¹ް� �޸� �Ҵ� �� �ߺ�		 ||
|| ���� �ʴ� ������ ������ ���� (���� �Է½� ����)	 ||
\*--------------------------------------------------*/
int** bingAlloc(int *num) 
{
	int i;
	int **bing;
	while (1)
	{
		printf("# �������� ����, ���� ũ�⸦ �Է����ּ���(����� �Է�) : ");
		if (scanf("%d", num))
		{
			if (*num > 0) // ���� �Է�
			{
				//----------Memory Allocation Part----------//
				bing = (int**)malloc(*num * sizeof(int*));
				assert(bing != NULL);
				for (i = 0; i < *num; i++)
				{
					bing[i] = (int*)malloc(*num * sizeof(int));
					assert(bing[i] != NULL);
				}
				inputRand(bing, *num);
				break;
			}
			else
				printf("### ����� �Է����ּ��� ###\n");
		}
		else // ���� �Է½�
		{
			printf("### ���ڸ� �Է����ּ��� ###\n");
			flush();
		}
	}
	return bing;
}
/*---------------------------------------------------*\
||	������ �ߺ����� �ʰ� 2���� �迭�� �����ϴ� �Լ� ||
\*---------------------------------------------------*/
void inputRand(int **bing,int num) 
{
	int i,j;
	int cmp;
	printf("\n<<< �������� �������Դϴ�. ��ø� ��ٷ� �ֽʽÿ� >>>\n");

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			cmp = random(num*num);
			if (checkNum(bing, num, cmp)) // ��ġ�� ���� �ִ� ���
				j--;
			else
				bing[i][j] = cmp;
		}
	}
	return;
}

/*---------------------------------------------------*\
||	������ ��� �Լ�											  ||
\*---------------------------------------------------*/
void displayBing(int**bing,int num)
{
	int i,j;
	printf("\n");
	for (i = 0; i < num; i++)
	{
		printf("|");
		for (j = 0; j < num; j++)
		{
			if (bing[i][j] == 'X')
				printf(" %2c ", bing[i][j]);
			else
				printf(" %2d ", bing[i][j]);
		}
		printf("|\n");
	}
	printf("\n");
	return;
}
/*---------------------------------------------------*\
||	������ ���� �ߺ��� ���� ���� ���� Ȯ�� �Լ�  	  ||
\*---------------------------------------------------*/
int checkNum(int **bing, int num, int tmp)
{
	int i, j;
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (bing[i][j] == tmp)
				return 1;
		}
	}
	return 0;
}
/*---------------------------------------------------*\
||	�����ǿ��� ���ڸ� X�� ���� �� ���� ���� üũ, 	  ||
||	�������� ������ִ� �Լ�								  ||
\*---------------------------------------------------*/
void trainBing(int **bing, int num)
{
	int i, j;
	int del;
	int bingCnt = 0;
	while (1)
	{
		printf("\n# ���� ���ڸ� �Է��ϼ��� : ");
		if (scanf("%d", &del))
		{
			if (checkdel(bing, num, del)) // ������ ���� ���
			{
				for (i = 0; i < num; i++)
				{
					for (j = 0; j < num; j++)
					{
						if (bing[i][j] == del) 						
							bing[i][j] = 'X';
					}
				}
				bingCnt = checkBing(bing, num);
				displayBing(bing, num);
				printf("* ���� ���� ���� : %d\n", bingCnt);
				if (bingCnt == num) {
					printf("### ���� ���� : %d ��, ���� ��! ###\n\n",bingCnt);
					delBing(bing,num); // ���� �޸� �Ҵ� ����
					break;
				}
			}
			else
				printf("\n*** �̹� ������ ���� �Դϴ�. �ٽ� �Է��ϼ��� ***\n");
		}
		else
		{
			printf("\n<<< �޴��� ���ư��ϴ� >>>\n\n");
			flush();
			break;
		}
	}
	return;
}
/*---------------------------------------------------*\
||	������ ���ڸ� �������� Ȯ���ϴ� �Լ�			  	  ||
\*---------------------------------------------------*/
int checkdel(int **bing, int num,int del) 
{
	int i, j, res = 0;
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			if (bing[i][j] == del)
			{
				res = 1;
				return res;
			}
		}
	}
	return res; // 1�̸� ������ ���� ���, 0�̸� �̹� ������
}
/*---------------------------------------------------*\
||	���� ���� Ȯ�� �Լ�										  ||
||	��, ��, �밢���� ��� ����								  ||
\*---------------------------------------------------*/
int checkBing(int **bing, int num) // bingo ���� ��ȯ
{
	int cnt = 0;
	int bingCnt = 0;
	int i, j;
	/*	���� ������� ���� �����ϴ� ��� */
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			if (bing[i][j] == 'X')
			{
				cnt++;
				if (cnt == num)
					bingCnt++;
			}
		}
		cnt = 0;
	}
	/*	���� ������� ���� �����ϴ� ��� */
	for (j = 0; j < num; j++) {
		for (i = 0; i < num; i++) {
			if (bing[i][j] == 'X')
			{
				cnt++;
				if (cnt == num)
					bingCnt++;
			}
		}
		cnt = 0;
	}
	/*	�밢���� ���·� ���� �����ϴ� ��� - (1) */
	for (i = 0; i < num; i++) {
		if (bing[i][i] == 'X')
		{
			cnt++;
			if (cnt == num)
				bingCnt++;
		}
	}
	cnt = 0;
	/*	�밢���� ���·� ���� �����ϴ� ��� - (2) */
	for (i = 0; i < num; i++) {
		if (bing[i][num - 1 - i] == 'X')
		{
			cnt++;
			if (cnt == num)
				bingCnt++;
		}
	}
	cnt = 0;

	return bingCnt;
}
void delBing(int **bing, int num)
{
	int i;
	for (i = 0; i < num; i++)
		free(bing[i]);
	free(bing);
	return;
}

/*-------------------------------------------------------------
		���⼭���� 2)���� ��忡 �ʿ��� �Լ����� ���Ǻ�
-------------------------------------------------------------*/


int random(int num)
{
	int res;
	res = rand() % num;
	return res+1; // 1~num������ ���� �߻�
}

void flush()
{
	while (getchar() != '\n') { ; }
}