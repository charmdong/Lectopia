#include <stdio.h>

int main()
{
	char name[50] = { 0 };
	double height;
	char sex;

	printf("# ���� �Է� : ");
	scanf("%[^\n]s", name);
	getc(stdin);

	printf("# Ű �Է�(cm����) : ");
	scanf("%lf", &height);
	getc(stdin);

	printf("# �����Է�(M/F) : ");
	scanf("%c", &sex);
	
	if (sex == 'M')
		printf("%s���� Ű�� %.2lfcm�̰� �����Դϴ�.\n", name, height);
	else
		printf("%s���� Ű�� %.2lfcm�̰� �����Դϴ�.\n", name, height);
}