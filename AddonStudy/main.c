/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.10
  writer - BGU.
*/

#define _CRT_SECURE_NO_WARNINGS

#define PI 3.14159
#define LIMIT 10.0
#define MSG "Passed!"
#define ERR_PRN printf("허용 범위를 벗어났습니다!\n")
#define SUM(a,b) ((a)+(b))
#define MUL(a,b) ((a)*(b))
#define PRINT_EXPR(x) printf(#x " = %d\n", x)
#define NAME_CAT(x,y) (x ## y)
#define VER 7
#define BIT32

#include <stdio.h>
#include <stdlib.h>
#include "student.h"


// 메인함수
int main(void)
{
    int max;

#if VER>=6
    printf("버전 %d입니다.\n", VER);
#endif

#ifdef BIT16
    max = 32767;
#else
    max = 2147483647;
#endif

    printf("int형 변수의 최대값 : %d\n", max);


    /*
    int a = 10, b = 20;
    int x = 30, y = 40;
    int res;

    printf("a + b = %d\n", SUM(a, b));
    printf("x + y = %d\n", SUM(x, y));
    res = 30 / MUL(2, 5);
    printf("res : %d\n", res);

    int a1, a2;

    NAME_CAT(a, 1) = 10;
    NAME_CAT(a, 2) = 20;
    PRINT_EXPR(a1 + a2);
    PRINT_EXPR(a2 - a1);
    */


    /*
    Student a = { 315,"홍길동" };

    printf("학번 : %d, 이름 : %s\n", a.num, a.name);

    double radius, area;

    while (1)
    {
        printf("반지름을 입력하세요 (10 이하) : ");
        scanf("%lf", &radius);
        

        if (radius > LIMIT)
        {
            ERR_PRN;
            return 0;
        }
        else
        {
            area = PI * radius * radius;
            printf("원의 면적 : %.2lf (%s)\n", area, MSG);
        }
    }
    */
    
    system("pause");
    return EXIT_SUCCESS;
}