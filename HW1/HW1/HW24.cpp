#include <stdio.h>

int input();
int escape(int);
void output(int, int);

int main()
{
	int deep = input();
	int day = escape(deep);
	output(deep, day);
	return 0;
}

int input()
{
	int deep;
	printf("* 우물의 깊이를 입력하시오(cm단위) : ");
	scanf("%d", &deep);
	return deep;
}

int escape(int x)
{
	int cnt = 0;
	int i;

	if (x == 0)
		cnt = 0;
	
	else // 깊이가 0이 아닐 때
	{
		while(1)
		{
			cnt++;
			x = x - 50;
			if (x <= 0)
				break;
			else
				x = x + 20;
		}
	}

	return cnt;
}

void output(int deep,int day)
{
	printf("%.2lf 미터 깊이의 우물을 탈출하기 위해서는 %d일이 걸립니다.\n", (double)deep/100, day);

}
