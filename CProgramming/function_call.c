#include <stdio.h>
/*
	call by value vs call by referecne 함수
	swap 함수
*/

void SwapByValue(int a, int b);
void SwapByReference(int*  a, int* b);


int main(void) 
{
	int x = 5, y = 10;
	SwapByValue(x, y);
	printf(" x= %d, y=%d \n", x, y);

	SwapByReference(&x,&y);
	printf(" x= %d, y=%d \n", x, y);

}

// call by value 
void SwapByValue(int a, int b) 
{
	printf(" a= %d, b=%d \n", a, b);
	int temp = a;
	a = b;
	b = temp;
	printf(" a= %d, b=%d \n", a, b);
}

// call by reference
void SwapByReference(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}