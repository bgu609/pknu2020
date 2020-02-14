/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.13
  writer - BGW.

  의문점 1 : 정확히 동일한 코드인데 작업 컴퓨터에 따라 오류 유무가 존재함 ( 리스트 동적 할당에 문제있는 것 같긴 한데 )
  => count에 6 이상 입력되면 오류
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node { int num; double double_data; struct Node* next; };


// 메인함수
int main(void)
{
    struct Node node = { 1, 1.0, 0 };
    struct Node* head=&node;

    printf("[%d, %lf, %p]\n", node.num, node.double_data, node.next);
    printf("head : %d\n", head->num);

    system("pause");
    return EXIT_SUCCESS;
}

void insertNode()
{

}

void deleteNode()
{

}

void printNode()
{

}