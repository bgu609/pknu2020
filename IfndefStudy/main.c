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
#include "point.h"
#include "line.h"


// �����Լ�
int main(void)
{
    Line a = { {1,2},{5,6} };
    Point b;

    b.x = (a.first.x + a.second.x) / 2;
    b.y = (a.first.y + a.second.y) / 2;
    printf("���� ��� ���� ��ǥ : (%.1lf,%.1lf)\n", b.x, b.y);

    system("pause");
    return EXIT_SUCCESS;
}