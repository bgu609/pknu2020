/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------
  first created - 2020.02.07
  writer - BGU.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void mem_malloc();
void anoth_loc();

// �����Լ�
int main(void)
{
    //mem_malloc();
    anoth_loc();


    system("pause");
    return EXIT_SUCCESS;
}

void mem_malloc(void)
{
    int* pi;
    int i, sum = 0;
    //double* pd;

    pi = (int*)malloc(5*sizeof(int));

    if (pi == NULL)
    {
        printf("#�޸𸮰� �����մϴ�.\n");
        exit(1);
    }
    
    for (i = 0; i < 5; i++)
    {
        printf("�ټ����� ���̸� �Է��ϼ��� (%d��) : ",(i+1));
        scanf("%d", &pi[i]);
        sum += pi[i];
    }

    printf("�ټ� ���� ��� ���� : %.1lf\n", (sum / 5.0));
    free(pi);

    /*
    pd = (double*)malloc(sizeof(double));

    *pi = 10;
    *pd = 3.4;

    printf("���������� ��� : %d\n", *pi);
    printf("�Ǽ������� ��� : %.1lf\n", *pd);
    
    free(pi);
    free(pd);
    */
}

void anoth_loc(void)
{
    int* pi;
    int size = 5;
    int count = 0;
    int num;
    int i;

    pi = (int*)calloc(size, sizeof(int));

    while (1)
    {
        printf("����� �Է��ϼ��� => ");
        scanf("%d", &num);
        if (num <= 0)
        {
            break;
        }
        if (count == size)
        {
            size += 5;
            pi = (int*)realloc(pi, size * sizeof(int));
        }
        pi[count++] = num;
    }

    for (i = 0; i < count; i++)
    {
        printf("%5d", pi[i]);
    }
    free(pi);
}