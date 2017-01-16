#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int random(int);
void baseBall(int *);
void gameCnt(int *, int *);
void result(int *);

int main()
{
	int base[4] = { 0 };
	int game[2] = { 0 };
	int cnt = 1;
	int i;
	
	srand((unsigned int)time(NULL));
	baseBall(base);
		printf("\t[");
		for (i = 0; i < 4; i++)
			printf(" %d ", base[i]);
		printf("]\n");
		while (1)
		{
			printf("# %d차 : ", cnt);
			gameCnt(base, game);
			result(game);
			if (game[0] == 4)
				break;
			else
			{
				game[0] = 0;
				game[1] = 0;
			}
			cnt++;
		}
	
	return 0;
}

void result(int *game)
{
	if (game[0] == 0 && game[1] == 0)
		printf("\tNo!\n");
	else if (game[0] == 4)
		printf("\tOK!!!\n");
	else
		printf("\t%dS %dB\n", game[0], game[1]);
	return;
}

void gameCnt(int *base, int *game)
{
	//game[0] : S , game[1] : B
	int cnt = 0; // 입력 받은 횟수
	int i;
	char ch;

	while (1)
	{
		ch = getche();
		if ('0'<= ch && ch<='9')
		{
			for (i = 0; i < 4; i++)
			{
				if (ch == (base[i]+'0') && cnt == i)
					game[0]++;
				else if (ch == (base[i]+'0'))
					game[1]++;
			}
			cnt++;
		}
		if (cnt == 4)
			break;
	}
	return;
}

void baseBall(int *base)
{
	int i;

	while (1)
	{
		int cnt[10] = { 0 };
		int res = 1;
		for (i = 0; i < 4; i++)
		{
			base[i] = random(9);
			cnt[base[i]]++;
		}
		for (i = 0; i < 10; i++)
		{
			if (cnt[i] > 1)
			{
				res = 0;
				break;
			}
		}
		if (res == 1)
			break;
	}
	return;
}

int random(int num)
{
	int res;
	res = rand() % num;
	return res;
}