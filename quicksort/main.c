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


int n = 0;

int array[] = { 69,10,30,2,16,8,31,22 };
int read = sizeof(array) / sizeof(int);

int pivot(int array[], int start, int end);
void divide(int array[], int start, int end);

int main(void)
{
    printf("[초기 상태]\n");
    for (int i = 0; i < read; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n");

    int start = 0;
    int end = sizeof(array) / sizeof(int) - 1;

    divide(array, start, end);
}


int pivot(int array[], int start, int end)
{
    int pivot = (end + start) / 2;
    int Left = start;
    int Right = end;
    int change;

    printf("[%d단계 : pivot=%d]\n", ++n, array[pivot]);

    while (Left <= Right)
    {
        for (Left; Left < Right; Left++)
        {
            if (array[Left] >= array[pivot])
            {
                break;
            }
        }

        for (Right; Right > Left; Right--)
        {
            if (array[Right] < array[pivot])
            {
                break;
            }
        }

        if (Left == Right)
        {
            change = array[pivot];
            array[pivot] = array[Left];
            array[Left] = change;

            for (int i = 0; i < read; i++)
            {
                printf("%d ", array[i]);
            }
            printf("\n\n");

            return Left;
        }
        else
        {
            change = array[Right];
            array[Right] = array[Left];
            array[Left] = change;

            Left++;
            Right--;
        }
    }

    for (int i = 0; i < read; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

void divide(int array[], int start, int end)
{
    int div;
    if (start < end)
    {
        div = pivot(array, start, end);
        divide(array, start, div - 1);
        divide(array, div + 1, end);
    }
}