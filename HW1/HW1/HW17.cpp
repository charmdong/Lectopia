#include <stdio.h>

int main()
{
	char name[50] = { 0 };
	double height;
	char sex;

	printf("# 성명 입력 : ");
	scanf("%[^\n]s", name);
	getc(stdin);

	printf("# 키 입력(cm단위) : ");
	scanf("%lf", &height);
	getc(stdin);

	printf("# 성별입력(M/F) : ");
	scanf("%c", &sex);
	
	if (sex == 'M')
		printf("%s씨의 키는 %.2lfcm이고 남성입니다.\n", name, height);
	else
		printf("%s씨의 키는 %.2lfcm이고 여성입니다.\n", name, height);
}