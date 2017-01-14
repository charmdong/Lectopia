#include <stdio.h>
#include <string.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define RESIDENT_NUMBER_LENGTH  13 /* �ֹε�Ϲ�ȣ ����*/
int availabilityCheck(char *resident_number);
int checkLengthCharacter(char *resident_number);
int checkDate(char *resident_number);
int checkIdentification(char *resident_number);
int checkGender(char *resident_number);
int checkYear(int year);

int main()
{
	/* �׽�Ʈ�� �ֹε�Ϲ�ȣ ���� �迭*/
	char resident_number[][20] = { "0402291000008", "870401102321", "00031541949179",
		"0003154194917", "801203#201122", "7804155328845", "7804150328840",
		"9612241068382", "9902292194322", "0230174326176", "8811391042219",
		"8100122042213", "8112002042213", "9210101069415", "0802294012345",
		"8806311069417","8807311069418" };
	int i, count;
	/* �˻��� �ֹε�Ϲ�ȣ�� ���� ���*/
	count = sizeof(resident_number) / sizeof(resident_number[0]);
	for (i = 0; i<count; i++) /* �ֹε�Ϲ�ȣ ��ȿ�� �˻縦 �ݺ������� ���� ��*/
	{
		if (availabilityCheck(resident_number[i]) == TRUE)
		{
			printf("(+) �ֹι�ȣ%s��(��) ��ȿ�� ��ȣ�Դϴ�.\n", resident_number[i]);
		}
		else
		{
			printf("(-) �ֹι�ȣ%s��(��) ��ȿ���� ���� ��ȣ�Դϴ�.\n", resident_number[i]);
		}
	}
	return 0;
}

int availabilityCheck(char *resident_number)
{
	int res = 0;
	res += checkLengthCharacter(resident_number);
	res += checkDate(resident_number);
	res += checkGender(resident_number);
	res += checkIdentification(resident_number);
	if (res == 4)
		return TRUE;
	else
		return FALSE;
}

int checkLengthCharacter(char *resident_number)
{
	int len, i;
	len = strlen(resident_number);
	if (len == RESIDENT_NUMBER_LENGTH)
	{
		for (i = 0; i < RESIDENT_NUMBER_LENGTH; i++)
		{
			if (resident_number[i] >= '0' && resident_number[i] <= '9')
				return TRUE;
			else
				return FALSE;
		}
	}
	else
		return FALSE;
}

int checkDate(char *resident_number) // ����� ��� ��, �� �� �Ǵ�
{
	int year=0,month,day;
	int i;
	
	if (resident_number[0] == '0') // 0���� �����ϴ� �ֹι�ȣ
	{
		if (resident_number[6] == '1' || resident_number[6] == '2') // 1900����
			year = 1900 + (resident_number[1] - '0');
		else // 2000����
			year = 2000 + (resident_number[1] - '0');
	}
	else if (resident_number[0] == 1) // 1�� �����ϴ� �ֹι�ȣ
	{
		if (resident_number[1] - '0' < 8) 
		{
			if (resident_number[6] == '1' || resident_number[6] == '2') // 1900����
				year = 1910 + (resident_number[1] - '0');
			else // 2000����
				year = 2010 + (resident_number[1] - '0');
		}
	}
	else // 1900����
		year = 1900 + (resident_number[0] - '0') * 10 + (resident_number[1] - '0');
	
	month = (resident_number[2] - '0') * 10 + (resident_number[3] - '0');
	day = (resident_number[4] - '0') * 10 + (resident_number[5] - '0');
	if (month>=1 && month <= 12) // �� ���� �Է��� ���
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			// 31���� ���� ���
		{
			if (day>=1 && day <= 31)
				return TRUE;
			else
				return FALSE;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) // 30���� ���
		{
			if (day>=1 && day <= 30)
				return TRUE;
			else
				return FALSE;
		}
		else // 2���� ���
		{
			if (checkYear(year)) // ����
			{
				if (day>=1 && day < 30)
					return TRUE;
				else
					return FALSE;
			}
			else // ���
			{
				if (day>=1 && day < 29)
					return TRUE;
				else
					return FALSE;
			}
		}
	}
	else // �� �������Է�
		return FALSE;
}

int checkIdentification(char *resident_number) // 
{
	int i;
	int iden=0;
	for (i = 0; i < RESIDENT_NUMBER_LENGTH-1; i++)
		iden += (resident_number[i] - '0');
	if (resident_number[12]-'0' == iden % 10)
		return TRUE;
	else
		return FALSE;
}

int checkGender(char *resident_number) // 7��° �ڸ��� 1~4�̸� TRUE
{
	if (resident_number[6] >= '1' && resident_number[6] <= '4')
		return TRUE;
	else
		return FALSE;
}


int checkYear(int year)
{
	if (year % 4 == 0) // 4�� ������ �������� ���
	{
		if (year % 100 == 0) // 100���� ������ �������� ���
		{
			if (year % 400 == 0) // ������ ���
				return TRUE;
			else // ����� ���
				return FALSE;
		}
		else // 100���� ������ �������� �ʴ� ��� - ����
			return TRUE;
	}
	else // 4�� ������ �������� �ʴ� ��� - ���
		return FALSE;
}