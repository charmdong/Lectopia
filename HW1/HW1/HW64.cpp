#include <stdio.h>

int inputNum(int *num);
int max_calc(int *num,int *max,int cnt);
int min_calc(int *num,int *min,int cnt);
int findNum(int *ary, int num, int cnt);
void output(int *ary,int cnt);

int main()
{
	int ary[100];
	int i;
	int cnt;
	while (cnt = inputNum(ary))
		output(ary, cnt);
	return 0;
}

int inputNum(int *num)
{
	int i=0,res;
	printf("* �����Է� : ");
	while (1)
	{
		res = scanf("%d", &num[i]);
		if (res != 1)
			break;
		if (num[i] == 0)
			break;
		i++;
	}
	return i;
}


int max_calc(int *num,int *max,int size)
{
	int tmp = num[0];
	int ary[100] = { 0 };
	int i,index;
	for (i = 0; i < size; i++)
		ary[i] = num[i];

	for (i = 0; i < size; i++)
	{
		if (num[i] > tmp)
			tmp = num[i];
	}
	*max = tmp;
	index = findNum(ary, tmp, size);
	return index;
}

int min_calc(int *num,int *min,int size)
{
	int tmp = num[0];
	int ary[100] = { 0 }; // ������ ���
	int i,index;
	for (i = 0; i < size; i++) // ary�� num ����
		ary[i] = num[i];

	for (i = 0; i < size; i++) // �ּҰ� ã�Ƽ� ���� ������ ����
	{
		if (num[i] < tmp)
			tmp = num[i];
	}
	*min = tmp;
	index = findNum(ary,tmp,size);
	return index;
}

int findNum(int *ary,int num,int cnt)
{
	int i;
	for (i = 0; i < cnt; i++)
	{
		if (ary[i] == num)
			return i;
	}
	return 0; // ã�� ���ڰ� ���� �� 0 ��ȯ
}

void output(int *ary,int cnt)
{
	int i;
	int max, min;
	int max_in, min_in;
	
	max_in = max_calc(ary, &max, cnt);
	min_in = min_calc(ary, &min, cnt);
	printf("�ִ밪 : %d(index : %d) / �ּҰ� : %d(index : %d)\n\n", max, max_in, min, min_in);
	return;
}