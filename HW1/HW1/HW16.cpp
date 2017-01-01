#include <stdio.h>

int input();
int cal_fee(int);
void output(int);

int main()
{
	int num;
	int result;
	num = input(); // 역의 개수
	result = cal_fee(num); // 요금 계산 결과
	output(result); // 출력
	return 0;
}

int input()
{
	int station;

	printf("역수를 입력하세요 : ");
	scanf("%d", &station);

	return station;
}

int cal_fee(int x)
{
	int fee;
	int over = 0; // 초과 정거장의 갯수
	int tmp4; // 4정거장의 초과 정거장 발생시
	int tmp2; // 2정거장의 초과 정거장 발생시

	if (x >= 1 && x < 6) // 1~5개 정거장의 경우
		fee = 600;
	else if (x >= 6 && x <= 10) // 6~10개 정거장의 경우
		fee = 800;
	else if (x > 10) // 10개 정거장 이상의 경우
	{
		fee = 800; // 기본요금 8000원
		over = x - 10; // 초과 정거장의 수
		if (over == 1 || over == 2) // 초과 정거장의 개수가 1 or 2일 때
			fee += 100;
		else if (over == 3 || over == 4) // 초과 정거장수가 3 or 4일 때
			fee += 200;
		else if (over > 4) // 초과 정거장수가 4개 이상일 때
		{
			tmp4 = over / 4; // tmp4 : 초과 정거장수를 4로 나눈 몫
			over = over - tmp4 * 4; 
			if (over == 1 || over == 2)
				fee = fee + tmp4 * 200 + 100;
			else if (over == 3)
				fee = fee + tmp4 * 200 + 200;
		}
	}
	return fee;
}

void output(int result)
{
	printf("요금 : %d\n", result);
}