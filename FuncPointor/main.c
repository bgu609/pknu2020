/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.06
  writer - BGU.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int sum(int, int);
//void func(int(*fp)(int, int));
//int sum(int a, int b);
//int mul(int a, int b);
//int user_max(int a, int b);
void void_point();

// 메인함수
int main(void) 
{
    /*
    int (*fp)(int, int);
    int res;

    fp = sum;
    res = fp(10, 20);
    printf("result : %d\n", res);
    */

    /*
    int sel;

    printf("01 두 정수의 합\n");
    printf("02 두 정수의 곱\n");
    printf("03 두 정수 중에서 큰 값 계산\n");
    printf("원하는 연산을 선택하세요 : ");
    scanf("%d", &sel);

    switch (sel)
    {
    case 1: func(sum); break;
    case 2: func(mul); break;
    case 3: func(user_max); break;
    }
    */

    void_point();

	system("pause");
	return EXIT_SUCCESS;
}

void func(int(*fp)(int, int))
{
    int a, b;
    int res;

    printf("두 정수의 값을 입력하세요 : ");
    scanf("%d%d", &a, &b);
    res = fp(a, b);
    printf("결과값은 : %d\n", res);
}

int sum(int a, int b)
{
    return(a + b);
}

int mul(int a, int b)
{
    return(a * b);
}

int user_max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void void_point(void)
{
    int a = 10;
    double b = 3.5;
    void* vp;

    vp = &a;
    printf("a : %d\n", *(int*)vp);

    vp = &b;
    printf("b : %.1lf\n", *(double*)vp);
}