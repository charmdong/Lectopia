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
	Dic ary[10]; // ����ü �迭 ����
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
			case 5: printf("\n<<< ���α׷��� �����մϴ� >>>\n\n"); break;
			default:printf("\n* 1~5�� �߿� �������ּ��� *\n\n");
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
		printf("# �ܾ �Է��Ͻÿ� : ");
		scanf("%s", (p + i)->word);
		flush();
		
		if (strcmp((p + i)->word, "end") == 0)
			break;
		
		if (checkData(p, (p + i)->word, *wcnt))
			printf("\n*** �̹� �����ϴ� �ܾ� �Դϴ� ***\n\n");
		else {
			(p + i)->len = strlen((p + i)->word);
			printf("# ���� �Է��Ͻÿ� : ");
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

int checkData(Dic *p, char *str,int wcnt) // 0 : �ߺ� ���� 1 : �ߺ� ����
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
		printf("*** �Էµ� �ܾ� ������ �����ϴ� ***\n");
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
		printf("\n# ã�� �ܾ �Է��Ͻÿ� : ");
		scanf("%s", cmp);
		if (strcmp(cmp, "end") == 0)
			break;
		flush();
		for (i = 0; i < wcnt; i++)
		{
			if (strcmp((p + i)->word, cmp) == 0) // ã�� �ܾ �ִ� ���
			{
				printf("  �ܾ��� �� : %s\n", (p + i)->mean);
				break;
			}
		}
		if (i == wcnt)
			printf("  NOT FOUND!!!\n");
	}
	return;
}

void delData(Dic *p, int *wcnt) // ������ ������ ����� �κ� �߰��ؾ���
{
	int i;
	while (1)
	{
		char del[MAX_WORD] = { 0 };
		char choice;
		printf("# ������ �ܾ �Է��ϼ��� : ");
		scanf("%s", del);
		if (strcmp(del, "end") == 0)
			break;
		flush();
		for (i = 0; i < *wcnt; i++)
		{
			if (strcmp((p + i)->word, del) == 0) // ã�� �ܾ �ִ� ���
			{
				printf("# ������ �����Ͻðڽ��ϱ�?(y/n) : ");
				scanf("%c", &choice);
				if (choice == 'y')
				{
					printf("  �����Ǿ����ϴ�.\n");
					flush();
					*wcnt--;
				}
				else {
					printf("  ������ ��ҵǾ����ϴ�.\n");
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