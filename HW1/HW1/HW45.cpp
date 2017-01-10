#include <stdio.h>
#include <math.h>

void input(char*, int*);
int primeNumber(int);

int main()
{
	int i,cnt=0;
	int res, num=0;
	input("* ������ �ϳ��� �Է��Ͻÿ� : ", &num);
	printf("1~%d������ �Ҽ� ���� ������ �����ϴ�.\n",num);
	printf("-----------------------------------\n");
	for (i = 1; i <= num; i++) // num�� �ݺ�
	{
		res = primeNumber(i);
		if (res == 1) // �Ҽ��� ���
		{
			printf("%d\t", i);
			cnt++;
			if (cnt % 5 == 0)
				printf("\n");
		}
	}
	printf("\n-----------------------------------\n");
	printf("1~%d������ �� �Ҽ��� %d�� �Դϴ�.\n\n", num, cnt);
	return 0;
}

void input(char* message, int *num)
{
	printf(message);
	scanf("%d", num);
	return;
}

int primeNumber(int number)
{
	int i,rem, root;
	root = sqrt(number);
	
	if (number == 1)
		return 0;
	else
	{
		for (i = 2; i <= root; i++)
		{
			rem = number % i;
			if (rem == 0) // ������ �������� ����!!!! 
				return 0;
		}
	}
	return 1;
}