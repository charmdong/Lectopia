#include <stdio.h>

FILE * fileOpen(char *filename, char *mode);
void inputFee(FILE *fp,int *parkFee); // 요금 받아오는 함수
void inputTime(FILE *fp, int(*time)[2]); // 시간 받아오는 함수
void disTime(int(*time)[2], int(*resTime)[101]); // 시간 받아서 2차원 배열에 저장 함수
int result(int *parkFee,int(*resTime)[101], int* cnt); // 시간대 구하는 함수
void reset(int(*time)[2], int(*resTime)[101], int *cnt,int *parkFee);

int main()
{
	int testCnt;
	int parkFee[3]; // A,B,C 주차 요금
	int time[3][2];
	int resTime[3][101] = { 0 };
	int cnt[3] = { 0 };
	int i, j, total;
		
	FILE *fp;
	fp = fileOpen("c:\\data\\hw77_parking_info.txt", "rt");
	if (fp == NULL) // 파일 열기 실패
		return 1;

	fscanf(fp, "%d", &testCnt); // test 수 불러와서 저장
	for (i = 0; i < testCnt; i++)
	{
		inputFee(fp, parkFee);
		inputTime(fp, time);
		
		disTime(time, resTime);
		
		total = result(parkFee,resTime, cnt);
		printf("A 요금 : %2d / B 요금 : %2d / C 요금 : %2d\n", parkFee[0], parkFee[1], parkFee[2]);
		printf("총 주차 요금 : %d 원\n\n", total);
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
	//cnt[0] = 3대 동일 시간대 cnt[1] = 2대 동일 시간대 cnt[2] = 1대
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