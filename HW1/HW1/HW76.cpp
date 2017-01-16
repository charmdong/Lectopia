#include <stdio.h>

char* ustrchr(char *str, char ch);
char* ustrcat(char *s1, char *s2);
char* ustrstr(char *s1, char *s2);
void ustrcpy(char *s1, char *s2);
unsigned int ustrlen(char *str);
int ustrcmp(char *s1, char *s2);
void reset(char *str, int len);

int main()
{
	char str[100];
	char s1[100];
	char s2[100];
	char ch;
	
	int choice;

	while (1)
	{
		char str[100]="Hacker School";
		char s1[100] = "Lectopia";
		char s2[100] = "C Program";
		char s3[100] = "lectopia";
		char s4[100] = "pia";
		char ch='S';

		printf("----------------MENU----------------\n");
		printf("1. ustrchr TEST\n");
		printf("2. ustrcat TEST\n");
		printf("3. ustrstr TEST\n");
		printf("4. ustrcpy TEST\n");
		printf("5. ustrlen TEST\n");
		printf("6. ustrcmp TEST\n");
		printf("7. Exit the Program\n");
		printf("# 메뉴 선택 : ");
		scanf("%d", &choice);
		getchar();
		switch (choice) {
		case 1:printf("\n### ustrchr TEST ###\n");
			printf("# str : %s, ch : %c\n",str,ch);
			printf("# Result : %s\n\n", ustrchr(str, ch));
			break;
		case 2:printf("\n### ustrcat TEST ###\n");
			printf("# s1 : %s, s2 : %s\n",s1,s2);
			printf("# Result : %s\n\n", ustrcat(s1, s2));
			break;
		case 3:printf("\n### ustrstr TEST ###\n");
			printf("# s1 : %s, s4 : %s\n", s1, s4);
			printf("# Result : %s\n\n", ustrstr(s1, s4));
			break;
		case 4:printf("\n### ustrcpy TEST ###\n");
			printf("# s1 : %s, s2 : %s\n", s1, s2);
			ustrcpy(s1, s2);
			printf("# Result : %s\n\n",s1);
			break;
		case 5:printf("\n### ustrlen TEST ###\n");
			printf("# str : %s\n", str);
			printf("# 이 문자열의 길이는 : %d\n\n", ustrlen(str));
			break;
		case 6:printf("\n### ustrcmp TEST ###\n");
			printf("# s1 : %s, s3 : %s\n", s1, s3);
			printf("[ r : 1 => s1 > s2, r : 0 => s1 == s2, r : -1 => s1 < s2 ]\n");
			printf("# Result : %d\n\n", ustrcmp(s1, s3));
			break;
		case 7:printf("# Exit the TEST Program !\n\n"); break;
		default: printf("잘못 입력하셨습니다.\n");
		}
		if (choice == 7)
			break;
	}
	
	return 0;
}
/*--------------------------------------------------------------*\
||	str 문자열 내에 문자 ch가 있으면 찾은 위치의 주소를 리턴		||
||	못찾으면 NULL pointer 반환											||
\*--------------------------------------------------------------*/
char *ustrchr(char *str, char ch)
{
	int len = ustrlen(str);
	int i;
	for (i = 0; i < len; i++)
	{
		if (ch == str[i])
			return str + i;
	}
	return NULL;
}

/*--------------------------------------------------------------*\
||	s1 문자열 뒤에 s2 문자열을 덧붙인 후 s1의 시작주소 리턴		||
\*--------------------------------------------------------------*/
char *ustrcat(char *s1, char *s2)
{
	int i,res;
	for (i = 0;; i++)
	{
		if (s1[i] == '\0')
		{
			res = i;
			break;
		}
	}
	for (i = i;; i++)
	{
		s1[i] = s2[i - res];
		if (s2[i - res] == '\0')
			break;
	}
	return s1;
}

/*--------------------------------------------------------------*\
||	s1 문자열 내에 s2 문자열이 부분 문자열로 존재하는 검사		||
||	찾으면 부분 문자열의 시작주소 리턴									||
||	못찾으면 NULL pointer 리턴											||
\*--------------------------------------------------------------*/
char* ustrstr(char *s1, char *s2)
{
	int lenS1 = ustrlen(s1), lenS2 = ustrlen(s2);
	int i,j,res=1;

	for (i = 0; i < lenS1; i++)
	{
		if (s1[i] == s2[0])
		{
			for (j = 1; j < lenS2; j++)
			{
				if (s1[j + i] != s2[j])
				{
					res = 0;
					break;
				}
			}
			if (res = 1)
				return s1 + i;
		}
	}
	return NULL;
}

/*--------------------------------------------------------------*\
||	s1 주소에 s2 문자열을 복사, 리턴값 없음							||
\*--------------------------------------------------------------*/
void ustrcpy(char *s1, char *s2)
{
	int i;
	for (i = 0; s1[i] != '\0'; i++)
		s1[i] = 0;
	for (i = 0; s2[i] != '\0'; i++)
		s1[i] = s2[i];
	return;
}

/*--------------------------------------------------------------*\
||	str 문자열의 길이를 구하여 리턴 함									||
\*--------------------------------------------------------------*/
unsigned int ustrlen(char *str)
{
	unsigned int len;
	int i;
	for (i = 0;; i++)
		if (str[i] == '\0') break;
	len = i;
	return len;
}

/*--------------------------------------------------------------*\
||	s1, s2 두 문자열의 문자를 순차적으로 비교하여 같으면 0,		||
||	s1 이 크면 1, s1 이 작으면 -1 리턴									||
\*--------------------------------------------------------------*/
int ustrcmp(char *s1, char *s2)
{
	int i;
	int lenS1, lenS2;
	lenS1 = ustrlen(s1), lenS2 = ustrlen(s2);
	
	if (lenS1 > lenS2)
		return 1;
	else if (lenS2 > lenS1)
		return -1;
	else // 길이가 같은 경우, 소문자(아스키 코드값이 높은거)가 큰 것
	{
		for (i = 0; i < lenS1; i++)
		{
			if (s1[i] > s2[i])
				return 1;
			else if (s1[i] < s2[i])
				return -1;
		}
		return 0;
	}
}

void reset(char *str, int len)
{
	int i;
	for (i = 0; i < len; i++)
		str[i] = 0;
	return;
}