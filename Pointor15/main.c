/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.06
  writer - BGU.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void double_pointor();
//void swap_pointor();
//void print_str(char** pps, int cnt);
//void point_compare();
//void point_2d();
void print_ary(int(*)[4]);

// 메인함수
int main(void) 
{
    //double_pointor();

    /*
    char* pa = "success";
    char* pb = "failure";

    printf("pa->%s, pb->%s\n", pa, pb);
    swap_pointor(&pa,&pb);
    printf("pa->%s, pb->%s\n", pa, pb);
    */

    /*
    char* ptr_ary[] = { "eagle","tiger","lion","squirrel" };
    int count;

    count = sizeof(ptr_ary) / sizeof(ptr_ary[0]);
    print_str(ptr_ary, count);
    */

    //point_compare();

    //point_2d();

    int ary[3][4]= { {1,2,3,4},{5,6,7,8},{9,10,11,12} };

    print_ary(ary);


	system("pause");
	return EXIT_SUCCESS;
}

void double_pointor(void)
{
    int a = 10;
    int* pi;
    int** ppi;

    pi = &a;
    ppi = &pi;

    printf("변수   변수값     &연산     *연산     **연산\n");
    printf("  a%10d%10u\n", a, &a);
    printf(" pi%10u%10u%10d\n", pi, &pi,*pi);
    printf("ppi%10d%10u%10u%10u\n", ppi, &ppi,*ppi,**ppi);
}

void swap_pointor(char **ppa,char**ppb)
{
    char* pt;
    pt = *ppa;
    *ppa = *ppb;
    *ppb = pt;
}

void print_str(char** pps, int cnt)
{
    int i;

    for (i = 0; i < cnt; i++)
    {
        printf("%s\n", pps[i]);
    }
}

void point_compare(void)
{
    int ary[5] = { 1,2,3,4 };

    printf("ary의 값 : %u\t", ary);
    printf("ary의 주소 : %u\n", &ary);
    printf("ary+1 : %u\t", ary + 1);
    printf("&ary+1 : %u\n", &ary + 1);
    printf("%d\n", *(ary + 1));
    printf("%p\n", *&ary + 1);
}

void point_2d(void)
{
    int ary[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
    int(*pa)[4];
    int i, j;

    pa = ary;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", pa[i][j]);
        }
        printf("\n");
    }
}

void print_ary(int(*pa)[4])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", pa[i][j]);
        }
        printf("\n");
    }
}