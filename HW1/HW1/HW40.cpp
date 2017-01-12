#include <stdio.h>

int main()
{
	int cream, shp, cola; // 500, 700, 400
	int price;
	int total=0;
	int i,j,k;
	int cnt = 0;

	while (1)
	{
		printf("현재 당신의 소유 금액 입력 : ");
		if (scanf("%d", &price) == 1 && price > 0 ) //정상 입력 
		{
			for (i = 1; i*500 <= price; i++)
			{
				for (j = 1; j*700 <=price; j++)	
				{
					for (k = 1; k*400 <=price; k++)
					{
						cream = i * 500;
						shp = j * 700;		
						cola = k * 400;
						total = cream + shp + cola;
						if (total == price)
						{
							printf("크림빵(%d 개), 새우깡(%d 봉지), 콜라(%d 병)\n", i, j, k);
							cnt++;
						}
					}
				}	
			}
			if (cnt != 0)
				printf("어떻게 구입하시겠습니까?\n\n");
			else
				printf("당신이 소유한 금액에 맞아 떨어지는 경우의 수가 존재하지 않습니다.\n\n");
		}
		else // 문자 입력시
			break;
	}
	return 0;
}
