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

struct score { int kor; int eng; int math; };

struct address { char name[20]; int age; char tel[20]; char addr[80]; };

void print_list(struct address* lp);
void address();
//void score_point();

// �����Լ�
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
        {"ȫ�浿", 23, "111-1111", "�︪�� ����"},
        {"�̼���", 35, "222-2222", "���� ��õ��"},
        {"�庸��", 19, "333-3333", "�ϵ� û����"},
        {"������", 15, "444-4444", "�泲 õ��"},
        {"���߱�", 45, "555-5555", "Ȳ�ص� ����"}
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

    printf("���� : %d\n", (*ps).kor);
    printf("���� : %d\n", (*ps).eng);
    printf("���� : %d\n", (*ps).math);
}