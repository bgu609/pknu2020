/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.13
  writer - BGW.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node { int num; struct Node *Next; };

void insertNode(int count, struct Node* List);
void deleteNode(int index);
void printNode(int count, struct Node* List);

// 메인함수
int main(void)
{
    struct Node List[10] = { {1, NULL} };
    struct Node* head = malloc(sizeof(struct Node));
    head = &List[0];

    int count=0;

    printf("head : %d\n", head->num);

    printf("리스트 연결체 증가 횟수 : ");
    scanf("%d", &count);

    struct Node* List_point;
    //List = (struct Node*) realloc(List, sizeof(struct Node) * (count + 1));
    insertNode(count, List);

    printNode(count, List);

    system("pause");
    return EXIT_SUCCESS;
}

void insertNode(int count, struct Node *List)
{
    struct Node* point;
    struct Node* next_point;

    for (int list_mem = 0; list_mem < count; list_mem++)
    {
        point = &List[list_mem];
        next_point = &List[list_mem + 1];

        next_point->num = point->num+1;
        next_point->Next = NULL;
        List[list_mem].Next = &List[list_mem + 1];
    }
}

void deleteNode(int index)
{

}

void printNode(int count, struct Node* List)
{
    int list_mem = 0;

    struct Node* point;

    for (int list_mem = 0; list_mem < count; list_mem++)
    {
        point = &List[list_mem];
        printf("%d\n", point->num);
    }
}