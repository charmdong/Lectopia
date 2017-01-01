#include <stdio.h>

int input();

int main()
{
	int i;
	int n; // num
	int cnt = 0;
	
	n = input();
	for (i = 0; i < n; i++)
	{
		printf("*");
		cnt++;
		if (cnt == 5)
		{
			printf("\n");
			cnt = 0;
		}
	}
	printf("\n");
	return 0;

}

int input() // 문자 입력 예외 처리 필요함
{
	int num;
	printf("# 정수값을 입력하세요 : ");
	scanf("%d", &num);
	return num;
}
