#include <stdio.h>
#include <string.h>

int main()
{
	char name[1000] = { 0 };
	double height;
	char sex;

	printf("# ���� �Է� : ");
	fgets(name,sizeof(name),stdin);
	name[strlen(name) - 1] = '\0';

	printf("# Ű �Է�(cm����) : ");
	scanf("%lf", &height);


	printf("# �����Է�(M/F) : ");
	scanf(" %c", &sex); // ������ �ν��ϱ� ���� ����
	
	if (sex == 'M')
		printf("%s���� Ű�� %.2lfcm�̰� �����Դϴ�.\n", name, height);
	else // sex == 'F'
		printf("%s���� Ű�� %.2lfcm�̰� �����Դϴ�.\n", name, height);
}