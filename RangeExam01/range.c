#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>

void range_array(int count, int* Array)
{
    for (int i = 0; i < (count - 1); i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (Array[i] > Array[j])
            {
                int temp = Array[i];
                Array[i] = Array[j];
                Array[j] = temp;
            }
        }
    }
}

int input_array(int* Array)
{
    int size;

    printf("배열 사이즈 입력 : ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        printf("%d번 멤버 입력 : ",i+1);
        scanf("%d", &Array[i]);
    }

    return size;
}