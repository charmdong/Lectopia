#include <stdio.h>
#include <string.h>

int main()
{
	char str[1000] = { 0 };
	int len;
	int i;

	printf("* ���ڿ� �Է� : ");
	scanf("%s", str);
	len = strlen(str);
	
	printf("[%*.*s. . .]\n", len,len/2, str);
	
	return 0;
}