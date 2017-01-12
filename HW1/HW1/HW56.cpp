#include <stdio.h>

FILE * fileOpen(char *filename, char *mode);
int fileRead(FILE *fp, int *dataArray);
void sortNum(int *ary, int dataCnt);
void output(FILE *fp, int*dataArray, int testCnt);

int main()
{
	int testCnt;
	int dataCnt;
	int dataArray[1000];
	int i, j, k;
	int cnt = 0;
	FILE *fp;
	fp = fileOpen("c:/data/hw56_sortData.txt", "rt");
	if (fp == NULL) // 파일 열기 실패
		return 1;

	fscanf(fp, "%d", &testCnt); // test 수 불러와서 저장
	output(fp, dataArray, testCnt);
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

int fileRead(FILE *fp, int *dataArray)
{
	int dataCnt = 0;
	while (1)
	{
		fscanf(fp, "%d", &dataArray[dataCnt]);
		if (dataArray[dataCnt] == 0) break;
		dataCnt++;
	}
	return dataCnt;
}

void sortNum(int *ary,int dataCnt)
{
	int i, j;
	int *n1, *n2;
	int tmp;
	for (i = 0; i < dataCnt; i++)
	{
		for (j = i + 1; j <= dataCnt; j++)
		{
			if (ary[j] < ary[i])
			{
				n1 = &ary[i];
				n2 = &ary[j];
				
				tmp = *n1;
				*n1 = *n2;
				*n2 = tmp;
			}
		}
	}
	return;
}

void output(FILE *fp, int*dataArray, int testCnt)
{
	int i, j;
	int dataCnt;
	for (i = 0; i < testCnt; i++)
	{
		printf("# 소트 전 데이터 : ");
		dataCnt = fileRead(fp, dataArray);
		for (j = 0; j < dataCnt; j++)
			printf("%d ", dataArray[j]);
		printf("\n");
		printf("# 소트 후 데이터 : ");
		for (j = 1; j <= dataCnt; j++)
		{
			sortNum(dataArray, dataCnt);
			printf("%d ", dataArray[j]);
		}
		printf("\n\n");
	}
	return;
}