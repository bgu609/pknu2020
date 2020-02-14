/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------
  first created - 2020.02.13
  writer - BGW.

  �ǹ��� 1 : ��Ȯ�� ������ �ڵ��ε� �۾� ��ǻ�Ϳ� ���� ���� ������ ������ ( ����Ʈ ���� �Ҵ翡 �����ִ� �� ���� �ѵ� )
  => count�� 6 �̻� �ԷµǸ� ����
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node { int num; struct Node* Next; };

void insertNode(int count, struct Node* List);
void deleteNode(int index, struct Node* List);
void printNode(int count, struct Node* List);

// �����Լ�
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

    printf("����Ʈ ����ü ���� Ƚ�� : ");
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

void printNode(int count, struct Node* List) // ����Ʈ ��ȸ ���� ���� �� ��Ŵ
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