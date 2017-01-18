#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

int random(int num);	// 난수 발생 함수
void menu(int *num); // 메뉴 함수
int** bingAlloc(int *num); // 빙고판 생성 함수
void inputRand(int **p,int num); // 중복되지 않는 난수 생성 및 저장 함수
void displayBing(int**p,int num); // 빙고판 출력 함수
void delBing(int **p,int num); // 빙고판 메모리 할당 해제 함수(게임 끝나고)
int checkNum(int**p, int num, int tmp); // 중복되는 수 체크 함수
void trainBing(int**p, int num);
int checkdel(int **bing, int num, int del); // 지워진건지 아닌지 확인하는 함수
int checkBing(int**bing, int num);
void flush();

int main()
{
	int num;
	srand((unsigned int)time(NULL));
	menu(&num);
	return 0;
}

void menu(int *num)
{
	int choice;
	int **bingo;
	while (1)
	{
		printf("-------------BINGO------------\n");
		printf("1. 연습게임 (개인 연습용)\n");
		printf("2. 대전게임 (컴퓨터와 대전용)\n");
		printf("3. 종료\n\n");
		printf("# 메뉴 선택 : ");
		if (scanf("%d", &choice))
		{
			switch (choice) {
			case 1:
				printf("\n<<< 연습용 빙고게임을 시작합니다 >>>\n\n");
				bingo = bingAlloc(num);
				displayBing(bingo, *num);
				trainBing(bingo, *num);
				break;
			case 2:
				printf("\n<<< 컴퓨터와 대전 빙고게임을 시작합니다 >>>\n\n"); 
				
				break;
			case 3:printf("\n<<< 빙고 게임을 종료합니다 >>>\n\n"); break;
			default: printf("### 1~3번 중에서 선택해 주십시오 ###\n\n");
			}
			if (choice == 3)
				break;
		}
		else {
			printf("### 1~3번 중에서 선택해 주십시오 ###\n\n");
			flush();
		}
	}
}
/*--------------------------------------------------*\
|| 빙고판의 크기를 입력받고 메모리 할당 및 중복		 ||
|| 되지 않는 난수로 빙고판 생성 (정상 입력시 리턴)	 ||
\*--------------------------------------------------*/
int** bingAlloc(int *num) 
{
	int i;
	int **bing;
	while (1)
	{
		printf("# 빙고판의 가로, 세로 크기를 입력해주세요(양수값 입력) : ");
		if (scanf("%d", num))
		{
			if (*num > 0) // 정상 입력
			{
				//----------Memory Allocation Part----------//
				bing = (int**)malloc(*num * sizeof(int*));
				assert(bing != NULL);
				for (i = 0; i < *num; i++)
				{
					bing[i] = (int*)malloc(*num * sizeof(int));
					assert(bing[i] != NULL);
				}
				inputRand(bing, *num);
				break;
			}
			else
				printf("### 양수만 입력해주세요 ###\n");
		}
		else // 문자 입력시
		{
			printf("### 숫자를 입력해주세요 ###\n");
			flush();
		}
	}
	return bing;
}
/*---------------------------------------------------*\
||	난수를 중복되지 않게 2차원 배열에 대입하는 함수 ||
\*---------------------------------------------------*/
void inputRand(int **bing,int num) 
{
	int i,j;
	int cmp;
	printf("\n<<< 빙고판을 생성중입니다. 잠시만 기다려 주십시오 >>>\n");

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			cmp = random(num*num);
			if (checkNum(bing, num, cmp)) // 겹치는 수가 있는 경우
				j--;
			else
				bing[i][j] = cmp;
		}
	}
	return;
}

/*---------------------------------------------------*\
||	빙고판 출력 함수											  ||
\*---------------------------------------------------*/
void displayBing(int**bing,int num)
{
	int i,j;
	printf("\n");
	for (i = 0; i < num; i++)
	{
		printf("|");
		for (j = 0; j < num; j++)
		{
			if (bing[i][j] == 'X')
				printf(" %2c ", bing[i][j]);
			else
				printf(" %2d ", bing[i][j]);
		}
		printf("|\n");
	}
	printf("\n");
	return;
}
/*---------------------------------------------------*\
||	빙고판 내에 중복된 수의 존재 유무 확인 함수  	  ||
\*---------------------------------------------------*/
int checkNum(int **bing, int num, int tmp)
{
	int i, j;
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (bing[i][j] == tmp)
				return 1;
		}
	}
	return 0;
}
/*---------------------------------------------------*\
||	빙고판에서 숫자를 X로 변경 및 빙고 개수 체크, 	  ||
||	빙고판을 출력해주는 함수								  ||
\*---------------------------------------------------*/
void trainBing(int **bing, int num)
{
	int i, j;
	int del;
	int bingCnt = 0;
	while (1)
	{
		printf("\n# 지울 숫자를 입력하세요 : ");
		if (scanf("%d", &del))
		{
			if (checkdel(bing, num, del)) // 지우지 않은 경우
			{
				for (i = 0; i < num; i++)
				{
					for (j = 0; j < num; j++)
					{
						if (bing[i][j] == del) 						
							bing[i][j] = 'X';
					}
				}
				bingCnt = checkBing(bing, num);
				displayBing(bing, num);
				printf("* 현재 빙고 개수 : %d\n", bingCnt);
				if (bingCnt == num) {
					printf("### 빙고 개수 : %d 개, 게임 끝! ###\n\n",bingCnt);
					delBing(bing,num); // 동적 메모리 할당 해제
					break;
				}
			}
			else
				printf("\n*** 이미 지워진 숫자 입니다. 다시 입력하세요 ***\n");
		}
		else
		{
			printf("\n<<< 메뉴로 돌아갑니다 >>>\n\n");
			flush();
			break;
		}
	}
	return;
}
/*---------------------------------------------------*\
||	빙고판 숫자를 지웠는지 확인하는 함수			  	  ||
\*---------------------------------------------------*/
int checkdel(int **bing, int num,int del) 
{
	int i, j, res = 0;
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			if (bing[i][j] == del)
			{
				res = 1;
				return res;
			}
		}
	}
	return res; // 1이면 지우지 않은 경우, 0이면 이미 지운경우
}
/*---------------------------------------------------*\
||	빙고 개수 확인 함수										  ||
||	행, 열, 대각선의 경우 빙고								  ||
\*---------------------------------------------------*/
int checkBing(int **bing, int num) // bingo 개수 반환
{
	int cnt = 0;
	int bingCnt = 0;
	int i, j;
	/*	행의 모습으로 빙고가 존재하는 경우 */
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			if (bing[i][j] == 'X')
			{
				cnt++;
				if (cnt == num)
					bingCnt++;
			}
		}
		cnt = 0;
	}
	/*	열의 모습으로 빙고가 존재하는 경우 */
	for (j = 0; j < num; j++) {
		for (i = 0; i < num; i++) {
			if (bing[i][j] == 'X')
			{
				cnt++;
				if (cnt == num)
					bingCnt++;
			}
		}
		cnt = 0;
	}
	/*	대각선의 형태로 빙고가 존재하는 경우 - (1) */
	for (i = 0; i < num; i++) {
		if (bing[i][i] == 'X')
		{
			cnt++;
			if (cnt == num)
				bingCnt++;
		}
	}
	cnt = 0;
	/*	대각선의 형태로 빙고가 존재하는 경우 - (2) */
	for (i = 0; i < num; i++) {
		if (bing[i][num - 1 - i] == 'X')
		{
			cnt++;
			if (cnt == num)
				bingCnt++;
		}
	}
	cnt = 0;

	return bingCnt;
}
void delBing(int **bing, int num)
{
	int i;
	for (i = 0; i < num; i++)
		free(bing[i]);
	free(bing);
	return;
}

/*-------------------------------------------------------------
		여기서부터 2)대전 모드에 필요한 함수들의 정의부
-------------------------------------------------------------*/


int random(int num)
{
	int res;
	res = rand() % num;
	return res+1; // 1~num까지의 난수 발생
}

void flush()
{
	while (getchar() != '\n') { ; }
}