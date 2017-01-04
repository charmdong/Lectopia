#include <stdio.h>
#include <string.h>

int main()
{
	char name[1000] = { 0 };
	double height;
	char sex;

	printf("# 성명 입력 : ");
	fgets(name,sizeof(name),stdin);
	name[strlen(name) - 1] = '\0';

	printf("# 키 입력(cm단위) : ");
	scanf("%lf", &height);


	printf("# 성별입력(M/F) : ");
	scanf(" %c", &sex); // 구분자 인식하기 위해 띄어쓰기
	
	if (sex == 'M')
		printf("%s씨의 키는 %.2lfcm이고 남성입니다.\n", name, height);
	else // sex == 'F'
		printf("%s씨의 키는 %.2lfcm이고 여성입니다.\n", name, height);
}