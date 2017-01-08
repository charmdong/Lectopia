#include <stdio.h>

char menu();
int deposit(int, int);
int withdraw(int, int);
void flush();

int main()
{
	char choice;
	int num=0;
	int total = 0;
	
	printf("* ���� �ܾ��� %d�� �Դϴ�.\n\n",total);
	while (1)
	{
		choice = menu();
		switch (choice)
		{
			case 'i' : total = deposit(num, total); break;
			case 'o': total = withdraw(num, total); break;
			case 'q': printf("\n## ���α׷��� �����մϴ�. ##\n\n"); break;
			default : printf("�� ��찡 �ɸ� ���� ����.\n");
		}
		flush();
		if (choice == 'q')
			break;
	}
	return 0;
}

char menu()
{
	char choice;
	
	while (1)
	{
		printf("# �޴��� �����Ͻÿ�(i-�Ա�, o-���, q-����) : ");
		if (scanf("%c", &choice) == 1)
		{
			if (choice == 'i' || choice == 'o' || choice == 'q') // ���� �Է�
				break;
			else
			{
				printf("* �߸� �Է��ϼ̽��ϴ�.\n\n");
				flush();
			}
		}
		else
		{
			printf("* �߸� �Է��ϼ̽��ϴ�.\n\n");
			flush();
		}
	}

	return choice;
}

int inputInt(char* message) // �������� ����
{
	int num;
	printf(message);
	
	while (scanf("%d", &num) != 1) // ���� �Է½�
	{
		flush();
		printf("* �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ� : ");
	}
	
	return num;
}

int deposit(int num, int total)
{
	num = inputInt("# �Աݾ��� �Է��ϼ��� : ");
	
	while (num < 0)
		num = inputInt("* �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ� : ");
	
	total += num;
	printf("* ���� �ܾ��� %d�� �Դϴ�.\n\n", total);
	return total;
}

int withdraw(int num, int total) // ���
{
	num = inputInt("# ��ݾ��� �Է��ϼ��� : ");
	
	while (num < 0)
		num = inputInt("* �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ� : ");

	if (total < num)
		printf("* �ܾ��� �����մϴ�.\n");
	else
		total -= num;

	printf("* ���� �ܾ��� %d�� �Դϴ�.\n\n", total);
	return total;
}

void flush()
{
	while (getchar() != '\n') {
		;
	}
}