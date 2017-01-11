#include <stdio.h>

void swap(int *,int);

int main()
{
	int a[] = { 1,2,3,4,5,6,7,8,9};
	int i, size;
	size = sizeof(a) / sizeof(a[0]); // 배열 요소의 개수
	printf("처음 배열에 저장된 값 : ");
	for (i = 0; i < size; i++)
		printf("%3d", a[i]);
	printf("\n");
	
	swap(a, size);
	printf("바뀐 배열에 저장된 값 : ");
	for (i = 0; i < size; i++)
		printf("%3d", a[i]);
	printf("\n");
	
	return 0;
}

void swap(int *num,int size)
{
	int *n1,*n2;
	int tmp;
	int i;

	for (i = 0; i < size/2; i++)
	{
		n1 = &num[i];
		n2 = &num[size - i - 1];
		tmp = *n1;
		*n1 = *n2;
		*n2 = tmp;
	}
	return;
}