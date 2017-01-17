#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>

void swapStr(char *p[5]);
void outputRes(char *p[5]);
void reset(char *temp,int len);

int main()
{
	char *p[5];
	char temp[1000] = { 0 };
	int i, j, len = 0;

	for (i = 0; i < 5; i++)
	{
		printf("# ¹®ÀÚ¿­ %d : ", i + 1);
		scanf("%s", temp);
		len = strlen(temp) + 1;
		p[i] = (char*)malloc(sizeof(char)*len);
		assert(p[i] != NULL);
		strcpy(p[i], temp);
		reset(temp, len - 1);
	}
	printf("\n");
	swapStr(p);
	outputRes(p);

	for (i = 0; i < 5; i++)
		free(p[i]);

	return 0;
}

void swapStr(char *p[5])
{
	int i,j, res;
	char *tmp;
	for (i = 0; i < 4; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			if (strcmp(p[i], p[j])>0)
			{
				tmp = p[i];
				p[i] = p[j];
				p[j] =tmp;
			}
		}
	}
	return;
}

void outputRes(char *p[5])
{
	int i;
	for (i = 0; i < 5; i++)
		printf("%d.  %s\n", i+1,p[i]);
	return;
}

void reset(char *temp,int len)
{
	int i;
	for (i = 0; i<len; i++)
		temp[i] = '\0';
	return;
}