/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------
  first created - 2020.02.13
  writer - BGW.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void change_score(int score);

// �����Լ�
int main(void)
{
    int int_score = 0;

    printf("������������ ������ �Է��ϼ��� : ");
    scanf("%d", &int_score);

    change_score(int_score);
    

    system("pause");
    return EXIT_SUCCESS;
}

void change_score(int score)
{
    int A_limit = 90;
    int B_limit = 70;
    int C_limit = 60;
    int D_limit = 50;

    if (A_limit <= score)
    {
        printf("��ȯ���� : A\n");
    }
    else if (B_limit <= score)
    {
        printf("��ȯ���� : B\n");
    }
    else if (C_limit <= score)
    {
        printf("��ȯ���� : C\n");
    }
    else if (D_limit <= score)
    {
        printf("��ȯ���� : D\n");
    }
    else
    {
        printf("��ȯ���� : F\n");
    }
}