/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�, ����������
  --------------------------------------------------------------------------------
  first created - 2020.02.11
  writer - BGU.
*/

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rangeEX.h"



// �����Լ�
int main(void)
{
    int NumArray[5];
    int count = input_array(NumArray);

    print_array(count, NumArray);

    range_array(count, NumArray);

    print_array(count, NumArray);

    system("pause");
    return EXIT_SUCCESS;
}