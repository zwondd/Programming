#include <stdio.h>

void sum();
int temp;
extern int k;

int main()
{
	int a=10;
	printf(" local a= %d \n", a);
	sum();
	printf(" global temp = %d \n", temp);

	printf("extern k = %d \n", k);
	sum();
	printf("extern k = %d \n", k);
}

void sum()
{
	temp += 100;
	k += 100;
}
