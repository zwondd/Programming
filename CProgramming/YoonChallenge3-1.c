#include <stdio.h>

/*
	���� C : ���� ���α׷���3
	1) ���̰� 4X4 �� int �� 2���� �迭 ����, �迭�� ��ҵ��� ������ �������� 90���� �̵����� �� ����� ���
*/

void RotateArray(int(*ptr)[4])
{
	int tempArr[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			tempArr[j][3 - i] = ptr[i][j];
		}
	}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			ptr[i][j] = tempArr[i][j];
}

void PrintArray(int(*ptr)[4])
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%2d   ", ptr[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

int main()
{
	int arr[4][4];
	int tmp = 1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = tmp++;
		}
	}
	RotateArray(arr);
	PrintArray(arr);

	RotateArray(arr);
	PrintArray(arr);

	RotateArray(arr);
	PrintArray(arr);
}