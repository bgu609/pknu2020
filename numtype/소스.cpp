#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdio.h>
#include <stdlib.h>

/*
	메인함수
*/

int main()
{
	printf("%d\n",100);
	printf("%f\n", 3.14);
	printf("%lf\n", 3.14);
	printf("%.1f\n", 3.1415); // 소수점 첫번째 자리
	printf("%.10f\n", 3.14);
	printf("%.1f+%.1f=%.1f\n", 10.2, 3.4, 10.2+3.4);
	
	system("pause");
	
	return 0;
}