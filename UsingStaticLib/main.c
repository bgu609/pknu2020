/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수,라이브러리 사용
  --------------------------------------------------------------------------------
  first created - 2020.02.11
  writer - BGW.
*/


#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int get_total(int* data,int size);

// 메인함수
int main(void) 
{
    puts("┌─────────────────────────┐");
    puts("│     정적 라이브러리     │");
    puts("└─────────────────────────┘");

    int data[] = { 10,20,30,40,50,60,70,80,90,100 };
    int result = get_total(data, 10);

    int count = sizeof(data) / sizeof(data[0]);

    printf("\n\n");
    printf("    [ data ]  : ");
    for (int i = 0; i < count; i++)
    {
        printf(" %d ", data[i]);
    }
    printf("\n\n");
    printf("     result  =  %d\n",result);
    printf("\n\n");

	system("pause");
	return EXIT_SUCCESS;
}