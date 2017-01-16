#include <stdio.h>

FILE * fileOpen(char *filename, char *mode);
int stuNum(FILE *fp);
void pickNum(FILE *fp, int *num, int student);
void output(int stuCnt, int *pickAry);

int main()
{
	int testCnt;
	int stuCnt; // 학생 수
	int pickAry[101] = { 0 };
	int i, j, k;
	int cnt = 0;
	FILE *fp;
	fp = fileOpen("c:\\data\\hw78_line.txt", "rt");
	if (fp == NULL) // 파일 열기 실패
		return 1;

	fscanf(fp, "%d", &testCnt); // test 수 불러와서 저장
	for (i = 0; i < testCnt; i++)
	{
		stuCnt = stuNum(fp);
		pickNum(fp, pickAry, stuCnt);
		printf("%d 반 학생의 순서 출력 : ", i + 1);
		output(stuCnt, pickAry);
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

int stuNum(FILE *fp)
{
	int student;
	fscanf(fp, "%d", &student);
	return student;
}

void pickNum(FILE *fp, int *num,int student)
{
	int i;
	for (i = 0; i < student; i++)
		fscanf(fp, "%d", &num[i]);
	return;
}

void output(int stuCnt,int *pickAry)
{
	int i,j;
	int stu[101] = { 0 }; // 학생 순번
	int res[101] = { 0 }; // 결과 저장
	for (i = 0; i < stuCnt; i++)
		stu[i] = i + 1;

	res[0] = stu[0];

	for (i = 1; i < stuCnt; i++)
	{
		if (pickAry[i] == 0)
			res[i] = stu[i];
		else 
		{
			for (j = i - 1; j >= i-pickAry[i]; j--)
				res[j+1] = res[j];
			res[i-pickAry[i]] = stu[i];
		}
	}
	for (i = 0; i < stuCnt; i++)
		printf("%2d ", res[i]);
	printf("\n");
	return;
}