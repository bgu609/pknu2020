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

struct Node { int num; struct Node* Next; };

void insertNode(int count, struct Node* List);
void deleteNode(int index, struct Node* List);
void printNode(int count, struct Node* List);

// 메인함수
int main(void)
{
    int count = 0;
    int index = 2;

    struct Node* List = malloc(sizeof(struct Node));
    struct Node* head = malloc(sizeof(struct Node));

    List[0].num = 1;
    List[0].Next = NULL;
    head = &List[0];

    //printf("[%d, %p]\n", List[0].num, List[0].Next);
    printf("head : %d\n", head->num);

    printf("리스트 연결체 증가 횟수 : ");
    scanf("%d", &count);

    insertNode(count, List);

    printNode(count, List);

    deleteNode(index, List);

    printNode(count, List);

    system("pause");
    return EXIT_SUCCESS;
}

void insertNode(int count, struct Node* List)
{
    struct Node* point;
    struct Node* next_point;

    for (int list_mem = 0; list_mem < (count + 1); list_mem++)
    {
        point = &List[list_mem];
        next_point = &List[list_mem + 1];

        next_point->num = point->num + 1;
        next_point->Next = NULL;
        List[list_mem].Next = &List[list_mem + 1];
    }
}

void deleteNode(int index, struct Node* List)
{
    struct Node* point;

    point = &List[index];
    point->Next = NULL;
    point = &List[index - 1];
    point->Next = &List[index + 1];
}

void printNode(int count, struct Node* List) // 리스트 순회 아직 도입 안 시킴
{
    int list_mem = 0;

    struct Node* point;

    for (int list_mem = 0; list_mem < (count + 1); list_mem++)
    {
        point = &List[list_mem];
        printf("%d\n", point->num);
        printf("%p => %p\n", &List[list_mem], point->Next);
    }
}