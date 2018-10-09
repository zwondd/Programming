#include <stdio.h>
#include<string.h>

/*
	문제1) 적당한 길이의 문자열 입력 받아 존재하는 숫자의 총 합 계산
*/

int ConvToInt(char c)
{
	static int diff = 1 - '1';
	return c + diff;
}

int main(void)
{
	char str[50];
	int len, i;
	int sum = 0;

	printf("문자열 입력\n");
	fgets(str, sizeof(str), stdin);
	len = strlen(str);

	for (i = 0; i < len; i++) {
		if ('1' <= str[i] && '9' >= str[i]) {
			sum += ConvToInt(str[i]);
		}
	}
	printf("총 합: %d", sum);
	return 0;
}
