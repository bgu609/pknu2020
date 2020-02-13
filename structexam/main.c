/*
  filename - main.c
  version - 1.0
  description - ±âº» ¸ÞÀÎ ÇÔ¼ö
  --------------------------------------------------------------------------------
  first created - 2020.02.13
  writer - BGW.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct student { int kor; int math; int eng; };

void score_average(struct student* scores, int count);

// ¸ÞÀÎÇÔ¼ö
int main(void)
{
    struct student score[3];

    int count = sizeof(score) / sizeof(score[0]);

    for (int i = 0; i < count; i++)
    {
        printf("%d¹ø %d°ú¸ñ Á¡¼ö ÀÔ·Â : ",i+1,count);
        scanf("%d%d%d", &score[i].kor, &score[i].math, &score[i].eng);
    }

    score_average(score, count);

    system("pause");
    return EXIT_SUCCESS;
}

void score_average(struct student *scores, int count)
{
    int sum = 0;
    int avg = 0;

    for (int i = 0; i < count; i++)
    {
        sum += scores[i].kor;
    }
    avg = sum / count;
    printf("kor ÃÑÇÕ : %d\n", sum);
    printf("kor Æò±Õ : %d\n", avg);

    sum = 0;
    avg = 0;

    for (int i = 0; i < count; i++)
    {
        sum += scores[i].math;
    }
    avg = sum / count;
    printf("math ÃÑÇÕ : %d\n", sum);
    printf("math Æò±Õ : %d\n", avg);

    sum = 0;
    avg = 0;

    for (int i = 0; i < count; i++)
    {
        sum += scores[i].eng;
    }
    avg = sum / count;
    printf("eng ÃÑÇÕ : %d\n", sum);
    printf("eng Æò±Õ : %d\n", avg);
}