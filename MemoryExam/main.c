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

void mem_mal();

// �����Լ�
int main(void)
{
    mem_mal();



    system("pause");
    return EXIT_SUCCESS;
}

void mem_mal(void)
{
    int* pi;
    double* pd;

    pi = (int*)malloc(sizeof(int));
    if (pi == NULL)
    {
        printf("#�޸𸮰� �����մϴ�.\n");
        exit(1);
    }
    
    pd = (double*)malloc(sizeof(double));

    *pi = 10;
    *pd = 3.4;

    printf("���������� ��� : %d\n", *pi);
    printf("�Ǽ������� ��� : %.1lf\n", *pd);

    free(pi);
    free(pd);
}