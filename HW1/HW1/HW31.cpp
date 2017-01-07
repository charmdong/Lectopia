#include <stdio.h>

int getBit(int, int);
int setBit(int, int);
int clearBit(int, int);
int clearBitsMSBthroughI(int, int);
int clearBitsIthrough0(int, int);
int updateBit(int, int, int);
void bitPrint(int);
void flush();
void input(char*, int*);

int main()
{
	int num;
	int i;
	int value;
	int choice;

	while (1)
	{
		printf("1.Ư�� bit �� ����\n");
		printf("2.Ư�� bit ���� 1�� �����\n");
		printf("3.Ư�� bit ���� 0���� �����\n");
		printf("4.MSB~Ư�� ��ġ bit�� ��� 0���� �����\n");
		printf("5.Ư�� ��ġ bit~LSB�� ��� 0���� �����\n");
		printf("6.Ư�� bit�� ���ϴ� ������ �����ϱ� (0 ro 1)\n");
		printf("7.����\n");
		printf("�޴��� �����ϼ��� : ");
		
		if (scanf("%d", &choice) == 1)
		{
			switch (choice)
			{
			case 1:	input("Input the Num : ", &num); bitPrint(num);
						input("Input the i : ", &i);
						printf("Result : %d\n",getBit(num,i));
						break;
			case 2:	input("Input the Num : ", &num); bitPrint(num);
						input("Input the i : ", &i); printf("Before : "); bitPrint(num);
						num = setBit(num, i); 
						printf("Result : ");
						bitPrint(num);
						break;
			case 3:   input("Input the Num : ", &num); bitPrint(num);
						input("Input the i : ", &i); printf("Before : "); bitPrint(num);
						num = clearBit(num, i);
						printf("Result : ");
						bitPrint(num);
						break;
			case 4:	input("Input the Num : ", &num); bitPrint(num);
						input("Input the i : ", &i); printf("Before : "); bitPrint(num);
						num = clearBitsMSBthroughI(num, i);
						printf("Result : ");
						bitPrint(num);
						break;
			case 5:	input("Input the Num : ", &num); bitPrint(num);
						input("Input the i : ", &i); printf("Before : "); bitPrint(num);
						num = clearBitsIthrough0(num, i);
						printf("Result : ");
						bitPrint(num);
						break;
			case 6:	input("Input the Num : ", &num); bitPrint(num);
						input("Input the i : ", &i);
						input("Input the value : ", &value); printf("Before : "); bitPrint(num);
						num = updateBit(num, i, value);
						printf("Result : ");
						bitPrint(num);
						break;
			case 7:	printf("\n## ���α׷��� �����մϴ� ##\n\n");
						break;
			default:	printf("\n## 1~7�� �� �ϳ��� �������ֽʽÿ� ##\n");
			}
			if (choice == 7)
				break;
		}
		else // ���� �Է�
		{
			printf("\n## 1~7�� �� �ϳ��� �������ֽʽÿ� ##\n");
			flush();
		}
		printf("\n");
	}
}

int getBit(int num, int i)
{
	if ((num>>i)&1 == 1) // Ư�� ��Ʈ�� 1�� ���
		return 1;
	else
		return 0;
}

int setBit(int num, int i) // Ư�� �ڸ� ��Ʈ�� 1�� �����ϴ� �Լ�
{
	if ((num & (1<<i)) == 0) // Ư�� ��Ʈ�� 0�� ���
	{
		num |= (1<<i);
		return num;
	}
	else // Ư�� ��Ʈ�� 1�� ���
		return num;
}

int clearBit(int num, int i) // Ư�� �ڸ� ��Ʈ�� 0���� �����ϴ� �Լ�
{
	if ((num & (1<<i)) == 0) // Ư�� ��Ʈ�� 0�� ���
		return num;
	else // Ư�� ��Ʈ�� 1�� ���
	{
		num ^= (1 << i); 
		return num;
	}
}

int clearBitsMSBthroughI(int num, int i) // i�º��� MSB���� 0���� ����
{
	int msb = sizeof(num) * 8 - 1;
	while (msb >= i)
	{
		num=clearBit(num, msb);
		msb--;
	}
	return num;
}

int clearBitsIthrough0(int num, int i)
{
	while (i >= 0)
	{
		num = clearBit(num, i);
		i--;
	}
	return num;
}

int updateBit(int num, int i, int value)
{
	if (value == 0)
	{
		num = clearBit(num, i);
		return num;
	}
	else // value == 1
	{
		num = setBit(num, i);
		return num;
	}
}

void bitPrint(int num)
{
	int i = sizeof(num) * 8 - 1;
	while (i + 1)
	{
		printf("%d", (num >> i) & 1);
		i--;
	}
	printf("\n");
}

void flush()
{
	while (getchar() != '\n') {
		;
	}
}

void input(char* message,int* p1)
{
	printf(message);
	scanf("%d", p1);
}