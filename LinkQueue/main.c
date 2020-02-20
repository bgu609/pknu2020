/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------

  writer - GWB.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct str_unit { char data; struct str* link; };
typedef struct str_unit str;

str* front;
str* rear;
str* list;

//3. 연결 큐가 공백 상태인지 검사하는 연산
int isEmpty();

//4. 연결 큐가 포화 상태인지 검사하는 연산
int isFull();

//5. 연결 큐의 rear에 원소를 삽입하는 연산
void enQueue(char item);

//6. 연결 큐의 front에서 원소를 삭제하는 연산
char deQueue();

//7. 연결 큐의 가장 앞에 있는 원소를 검색하는 연산
char peek();

//8. 연결 큐의 원소를 출력하는 연산
void printQ();

int main(void)
{
    front = NULL;
    rear = NULL;

    char item;
    printf("\n ***** 연결 큐 연산 ***** \n");
    printf("\n 삽입 A>>");  enQueue('A'); printQ();
    printf("\n 삽입 B>>");  enQueue('B'); printQ();
    printf("\n 삽입 C>>");  enQueue('C'); printQ();
    item = peek();    printf(" peek item : %c \n", item);
    printf("\n 삭제  >>");  item = deQueue(); printQ();
    printf("\t삭제 데이터: %c", item);
    printf("\n 삭제  >>");  item = deQueue(); printQ();
    printf("\t삭제 데이터: %c", item);
    printf("\n 삭제  >>");  item = deQueue(); printQ();
    printf("\t\t삭제 데이터: %c", item);

    printf("\n 삽입 D>>");  enQueue('D'); printQ();
    printf("\n 삽입 E>>");  enQueue('E'); printQ();
}

//3. 연결 큐가 공백 상태인지 검사하는 연산
int isEmpty()
{
    if (front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//4. 연결 큐가 포화 상태인지 검사하는 연산
int isFull()
{
    return 0;
}

//5. 연결 큐의 rear에 원소를 삽입하는 연산
void enQueue(char item)
{
    list = (str*)malloc(sizeof(str));

    list->data = item;
    list->link = NULL;

    if (front == NULL)
    {
        front = list;
        rear = list;
    }
    else
    {
        rear->link = list;
        rear = list;
    }
}

//6. 연결 큐의 front에서 원소를 삭제하는 연산
char deQueue()
{
    if (isEmpty(front))
    {
        exit(1);
    }
    else
    {
        str* dead;

        dead = front;
        char dead_data = dead->data;
        front = front->link;

        if (isEmpty(front))
        {
            rear->link = NULL;
        }

        free(dead);

        return dead_data;
    }
}

//7. 연결 큐의 가장 앞에 있는 원소를 검색하는 연산
char peek()
{
    if (isEmpty())
    {
        printf(" Queue is empty\n");
        exit(1);
    }
    else
    {
        return front->data;
    }
}

//8. 연결 큐의 원소를 출력하는 연산
void printQ()
{
    str* read;

    read = front;

    printf(" Circular Queue : [ ");
    while (read != NULL)
    {
        if (isEmpty())
        {
            exit(1);
        }

        printf("%c ", read->data);
        read = read->link;
    }
    printf("]");
}