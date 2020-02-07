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

struct score { int kor; int eng; int math; };

struct address { char name[20]; int age; char tel[20]; char addr[80]; };

void print_list(struct address* lp);
void address();
//void score_point();

// 메인함수
int main(void)
{
    address();
    //score_point();

    system("pause");
    return EXIT_SUCCESS;
}

void print_list(struct address* lp)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("%10s%5d%15s%20s\n", (*(lp+i)).name, (*(lp + i)).age, (*(lp + i)).tel, (*(lp + i)).addr);
    }
}

void address(void)
{
    struct address list[5] = {
        {"홍길동", 23, "111-1111", "울릉도 독도"},
        {"이순신", 35, "222-2222", "서울 건천동"},
        {"장보고", 19, "333-3333", "완도 청해진"},
        {"유관순", 15, "444-4444", "충남 천안"},
        {"안중근", 45, "555-5555", "황해도 해주"}
    };

    print_list(list);

    /*
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("%10s%5d%15s%20s\n", list[i].name, list[i].age, list[i].tel, list[i].addr);
    }
    */
}

void score_point(void)
{
    struct score yuni = { 90,80,70 };
    struct score* ps = &yuni;

    printf("국어 : %d\n", (*ps).kor);
    printf("영어 : %d\n", (*ps).eng);
    printf("수학 : %d\n", (*ps).math);
}