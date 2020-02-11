/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수, 분할컴파일
  --------------------------------------------------------------------------------
  first created - 2020.02.11
  writer - BGU.
*/

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "line.h"


// 메인함수
int main(void)
{
    Line a = { {1,2},{5,6} };
    Point b;

    b.x = (a.first.x + a.second.x) / 2;
    b.y = (a.first.y + a.second.y) / 2;
    printf("선의 가운데 점의 좌표 : (%.1lf,%.1lf)\n", b.x, b.y);

    system("pause");
    return EXIT_SUCCESS;
}