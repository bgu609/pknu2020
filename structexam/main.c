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


struct student { int kor; int math; int eng; };

void score_average(struct student* scores);

// 메인함수
int main(void)
{
    struct student scores[] = { {10,20,30},{40,50,60},{70,80,90} };

    score_average(scores);

    system("pause");
    return EXIT_SUCCESS;
}

void score_average(struct student *scores)
{
    int count = 3;

    int sum = 0;
    int avg = 0;

    for (int i = 0; i < count; i++)
    {
        sum += scores[i].kor;
    }
    avg = sum / count;
    printf("kor sum : %d\n", sum);
    printf("kor avg : %d\n", avg);

    sum = 0;
    avg = 0;

    for (int i = 0; i < count; i++)
    {
        sum += scores[i].math;
    }
    avg = sum / count;
    printf("math sum : %d\n", sum);
    printf("math avg : %d\n", avg);

    sum = 0;
    avg = 0;

    for (int i = 0; i < count; i++)
    {
        sum += scores[i].eng;
    }
    avg = sum / count;
    printf("eng sum : %d\n", sum);
    printf("eng avg : %d\n", avg);
}