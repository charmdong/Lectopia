#include <stdio.h>

int input(char*);
int calc(int, int);
void output(int, int, int);
void flush();

int main()
{
	int code, use, total;

	while (1)
	{
		code = input("* ����� �ڵ带 �Է��Ͻÿ�(1:������/2:�����/3:������) : ");
		if (code >= 1 && code <= 3)
			break;
		else
			printf("\n# 1~3 �߿��� �������ֽʽÿ� #\n\n");
	}
	switch (code)
	{
	case 1:	use = input("* ��뷮�� �Է��Ͻÿ�(ton����) : ");
		total = calc(code, use);
		output(code, use, total);
		break;
	case 2:	use = input("* ��뷮�� �Է��Ͻÿ�(ton����) : ");
		total = calc(code, use);
		output(code, use, total);
		break;
	case 3:	use = input("* ��뷮�� �Է��Ͻÿ�(ton����) : ");
		total = calc(code, use);
		output(code, use, total);
		break;
	}
	return 0;
}

int input(char * message)
{
	int code;

	while (1)
	{
		printf(message);
		if (scanf("%d", &code) == 1 && getchar() == '\n')// ���� �Է�
			break;
		else // ���� �Է�
		{
			printf("\n# 1~3 �� �������ֽʽÿ� #\n\n");
			flush();
		}
	}
	return code;
}

int calc(int code, int use)
{
	int total;
	if (code == 1)
		total = (use * 50) * 105 / 100;
	else if (code == 2)
		total = (use * 45) * 105 / 100;
	else
		total = (use * 30) * 105 / 100;
	return total;
}

void output(int code, int use, int total)
{
	printf("\n");
	if (code == 1)
		printf("# ������ڵ� : %d(������)\n", code);
	else if (code == 2)
		printf("# ������ڵ� : %d(�����)\n", code);
	else
		printf("# ������ڵ� : %d(������)\n", code);

	printf("# ��뷮 : %d ton\n", use);
	printf("# �Ѽ������ : %d��\n\n", total);

	return;
}

void flush()
{
	while (getchar() != '\n') { ; }
}