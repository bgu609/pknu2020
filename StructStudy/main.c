/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
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

// 메인함수
int main(void)
{
    struct profile yuni;
    
    yuni.name = (char*)malloc(20);
    printf("이름 : ");
    gets(yuni.name);

    yuni.age = 17;
    yuni.height = 164.5;

    yuni.intro = (char*)malloc(80);
    printf("자기소개 : ");
    gets(yuni.intro);

    system("cls");

    printf("     이름\t: %s\n", yuni.name);
    printf("     나이\t: %d\n", yuni.age);
    printf("      키\t: %.1lf\n", yuni.height);
    printf("   자기소개\t: %s\n", yuni.intro);
    free(yuni.name);
    free(yuni.intro);

    system("pause");
    return EXIT_SUCCESS;
}