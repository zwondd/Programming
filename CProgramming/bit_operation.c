#include <stdio.h>
void display(unsigned char * a);  //bit 출력
int getBit(int num, int i);  //특정 bit값 얻어내기
int setBit(int num, int i);  //특정 bit값을 1로 만들기
int clearBit(int num, int i);  //특정 bit값을 0으로 지우기
int clearBitsMSBthrough1(int num, int i);  //MSB부터 i승 비트까지 모두 0으로 지움
int clearBits1through0(int num, int i);  //i승 비트~0승 비트까지 모두 0으로 지움
int updateBit(int num, int i, int value);  //i승 비트의 값을 value(0 or 1)값으로 변경

int main()
{
	unsigned char a = 1;

	a = ~a;
	display(&a);

	printf("get Bit : %d \n", getBit(2, 0));

	int sb = setBit(1, 6);
	printf("set Bit \n");
	display(&sb);

	int cb = clearBit(15, 1);
	printf("clearBit \n");
	display(&cb);

	int cbMSB = clearBitsMSBthrough1(127, 4);
	printf("clearBitsMSBthrough 1 \n");
	display(&cbMSB);


	int tmp = clearBits1through0(127, 3);
	printf("clearBits1through0 \n");
	display(&tmp);

	int u = updateBit(127, 1, 0);
	printf("update \n");
	display(&u);

}


void display(unsigned char * a)
{
	int i;
	for (i = 7; i >= 0; i--) {
		if (*a&(1 << i))
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}


int getBit(int num, int i)
{
	return  (num&(1 << i)) >> i;
}

int setBit(int num, int i)
{
	return num | (1 << i);
}

int clearBit(int num, int i)
{
	return num & ~(1 << i);
}

int clearBitsMSBthrough1(int num, int i)
{
	/*int j;
	int cbMSB = 0;
	for (j = 0; j < i; j++) {
		cbMSB |= 1 << j;
	}
	return num & cbMSB;*/

	return num &= ((1 << i) - 1);
}

int clearBits1through0(int num, int i)
{
	/*int j;
	int tmp = 0;
	for (j = 0; j < i; j++) {
		tmp |= 1 << j;
	}
	tmp = ~tmp;
	return num & tmp;*/

	return num &= ~((1 << (i + 1)) - 1);
}

int updateBit(int num, int i, int value)
{
	printf("value : %d \n", value);
	if (value == 1)
		return num | (1 << i);
	else
		return num & (1 << i);
}




