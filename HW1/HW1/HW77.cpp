#include <stdio.h>

FILE * fileOpen(char *filename, char *mode);
void inputFee(FILE *fp,int *parkFee); // ��� �޾ƿ��� �Լ�
void inputTime(FILE *fp, int(*time)[2]); // �ð� �޾ƿ��� �Լ�
void disTime(int(*time)[2], int(*resTime)[101]); // �ð� �޾Ƽ� 2���� �迭�� ���� �Լ�
int result(int *parkFee,int(*resTime)[101], int* cnt); // �ð��� ���ϴ� �Լ�
void reset(int(*time)[2], int(*resTime)[101], int *cnt,int *parkFee);

int main()
{
	int testCnt;
	int parkFee[3]; // A,B,C ���� ���
	int time[3][2];
	int resTime[3][101] = { 0 };
	int cnt[3] = { 0 };
	int i, j, total;
		
	FILE *fp;
	fp = fileOpen("c:\\data\\hw77_parking_info.txt", "rt");
	if (fp == NULL) // ���� ���� ����
		return 1;

	fscanf(fp, "%d", &testCnt); // test �� �ҷ��ͼ� ����
	for (i = 0; i < testCnt; i++)
	{
		inputFee(fp, parkFee);
		inputTime(fp, time);
		
		disTime(time, resTime);
		
		total = result(parkFee,resTime, cnt);
		printf("A ��� : %2d / B ��� : %2d / C ��� : %2d\n", parkFee[0], parkFee[1], parkFee[2]);
		printf("�� ���� ��� : %d ��\n\n", total);
		reset(time, resTime, cnt,parkFee);
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

void inputFee(FILE *fp,int *parkFee)
{
	int i;
	while (1)
	{
		for (i = 0; i < 3; i++)
			fscanf(fp, "%d", &parkFee[i]);
		if (1 <= parkFee[2] && parkFee[2] <= parkFee[1] && parkFee[1] <= parkFee[0] && parkFee[0] <= 100)
			break;
	}
	return;
}

void inputTime(FILE *fp,int(*time)[2])
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
			fscanf(fp, "%d", &time[i][j]);
	}
	return;
}

void disTime(int(*time)[2],int(*resTime)[101])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = time[i][0]; j < time[i][1]; j++)
			resTime[i][j]=1;
	}
	return;
}

int result(int*parkFee,int(*resTime)[101], int* cnt)
{
	//cnt[0] = 3�� ���� �ð��� cnt[1] = 2�� ���� �ð��� cnt[2] = 1��
	int i,total=0;
	int tmp;
	for (i = 1; i <= 100; i++)
	{
		tmp = resTime[0][i] + resTime[1][i] + resTime[2][i];
		if (tmp == 3)
			cnt[0]++;
		else if (tmp == 2)
			cnt[1]++;
		else if (tmp == 1)
			cnt[2]++;
	}
	
	total = (cnt[0]) * 3 * parkFee[2] + cnt[1] * 2 * parkFee[1] + cnt[2] * parkFee[0];

	return total;
}

void reset(int(*time)[2], int(*resTime)[101], int *cnt,int *parkFee)
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
			time[i][j] = 0;
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 1; j < 101; j++)
			resTime[i][j] = 0;
	}
	for (i = 0; i < 3; i++)
	{
		parkFee[i] = 0;
		cnt[i] = 0;
	}
	return;
}