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
#include <windows.h>

struct profile
{
    char* name;
    int age;
    double height;
    char* intro;
};

// �����Լ�
int main(void)
{
    struct profile yuni;
    
    yuni.name = (char*)malloc(20);
    printf("�̸� : ");
    gets(yuni.name);

    yuni.age = 17;
    yuni.height = 164.5;

    yuni.intro = (char*)malloc(80);
    printf("�ڱ�Ұ� : ");
    gets(yuni.intro);

    system("cls");

    printf("     �̸�\t: %s\n", yuni.name);
    printf("     ����\t: %d\n", yuni.age);
    printf("      Ű\t: %.1lf\n", yuni.height);
    printf("   �ڱ�Ұ�\t: %s\n", yuni.intro);
    free(yuni.name);
    free(yuni.intro);

    system("pause");
    return EXIT_SUCCESS;
}