#include <stdio.h>

void print_array(int count, int* Array)
{
    for (int i = 0; i < count; i++)
    {
        printf("%5d", Array[i]);
    }
    printf("\n");
}