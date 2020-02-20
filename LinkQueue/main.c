/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
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

//3. ���� ť�� ���� �������� �˻��ϴ� ����
int isEmpty();

//4. ���� ť�� ��ȭ �������� �˻��ϴ� ����
int isFull();

//5. ���� ť�� rear�� ���Ҹ� �����ϴ� ����
void enQueue(char item);

//6. ���� ť�� front���� ���Ҹ� �����ϴ� ����
char deQueue();

//7. ���� ť�� ���� �տ� �ִ� ���Ҹ� �˻��ϴ� ����
char peek();

//8. ���� ť�� ���Ҹ� ����ϴ� ����
void printQ();

int main(void)
{
    front = NULL;
    rear = NULL;

    char item;
    printf("\n ***** ���� ť ���� ***** \n");
    printf("\n ���� A>>");  enQueue('A'); printQ();
    printf("\n ���� B>>");  enQueue('B'); printQ();
    printf("\n ���� C>>");  enQueue('C'); printQ();
    item = peek();    printf(" peek item : %c \n", item);
    printf("\n ����  >>");  item = deQueue(); printQ();
    printf("\t���� ������: %c", item);
    printf("\n ����  >>");  item = deQueue(); printQ();
    printf("\t���� ������: %c", item);
    printf("\n ����  >>");  item = deQueue(); printQ();
    printf("\t\t���� ������: %c", item);

    printf("\n ���� D>>");  enQueue('D'); printQ();
    printf("\n ���� E>>");  enQueue('E'); printQ();
}

//3. ���� ť�� ���� �������� �˻��ϴ� ����
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

//4. ���� ť�� ��ȭ �������� �˻��ϴ� ����
int isFull()
{
    return 0;
}

//5. ���� ť�� rear�� ���Ҹ� �����ϴ� ����
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

//6. ���� ť�� front���� ���Ҹ� �����ϴ� ����
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

//7. ���� ť�� ���� �տ� �ִ� ���Ҹ� �˻��ϴ� ����
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

//8. ���� ť�� ���Ҹ� ����ϴ� ����
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