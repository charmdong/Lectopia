#include <stdio.h>

int inputCnt(int *cnt);
int inputNum(int *ary, int *cntAry, int cnt);
int diffCnt(int *cntArray, int cnt);
void reset(int*cntAry,int size);
void flush();

int main()
{
	int ary[1000] = { 0 };
	int cntAry[10001] = { 0 };
	int cnt;
	int res;
	int diff;
	int i;
	while (1)
	{
		res = inputCnt(&cnt);
		if (res)
		{
			if (inputNum(ary, cntAry, cnt))
			{
				diff = diffCnt(cntAry, cnt);
				printf("* ���� �ٸ� ���� ���� : %d\n\n", diff);
			}
		}
		else // ���� �Է�
			break;

		reset(ary,sizeof(ary)/sizeof(ary[0]));
		reset(cntAry, sizeof(cntAry) / sizeof(cntAry[0]));
	}
	
	return 0;
	
}

int inputCnt(int *cnt)
{
	int res = 1;
	while (1)
	{
		printf("* �Է��� ������ ���� : ");
		if (scanf("%d", cnt))
		{
			if (*cnt >= 2 && *cnt <= 1000)
				break;
			else
				printf("* ������ ������ϴ�.\n\n");
		}
		else // ���� �Է�
		{
			res = 0;
			break;
		}
	}
	return res;
}

int inputNum(int *ary,int *cntAry,int cnt)
{
	int res = 1;
	int i;
	int tmp;
	
	printf("* ���� �Է� : ");
	for (i = 0; i < cnt; i++)
	{
		if (scanf("%d", &ary[i]))
		{
			if (ary[i] < 1 || ary[i]>1000)
			{
				printf("* �߸� �Է��ϼ̽��ϴ�.\n\n");
				flush();
				res = 0;
				break;
			}
			else // ���� �Է�
			{
				tmp = ary[i];
				cntAry[tmp]++;
			}
		}
	}
	
	return res;
}

int diffCnt(int *cntArray,int cnt)
{
	int i;
	int diff_cnt = 0;
	for (i = 1; i <=10000; i++)
	{
		if (cntArray[i] > 0)
			diff_cnt++;
	}
	return diff_cnt;
}

void reset(int *cntAry,int size)
{
	int i;
	for (i = 0; i < size; i++)
		cntAry[i] = 0;
	return;
}

void flush()
{
	while (getchar() != '\n') { ; }
}