/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.11
  writer - BGU.
*/

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
#include <stdlib.h>
#include "sub.h"


void input_data(int* pa, int* pb)
{
    printf("두 정수 입력 : ");
    scanf("%d%d", pa, pb);
}

double average(int a, int b)
{
    int tot;
    double avg;

    tot = a + b;
    avg = tot / 2.0;

    return avg;
}