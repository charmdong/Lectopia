#include <stdio.h>
#include <string.h>

int main()
{
	char ary[] = { 0 };
	int len,len2,len3;
	int i;

	printf("* ���ڿ� �Է� : ");
	scanf("%s", ary);

	len = strlen(ary);
	len2 = len / 2;
	len3 = len - len2; // �� ���� Ȧ��, ¦���� ��� ������ ����
	printf("[");

	for (i = 0; i <len-len2; i++)
		printf(" ");
	for (i = 0; i < len3; i++)
		printf("%c", ary[i]);
	printf(". . .]\n");

	return 0;
}