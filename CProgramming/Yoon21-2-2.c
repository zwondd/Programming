#include <stdio.h>
#include <string.h>

/*
	����2) �� 3���� �迭�� ���� �� ���ڿ� str1, str2�� �Է� ���� �� str3�� ���������� ����
*/

int main()
{
	char str1[20];
	char str2[20];
	char str3[40];

	fputs("str1 �Է�: ", stdout);
	fgets(str1, sizeof(str1), stdin);
	str1[strlen(str1) - 1] = 0;

	fputs("str2 �Է�: ", stdout);
	fgets(str2, sizeof(str2), stdin);
	str2[strlen(str2) - 1] = 0;

	strcpy_s(str3, sizeof(str1),str1);
	strcat_s(str3, sizeof(str3)- sizeof(str1), str2);

	printf("str3 ���ڿ�: %s \n", str3);
	return 0;
}