#include <stdio.h>
#include <string.h>

/*
	문제2) 총 3개의 배열을 선언 후 문자열 str1, str2을 입력 받은 후 str3에 순차적으로 복사
*/

int main()
{
	char str1[20];
	char str2[20];
	char str3[40];

	fputs("str1 입력: ", stdout);
	fgets(str1, sizeof(str1), stdin);
	str1[strlen(str1) - 1] = 0;

	fputs("str2 입력: ", stdout);
	fgets(str2, sizeof(str2), stdin);
	str2[strlen(str2) - 1] = 0;

	strcpy_s(str3, sizeof(str1),str1);
	strcat_s(str3, sizeof(str3)- sizeof(str1), str2);

	printf("str3 문자열: %s \n", str3);
	return 0;
}