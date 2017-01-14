#include <stdio.h>

/* Histogram */

FILE * fileOpen(char *filename, char *mode);
int fileRead(FILE *fp, int *dataArray);
int max_calc(int *num,int cnt);
void output(int *num, int size, int max);

int main()
{
	int testCnt;
	int dataCnt;
	int dataArray[30];
	int i, j, k;
	int cnt = 0;
	int max;
	FILE *fp;
	fp = fileOpen("c:\\data\\HW63_histogram.txt", "rt");
	if (fp == NULL) // 파일 열기 실패
		return 1;

	fscanf(fp, "%d", &testCnt); // test 수 불러와서 저장
	
	for (i = 0; i < testCnt; i++)
	{
		dataCnt = fileRead(fp, dataArray);
		max = max_calc(dataArray,dataCnt);
		output(dataArray, dataCnt, max);
	}
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

void output(int *num,int size, int max)
{
	int i, j;
	int tmp = max;
	for (i = 0; i < tmp; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (num[j] >= max)
				printf("%2c", '*');
			else
				printf("%2s"," ");
		}
		printf("\n");
		max--;
	}
	for (i = 0; i < size; i++)
		printf("%2d", num[i]);
	printf("\n");
	return;
}

int max_calc(int *num,int cnt)
{
	int max = num[0];
	int i;
	int res = 0;
	for (i = 0; i < cnt; i++)
	{
		if (num[i] > max)
		{
			max = num[i];
			res = i;
		}
	}
	return num[res];
}