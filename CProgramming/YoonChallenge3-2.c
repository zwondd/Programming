#include <stdio.h>
#include <stdlib.h>

void PrintSnailArray(int n)
{
	int **visitArr, **arr;
	int dir = 0;
	int cur_x = 0;
	int cur_y = 0;
	int x[] = { 0,1,0,-1 };
	int y[] = { 1,0,-1,0 };

	// visited 배열 메모리 할당
	visitArr = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++)
		visitArr[i] = (int(*)) malloc(sizeof(int)*n);

	// arr 배열 메모리 할당
	arr = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++)
		arr[i] = (int(*)) malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visitArr[i][j] = 0;
		}
	}

	int tmp = 0;
	while (tmp < n*n) {
		visitArr[cur_x][cur_y] = 1;
		arr[cur_x][cur_y] = tmp + 1;
		tmp++;

		int next_x = cur_x + x[dir % 4];
		int next_y = cur_y + y[dir % 4];

		if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)
			dir++;
		else if (visitArr[next_x][next_y] == 1)
			dir++;

		cur_x = cur_x + x[dir % 4];
		cur_y = cur_y + y[dir % 4];
	}

	// Print
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%2d  ", arr[i][j]);
		printf("\n");
	}
}


int main(void)
{
	int n;
	scanf_s("%d", &n);
	printf("입력받은 숫자 : %d \n", n);
	PrintSnailArray(n);


}

