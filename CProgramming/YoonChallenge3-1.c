#include <stdio.h>

/*
	열혈 C : 도전 프로그래밍3
	1) 길이가 4X4 인 int 형 2차원 배열 선언, 배열의 요소들을 오른쪽 방향으로 90도씩 이동시켜 그 결과를 출력
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