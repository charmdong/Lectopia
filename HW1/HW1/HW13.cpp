#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char family[20] = { 0 };
	char name[20] = { 0 };
	int len1, len2;
	int i;

	printf("<%s><%s>\n", family, name);
	printf("#���� �Է��Ͻÿ� : ");
	scanf("%s", family);
	
	printf("#�̸��� �Է��Ͻÿ� : ");
	scanf("%s", name);
	
	printf("%s %s\n", family, name);
	len1 = strlen(family);
	len2 = strlen(name);
	
	for (i = 1; i < len1; i++)
		printf(" ");
	printf("%d ", len1);

	for (i = 1; i < len2; i++)
		printf(" ");
	printf("%d\n", len2);

	return 0;
}
