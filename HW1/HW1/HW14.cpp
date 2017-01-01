#include <stdio.h>
#include <string.h>

int main()
{
	char ary[] = { 0 };
	int len,len2,len3;
	int i;

	printf("* 문자열 입력 : ");
	scanf("%s", ary);

	len = strlen(ary);
	len2 = len / 2;
	len3 = len - len2; // 이 값이 홀수, 짝수인 경우 나눠서 생각
	printf("[");

	for (i = 0; i <len-len2; i++)
		printf(" ");
	for (i = 0; i < len3; i++)
		printf("%c", ary[i]);
	printf(". . .]\n");

	return 0;
}