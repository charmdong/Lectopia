#include <stdio.h>

unsigned char openFan(unsigned char);
unsigned char closeFan(unsigned char);
unsigned char reverseFan(unsigned char);
int inputStr(char*);
int menu();
void displayFan(unsigned char);
int getBit(unsigned char, int);
unsigned char setBit(unsigned char, int);
unsigned char clearBit(unsigned char, int);
void flush();

int main()
{
	int choice;
	unsigned char ch=0;
	
	while (1)
	{
		choice = menu();
		switch (choice)
		{
		case 1: ch = openFan(ch); displayFan(ch); break;
		case 2: ch = closeFan(ch); displayFan(ch); break;
		case 3: ch = reverseFan(ch); displayFan(ch); break;
		case 4: printf("\n# ���α׷��� �����մϴ� #\n\n"); break;
		}
		if (choice == 4)
			break;
	}
	return 0;
}

int menu()
{
	int choice,res;
	
	printf("1. ȯǳ�� ���� / 2. ȯǳ�� �ݱ� / 3. ȯǳ�� ��ü ��ȯ / 4. ���� : ");
	while (1)
	{
		while (1)
		{
			res = scanf("%d", &choice);
			if (res == 1 && getchar() == '\n') // ���� �Է�
				break;
			else
			{
				printf("\n## 1~4�� �߿��� �������ֽʽÿ� : ");
				flush();
			}
		}
		if (choice >= 1 && choice <= 4) 
			break;
		else 
			printf("\n## 1~4�� �߿��� �������ֽʽÿ� : ");
	}
	return choice; // 1~4���� ���ϵȴ�.
}

unsigned char openFan(unsigned char fan)
{
	printf("---------------------------------------------------------------\n");
	printf("\t\tFan ���� �۾� ���� ȭ��\n");
	printf("---------------------------------------------------------------\n");
	int i = inputStr("* OPEN�� FAN ��ȣ�� �Է��Ͻÿ�(1-8) : ");
	printf("---------------------------------------------------------------\n");
	if ((fan & (1 << (i-1))) == 0)
	{
		fan |= (1 << (i-1));
		return fan;
	}
	else
		return fan;
}

unsigned char closeFan(unsigned char fan)
{
	printf("---------------------------------------------------------------\n");
	printf("\t\tFan �ݱ� �۾� ���� ȭ��\n");
	printf("---------------------------------------------------------------\n");
	int i = inputStr("* CLOSE�� FAN ��ȣ�� �Է��Ͻÿ�(1-8) : ");
	printf("---------------------------------------------------------------\n");
	if ((fan & (1 << (i-1))) == 0)
		return fan;
	else
	{
		fan ^= (1 << (i-1));
		return fan;
	}
}

int inputStr(char* message)
{
	int num,res;
	printf(message);
	while (1)
	{
		while (1)
		{
			res = scanf("%d", &num);
			if (res == 1 && getchar() == '\n') // ���� �Է�
				break;
			else
			{
				printf("\n## 1~8��° �߿��� �������ֽʽÿ� : ");
				flush();
			}
		}
		if (num >= 1 && num <= 8)
			break;
		else
			printf("\n## 1~8��° �߿��� �������ֽʽÿ� : ");
	}
	return num; // 1~8���� ���ϵȴ�.
}

unsigned char reverseFan(unsigned char ch) // on,off ���¸� �ٲ������ �Լ�
{
	int res;
	int cnt=7;
	printf("---------------------------------------------------------------\n");
	printf("\t\tFan ��ü ��ȯ �۾� ���� ȭ��\n");
	printf("---------------------------------------------------------------\n");
	while (cnt>=0)
	{
		res = getBit(ch, cnt); // ���ڸ��� ��Ʈ Ȯ�� 0 or 1
		if (res == 0) // Ư�� ��ġ ��Ʈ�� 0�� ���
			ch = setBit(ch, cnt); // 1�� ����
		else
			ch = clearBit(ch, cnt);
		cnt--;
	}
	return ch;
}

int getBit(unsigned char num, int i) // Ư�� ��ġ ��Ʈ üũ ( 0 �Ǵ� 1 )
{
	if ((num >> i) & 1 == 1) // Ư�� ��Ʈ�� 1�� ���
		return 1;
	else 
		return 0;
}

void displayFan(unsigned char ch)
{
	int res;
	int cnt = 7;
	int i = 8;
	
	while (i)
	{
		printf("%d�� FAN\t", i);
		i--;
	}
	printf("\n");
	
	while (cnt >= 0)
	{
		res = getBit(ch, cnt);
		if (res == 1)
			printf("%4s\t", "ON");
		else
			printf("%5s\t", "OFF");
		cnt--;
	}
	printf("\n---------------------------------------------------------------\n\n");
	return;
}

unsigned char setBit(unsigned char num, int i) // Ư�� �ڸ� ��Ʈ�� 1�� �����ϴ� �Լ�
{
	if ((num & (1 << i)) == 0) // Ư�� ��Ʈ�� 0�� ���
	{
		num |= (1 << i);
		return num;
	}
	else // Ư�� ��Ʈ�� 1�� ���
		return num;
}

unsigned char clearBit(unsigned char num, int i) // Ư�� �ڸ� ��Ʈ�� 0���� �����ϴ� �Լ�
{
	if ((num & (1 << i)) == 0) // Ư�� ��Ʈ�� 0�� ���
		return num;
	else // Ư�� ��Ʈ�� 1�� ���
	{
		num ^= (1 << i);
		return num;
	}
}

void flush()
{
	while (getchar() != '\n') { ; }
}