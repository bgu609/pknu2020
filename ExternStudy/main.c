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

int input_data();
double average();
void print_data(double);


int count = 0;
static int total = 0;

// �����Լ�
int main(void)
{
    double avg;

    total = input_data();
    avg = average();
    print_data(avg);

    system("pause");
    return EXIT_SUCCESS;
}

void print_data(double avg)
{
    printf(" �Է��� ����� ���� : %d\n", count);
    printf(" ��ü �հ� ��� : %d, %.1lf\n", total, avg);
}