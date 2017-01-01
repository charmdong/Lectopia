#include <stdio.h>

int main()
{
	int aci;
	printf("ASCII code값을 입력하시오 : ");
	scanf("%d", &aci);
	printf("%d은 '%c'의 ASCII code 입니다.\n", aci, aci);
	return 0;
}