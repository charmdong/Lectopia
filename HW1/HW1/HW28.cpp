#include <stdio.h>

int main()
{
	char ch;
	int alpa = 0, num = 0, sep = 0, etc = 0;
	
	printf("# ���� ������ �Է� �Ͻÿ� :\n");
	while ((ch=getchar()) != EOF)
	{
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) // ��ҹ���
				alpa++;
			else if (ch >= '0' && ch <= '9') // ���ڹ����� ���
				num++;
			else if (ch == '\n' || ch == '\t' || ch == 32) // �������� ���
				sep++;
			else // ��Ÿ
				etc++;
	}
	printf("* ������ ��ҹ��� ���� : %d\n", alpa);
	printf("* ���ڹ��� ���� : %d\n", num);
	printf("* ���鹮��(space, tab, enter) ���� : %d\n", sep);
	printf("* �� �� ��Ÿ���� ���� : %d\n", etc);
	return 0;
}

