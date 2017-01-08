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
		code = input("* 사용자 코드를 입력하시오(1:가정용/2:상업용/3:공업용) : ");
		if (code >= 1 && code <= 3)
			break;
		else
			printf("\n# 1~3 중에서 선택해주십시오 #\n\n");
	}
	switch (code)
	{
	case 1:	use = input("* 사용량을 입력하시오(ton단위) : ");
		total = calc(code, use);
		output(code, use, total);
		break;
	case 2:	use = input("* 사용량을 입력하시오(ton단위) : ");
		total = calc(code, use);
		output(code, use, total);
		break;
	case 3:	use = input("* 사용량을 입력하시오(ton단위) : ");
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
		if (scanf("%d", &code) == 1 && getchar() == '\n')// 정수 입력
			break;
		else // 문자 입력
		{
			printf("\n# 1~3 중 선택해주십시오 #\n\n");
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
		printf("# 사용자코드 : %d(가정용)\n", code);
	else if (code == 2)
		printf("# 사용자코드 : %d(상업용)\n", code);
	else
		printf("# 사용자코드 : %d(공업용)\n", code);

	printf("# 사용량 : %d ton\n", use);
	printf("# 총수도요금 : %d원\n\n", total);

	return;
}

void flush()
{
	while (getchar() != '\n') { ; }
}