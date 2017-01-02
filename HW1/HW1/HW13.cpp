#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char family[1000] = { 0 };
	char name[1000] = { 0 };
	int len1, len2;
	
	printf("#성을 입력하시오 : ");
	scanf("%s", family);
	
	printf("#이름을 입력하시오 : ");
	scanf("%s", name);
	
	printf("%s %s\n", family, name);
	len1 = strlen(family);
	len2 = strlen(name);
	
	printf("%*d %*d\n", len1, len1,len2,len2);

	return 0;
}
