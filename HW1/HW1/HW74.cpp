#include <stdio.h>

FILE * fileOpen(char *filename, char *mode);
int getIndex(FILE *fp);
void getJolly(FILE *fp, int *jollyNum, int indexCnt);
void checkJolly(int *jollyNum,int indexCnt);
void reset(int *,int size);
int absNum(int num);

int main()
{
	int testCnt;
	int indexCnt;
	int jollyNum[101];
	int i, j, k;
	FILE *fp;
	fp = fileOpen("c:\\data\\hw74_jolly.txt", "rt");
	if (fp == NULL) // 파일 열기 실패
		return 1;

	fscanf(fp, "%d", &testCnt); // test 수 불러와서 저장
	for (i = 0; i < testCnt; i++)
	{
		indexCnt = getIndex(fp);
		getJolly(fp, jollyNum, indexCnt);
		printf("검사한 수열 : ");
		for (j = 0; j < indexCnt; j++)
			printf("%d ", jollyNum[j]);
		checkJolly(jollyNum, indexCnt);
		reset(jollyNum, indexCnt);
	}
	printf("\n");
	fclose(fp);
	return 0;
}

FILE * fileOpen(char *filename, char *mode)
{
	FILE *fp;
	if ((fp = fopen(filename, mode)) == NULL)
	{
		printf("File open error!\n");
	}
	return fp;
}

int getIndex(FILE *fp)
{
	int cnt;
	fscanf(fp, "%d", &cnt);
	return cnt;
}

void getJolly(FILE *fp, int *jollyNum,int indexCnt)
{
	int i;
	for (i = 0; i < indexCnt; i++)
		fscanf(fp, "%d", &jollyNum[i]);
	return;
}

void checkJolly(int *jollyNum,int indexCnt)
{
	int i,diff,res=1;
	int cnt[101] = { 0 };
	if (indexCnt == 0)
		printf("이건 졸리가 맞는 것도 아닌 것도 아니여....\n");
	else if (indexCnt == 1)
		printf("\t<Jolly Jumper>\n");
	else 
	{
		for (i = 0; i < indexCnt - 1; i++)
		{
			diff = absNum(jollyNum[i] - jollyNum[i + 1]);
			cnt[diff]++;
		}
		for (i = 1; i < indexCnt; i++)
		{
			if (cnt[i] != 1)
			{
				res = 0;
				break;
			}
		}
		if (res)
			printf("<Jolly Jumper>\n");
		else
			printf("<Not Jolly Jumper>\n");
	}
	return;
}

void reset(int *jollyNum, int indexCnt)
{
	int i;
	for (i = 0; i < indexCnt; i++)
		jollyNum[i] = 0;
	return;
}

int absNum(int num)
{
	if (num < 0)
		return -num;
	else
		return num;
}