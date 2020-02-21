/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------

  writer - GWB.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int size, double score[]);
double trimmed(int size, int cut, double score[]);
double adjust(int size, int cut, double score[]);

int main(void)
{
    int size;
    int cut;
    double avr;

    printf("input size : ");
    scanf("%d", &size);
    printf("cut : ");
    scanf("%d", &cut);

    double* score;
    score = (double*)malloc(sizeof(double) * size);

    for (int i = 0; i < size; i++)
    {
        printf("score %d : ", i + 1);
        scanf("%lf", &score[i]);
    }

    sort(size, score);

    avr = trimmed(size, cut, score);

    printf("%.2lf\n", avr);

    avr = adjust(size, cut, score);

    printf("%.2lf\n", avr);

    free(score);
}

void sort(int size, double score[])
{
    int count = size;
    double temp;

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (score[j] > score[j + 1])
            {
                temp = score[j + 1];
                score[j + 1] = score[j];
                score[j] = temp;
            }
        }
        for (int k = 0; k < size; k++)
        {
            printf("%.1lf", score[k]);
        }
        printf("\n");
    }
}

double trimmed(int size, int cut, double score[])
{
    double sum = 0;

    for (int i = cut; i < size - cut; i++)
    {
        sum = sum + score[i];
    }

    double avr = sum / (size - cut - cut);

    return avr;
}

double adjust(int size, int cut, double score[])
{
    double sum = 0;

    for (int i = 0; i < cut; i++)
    {
        sum = sum + score[cut];
    }

    for (int i = cut; i < size - cut; i++)
    {
        sum = sum + score[i];
    }

    for (int i = size - cut; i < size; i++)
    {
        sum = sum + score[size - cut - 1];
    }

    double avr = sum / (size);

    return avr;
}