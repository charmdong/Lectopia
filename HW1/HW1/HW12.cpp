#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char ary[20];
	char ary2[20] = { 0 };
	char ary3[20] = { 0 };
	int i;

	printf("이름을 입력하시오 : ");
	scanf("%[^\n]s", ary);

	printf("\"%s\"\n", ary);
	if (strlen(ary) < 19)
	{
		for (i = 19; i > 0; i--)
			ary2[i] = ary[];
	}

}