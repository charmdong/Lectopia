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
		printf("1.특정 bit 값 얻어내기\n");
		printf("2.특정 bit 값을 1로 만들기\n");
		printf("3.특정 bit 값을 0으로 만들기\n");
		printf("4.MSB~특정 위치 bit를 모두 0으로 만들기\n");
		printf("5.특정 위치 bit~LSB를 모두 0으로 만들기\n");
		printf("6.특정 bit를 원하는 값으로 변경하기 (0 ro 1)\n");
		printf("7.종료\n");
		printf("메뉴를 선택하세요 : ");
		
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
			case 7:	printf("\n## 프로그램을 종료합니다 ##\n\n");
						break;
			default:	printf("\n## 1~7번 중 하나를 선택해주십시오 ##\n");
			}
			if (choice == 7)
				break;
		}
		else // 문자 입력
		{
			printf("\n## 1~7번 중 하나를 선택해주십시오 ##\n");
			flush();
		}
		printf("\n");
	}
}

int getBit(int num, int i)
{
	if ((num>>i)&1 == 1) // 특정 비트가 1인 경우
		return 1;
	else
		return 0;
}

int setBit(int num, int i) // 특정 자리 비트를 1로 변경하는 함수
{
	if ((num & (1<<i)) == 0) // 특정 비트가 0인 경우
	{
		num |= (1<<i);
		return num;
	}
	else // 특정 비트가 1인 경우
		return num;
}

int clearBit(int num, int i) // 특정 자리 비트를 0으로 변경하는 함수
{
	if ((num & (1<<i)) == 0) // 특정 비트가 0인 경우
		return num;
	else // 특정 비트가 1인 경우
	{
		num ^= (1 << i); 
		return num;
	}
}

int clearBitsMSBthroughI(int num, int i) // i승부터 MSB까지 0으로 지움
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