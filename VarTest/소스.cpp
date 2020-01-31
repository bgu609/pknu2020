#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*
	short sh = 32767;
	int in = 2147483647;
	long ln = 2147483647;
	long long lln = 123451234512345;

	printf("short형 변수 출력 : %d\n", sh);
	printf("int형 변수 출력 : %d\n", in);
	printf("long형 변수 출력 : %ld\n", ln);
	printf("long long형 변수 출력 : %lld\n", lln);
	*/

	unsigned int ui;

	ui = 4294967295;
	printf("%d\n", ui);
	printf("%u\n", ui);
	ui = -1;
	printf("%u\n", ui);
	printf("%d\n", ui);
	
	system("pause");
	
	return 0;
}