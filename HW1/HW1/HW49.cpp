#include <stdio.h>

FILE * fileOpen(char *filename, char *mode);
int fileRead(FILE *fp, int *dataArray);

int main()
{
	int testCnt;
	int dataCnt;
	int dataArray[15];
	int i, j,k;
	int cnt = 0;
	FILE *fp;
	fp = fileOpen("c:\\data\\hw49_number_list.txt", "rt");
	if (fp == NULL) // ���� ���� ����
		return 1;
	
	fscanf(fp, "%d", &testCnt); // test �� �ҷ��ͼ� ����
	for (i = 0; i < testCnt; i++)
	{
		printf("# ���� : ");
		dataCnt = fileRead(fp, dataArray);
		for (j = 0; j < dataCnt; j++)
		{
			printf("%d ", dataArray[j]);
			for (k = 0; k < dataCnt; k++)
			{
				if (2* dataArray[j] == dataArray[k])
					cnt++;
			}
		}
		printf("\n  2 �� ���� �����ϴ� ������ ������ %d �� �Դϴ�.\n\n", cnt);
		cnt = 0;
	}	
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