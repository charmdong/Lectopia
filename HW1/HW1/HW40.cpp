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
		printf("���� ����� ���� �ݾ� �Է� : ");
		if (scanf("%d", &price) == 1 && price > 0 ) //���� �Է� 
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
							printf("ũ����(%d ��), �����(%d ����), �ݶ�(%d ��)\n", i, j, k);
							cnt++;
						}
					}
				}	
			}
			if (cnt != 0)
				printf("��� �����Ͻðڽ��ϱ�?\n\n");
			else
				printf("����� ������ �ݾ׿� �¾� �������� ����� ���� �������� �ʽ��ϴ�.\n\n");
		}
		else // ���� �Է½�
			break;
	}
	return 0;
}
