#include <stdio.h>

int main()
{
	unsigned int his, liter, art;
	int total = 0;
	double avg = 0;

	printf("역사, 문학, 예능 점수를 입력하세요 : ");
	scanf("%d %d %d", &his, &liter, &art);

	total = his + liter + art;
	avg = (double)total / 3;
	printf("총점은 %d 이고 평균은 %.2lf 입니다.\n", total, avg);
	return 0;
}