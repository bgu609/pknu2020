#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*
	int a = 20, b = 3;
	double res;

	res = ((double)a) / ((double)b);

	printf("a=%d, b=%d\n", a, b);
	printf("a / b �� ��� : %.1lf\n", res);

	a = (int)res;
	printf("(int)%.1lf�� ��� : %d\n", res, a);
	*/

	int a = 10;
	double b = 3.4;
	long double ld=1.23123123123;
	int sizecheck = sizeof(ld);

	printf("int�� ������ ũ�� : %d\n", sizeof(a));
	printf("double�� ������ ũ�� : %d\n", sizeof(b));
	printf("������ ��� 10�� ũ�� : %d\n", sizeof(10));
	printf("1.5+3.4 ������ ������� ũ�� : %d\n", sizeof(1.5+3.4));
	printf("char �ڷ����� ũ�� : %d\n", sizeof(char));
	printf("%Lf\n", ld);

	system("pause");
	
	return 0;
}