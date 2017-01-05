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
	printf("* �칰�� ���̸� �Է��Ͻÿ�(cm����) : ");
	scanf("%d", &deep);
	return deep;
}

int escape(int x)
{
	int cnt = 0;
	int i;

	if (x == 0)
		cnt = 0;
	
	else // ���̰� 0�� �ƴ� ��
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
	printf("%.2lf ���� ������ �칰�� Ż���ϱ� ���ؼ��� %d���� �ɸ��ϴ�.\n", (double)deep/100, day);

}
