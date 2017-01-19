#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_WORD 20
#define MAX_MEAN 80

typedef struct {
	char word[MAX_WORD];
	char mean[MAX_MEAN];
	int len;
}Dic;

void menu(Dic *ary, int *wcnt);
void storData(Dic *p, int *wcnt);
int checkData(Dic *p, char *str, int wcnt);
void printData(Dic *p, int wcnt);
void sortData(Dic *p, int wcnt);
void searchData(Dic *p,int wcnt);
void delData(Dic *p, int *wcnt);
void flush();

int main()
{
	Dic ary[10]; // 구조체 배열 선언
	int wcnt = 0; // word Count

	menu(ary, &wcnt);
	return 0;
}

void menu(Dic *ary,int *wcnt)
{
	int choice;

	while (1)
	{
		printf("==========================\n");
		printf("|| Donggun's Dictionary ||\n");
		printf("==========================\n");
		printf("1. Input\n");
		printf("2. Display\n");
		printf("3. Search\n");
		printf("4. Delete\n");
		printf("5. Quit\n");
		printf("\nSel : ");
		if (scanf("%d", &choice)) {
			switch (choice) {
			case 1:
				storData(ary, wcnt);
				break;
			case 2: 
				printData(ary, *wcnt);
				break;
			case 3: 
				searchData(ary, *wcnt);
				break;
			case 4: break;
			case 5: printf("\n<<< 프로그램을 종료합니다 >>>\n\n"); break;
			default:printf("\n* 1~5번 중에 선택해주세요 *\n\n");
			}
			if (choice == 5)
				break;
		}
		else
			flush();
	}
	return;
}

void storData(Dic *p,int *wcnt)
{
	printf("\n");
	int i;
	while(1) {
		i = *wcnt;
		printf("# 단어를 입력하시오 : ");
		scanf("%s", (p + i)->word);
		flush();
		
		if (strcmp((p + i)->word, "end") == 0)
			break;
		
		if (checkData(p, (p + i)->word, *wcnt))
			printf("\n*** 이미 존재하는 단어 입니다 ***\n\n");
		else {
			(p + i)->len = strlen((p + i)->word);
			printf("# 뜻을 입력하시오 : ");
			fgets((p + i)->mean, MAX_MEAN, stdin);
			((p + i)->mean)[strlen((p + i)->mean) - 1] = '\0';

			if (strcmp((p + i)->mean, "end") == 0)
				break;
			printf("\n");
			(*wcnt)++;
		}
	}
	printf("\n");
	return;
}

int checkData(Dic *p, char *str,int wcnt) // 0 : 중복 없음 1 : 중복 있음
{
	int i;
	for (i = 0; i < wcnt; i++) {
		if (strcmp((p + i)->word, str) == 0)
			return 1;
	}
	return 0;
}

void printData(Dic *p, int wcnt) 
{
	int i;
	printf("\n");
	if (wcnt == 0)
		printf("*** 입력된 단어 정보가 없습니다 ***\n");
	else {
		sortData(p, wcnt);
		for (i = 0; i < wcnt; i++) {
			if(strlen((p+i)->mean)>50)
				printf("%d.\t%10s(%d) : %.50s~\n", i + 1, (p + i)->word, (p + i)->len, (p + i)->mean);
			else
				printf("%d.\t%10s(%d) : %s\n", i + 1, (p + i)->word, (p + i)->len, (p + i)->mean);
		}
	}
	printf("\n");
	return;
}

void sortData(Dic *p, int wcnt)
{
	Dic tmp;
	int i, j;
	for (i = 0; i < wcnt-1; i++)
	{
		for (j = i + 1; j < wcnt; j++)
		{
			if (strcmp(p[i].word, p[j].word) > 0)
			{
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
	return;
}

void searchData(Dic *p,int wcnt) 
{
	int i;
	while (1)
	{
		char cmp[MAX_WORD] = { 0 };
		printf("\n# 찾을 단어를 입력하시오 : ");
		scanf("%s", cmp);
		if (strcmp(cmp, "end") == 0)
			break;
		flush();
		for (i = 0; i < wcnt; i++)
		{
			if (strcmp((p + i)->word, cmp) == 0) // 찾는 단어가 있는 경우
			{
				printf("  단어의 뜻 : %s\n", (p + i)->mean);
				break;
			}
		}
		if (i == wcnt)
			printf("  NOT FOUND!!!\n");
	}
	return;
}

void delData(Dic *p, int *wcnt) // 삭제시 앞으로 땡기는 부분 추가해야함
{
	int i;
	while (1)
	{
		char del[MAX_WORD] = { 0 };
		char choice;
		printf("# 삭제할 단어를 입력하세요 : ");
		scanf("%s", del);
		if (strcmp(del, "end") == 0)
			break;
		flush();
		for (i = 0; i < *wcnt; i++)
		{
			if (strcmp((p + i)->word, del) == 0) // 찾는 단어가 있는 경우
			{
				printf("# 정말로 삭제하시겠습니까?(y/n) : ");
				scanf("%c", &choice);
				if (choice == 'y')
				{
					printf("  삭제되었습니다.\n");
					flush();
					*wcnt--;
				}
				else {
					printf("  삭제가 취소되었습니다.\n");
					flush();
					break;
				}
			}
		}
		if (i == *wcnt)
			printf("  NOT FOUND!!!\n");
	}
}

void flush()
{
	while (getchar() != '\n') { ; }
}