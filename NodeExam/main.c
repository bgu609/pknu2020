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

struct Node { int num; struct Node* Next; };
typedef struct Node NODE;

NODE* insertNode(int count);
NODE* deleteNode(int index, NODE* List);
void printNode(int count, NODE* List);
NODE* custom_insert(int count);
NODE* custom_delete(int index, NODE* List);

// 메인함수
int main(void)
{
    int count = 0;
    int index = 0;
    
    

    NODE* List;
    NODE* head;
    List = insertNode(0);

    while (1)
    {
        char insert=0;
        printf("\n리스트를 추가하시겠습니까? (y/n): ");
        insert = getchar();

        if (insert == 'n')
        {
            printf("\n종료\n");
            break;
        }
        else if (insert == 'y')
        {
            List = custom_insert(count);
            printNode(count, List);
        }
        else
        {
            printf("\n잘못된 명령 입력\n");
        }

        char delete=0;
        printf("\n리스트 연결체를 삭제하시겠습니까? (y/n): ");
        delete = getchar();

        if (delete == 'n')
        {
            printf("\n종료\n");
            break;
        }
        else if (delete == 'y')
        {
            List = custom_delete(index, List);
            printNode(count, List);
        }
        else
        {
            printf("\n잘못된 명령 입력\n");
        }
    }
    
    /*
    List = custom_insert(count);

    printNode(count, List);

    List = custom_delete(index, List);

    printNode(count, List);
    */

    system("pause");
    return EXIT_SUCCESS;
}

NODE* custom_insert(int count)
{
    NODE* List;

    printf("리스트 연결체 증가 횟수 : ");
    scanf("%d", &count);
    List = insertNode(count);

    return List;
}

NODE* custom_delete(int index, NODE* List)
{
    printf("삭제할 리스트 연결체 : ");
    scanf("%d", &index);
    List = deleteNode(index, List);

    return List;
}

NODE* insertNode(int count)
{
    int size = sizeof(NODE) * (count + 1);

    NODE* List;
    List = (NODE *) malloc(size);

    List[0].num = 1;
    List[0].Next = NULL;

    printf("내부 초기화 : (0x%p)[%d, %p]\n\n", &List[0], List[0].num, List[0].Next);

    NODE* point;
    NODE* next_point;

    int insert_num;

    next_point = &List[1];
    List[0].Next = next_point;
    for (int list_mem = 0; list_mem < (count+1); list_mem++)
    {
        point = &List[list_mem];
        next_point = &List[list_mem + 1];

        if (list_mem != count)
        {
            printf("%d번째 연결체에 데이터 입력 : ", list_mem + 2);
            scanf("%d", &insert_num);
            next_point->num = insert_num;
        }
        point->Next = next_point;
    }
    point->Next = NULL;

    for (int list_mem = 0; list_mem < (count + 1); list_mem++)
    {
        printf("(0x%p)[%d, %p]\n", &List[list_mem], List[list_mem].num, List[list_mem].Next);
    }

    return List;
}

NODE* deleteNode(int index, NODE* List)
{
    NODE* point;

    point = &List[index-1];
    point->Next = NULL;
    point = &List[index - 2];
    point->Next = &List[index];

    return List;
}

void printNode(int count, NODE* List)
{
    NODE* point;

    printf("\n[");
    while (List != NULL)
    {
        printf(" %d ", List->num);
        List = List->Next;
    }
    printf("]\n");
}