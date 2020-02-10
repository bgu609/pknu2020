/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.10
  writer - BGU.
*/

#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func();

// 메인함수
int main(void)
{
    printf("컴파일 날짜와 시간 : %s, %s\n\n", __DATE__, __TIME__);
    printf("파일명 : %s\n", __FILE__);
    printf("함수명 : %s\n", __FUNCTION__);
    printf("행번호 : %d\n", __LINE__);

#line 100 "macro.c"
    func();

    return 0;

    system("pause");
    return EXIT_SUCCESS;
}

void func(void)
{
    printf("\n");
    printf("파일명 : %s\n", __FILE__);
    printf("함수명 : %s\n", __FUNCTION__);
    printf("행번호 : %d\n", __LINE__);
}