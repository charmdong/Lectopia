#include <stdio.h>

int input();
int cal_fee(int);
void output(int);

int main()
{
	int num;
	int result;
	num = input(); // ���� ����
	result = cal_fee(num); // ��� ��� ���
	output(result); // ���
	return 0;
}

int input()
{
	int station;

	printf("������ �Է��Ͻÿ� : ");
	scanf("%d", &station);

	return station;
}

int cal_fee(int x)
{
	int fee;
	int over; // �ʰ� �������� ����
	int tmp4; // �ʰ� �������� ���� 4�� ���� ��
	int rem; // �ʰ� ������ ���� 4�� ���� ������

	if (x < 6) // 1~5�� �������� ���
		fee = 600;
	else if (x <= 10) // 6~10�� �������� ���
		fee = 800;
	else // �������� ���� 10�� �ʰ��� ���
	{
		fee = 800; // �⺻��� 800��
		over = x - 10; // �ʰ� �������� ��
		if (over <=2 ) // �ʰ� �������� ������ 1 or 2�� ��
			fee += 100;
		else if (over <=4) // �ʰ� ��������� 3 or 4�� ��
			fee += 200;
		else // �ʰ� ��������� 4�� �̻��� ��
		{
			tmp4 = over / 4; // tmp4 : �ʰ� ��������� 4�� ���� ��
			rem = over - tmp4 * 4; //�ʰ� ��������� 4�� ���� ������
			if (rem == 0)
				fee = fee + tmp4 * 200;
			else if(rem <= 2)
				fee = fee + tmp4 * 200 + 100;
			else // if (rem == 3)
				fee = fee + tmp4 * 200 + 200;
		}
	}
	return fee;
}

void output(int result)
{
	printf("��� : %d��\n", result);
}