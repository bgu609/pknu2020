/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.13
  writer - BGW.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void change_score(int score);

// 메인함수
int main(void)
{
    int int_score = 0;

    printf("정수형식으로 점수를 입력하세요 : ");
    scanf("%d", &int_score);

    change_score(int_score);
    

    system("pause");
    return EXIT_SUCCESS;
}

void change_score(int score)
{
    int A_limit = 90;
    int B_limit = 70;
    int C_limit = 60;
    int D_limit = 50;

    if (A_limit <= score)
    {
        printf("변환점수 : A\n");
    }
    else if (B_limit <= score)
    {
        printf("변환점수 : B\n");
    }
    else if (C_limit <= score)
    {
        printf("변환점수 : C\n");
    }
    else if (D_limit <= score)
    {
        printf("변환점수 : D\n");
    }
    else
    {
        printf("변환점수 : F\n");
    }
}