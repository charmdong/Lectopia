#include <stdio.h>

int main()
{
	char ch;
	int alpa = 0, num = 0, sep = 0, etc = 0;
	
	printf("# 영문 문장을 입력 하시오 :\n");
	while ((ch=getchar()) != EOF)
	{
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) // 대소문자
				alpa++;
			else if (ch >= '0' && ch <= '9') // 숫자문자의 경우
				num++;
			else if (ch == '\n' || ch == '\t' || ch == 32) // 구분자의 경우
				sep++;
			else // 기타
				etc++;
	}
	printf("* 영문자 대소문자 개수 : %d\n", alpa);
	printf("* 숫자문자 개수 : %d\n", num);
	printf("* 여백문자(space, tab, enter) 개수 : %d\n", sep);
	printf("* 그 외 기타문자 개수 : %d\n", etc);
	return 0;
}

