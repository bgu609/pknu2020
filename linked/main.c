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


struct str_unit { char item; struct str_unit* link; };
typedef struct str_unit str;


str* head;
str* tail;
str* stack;


int isEmpty();
int isFull();
void push(char item);
char pop();
char peek();
void printStack();
void rev_printStack();

int main(void)
{
    head = NULL;
    tail = NULL;

    char item;
    printf("\n** ���� ���� ���� **\n");
    printStack();
    push('A');    printStack();       // 1 ����
    push('B');    printStack();       // 2 ����
    push('C');    printStack();       // 3 ����

    item = peek(); printStack();    // ���� top�� ���� ���
    printf("\t peek => %c", item);

    item = pop();  printStack();    // ����
    printf("\t pop  => %c", item);

    item = pop();  printStack();    // ����
    printf("\t pop  => %c", item);

    item = pop();  printStack();    // ����
    printf("\t pop  => %c", item);
}

int isEmpty() // ����ִ��� ����
{
    if (tail == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull() // ���� ��ȭ���� ����
{
    return 0;
}

void push(char item) // ���ÿ� ���Ҹ� �����ϴ� ����
{
    stack = (str*)malloc(sizeof(str));

    stack->item = item;
    stack->link = NULL;

    if (head == NULL)
    {
        head = stack;
        tail = stack;
    }
    else
    {
        tail->link = stack;
        tail = stack;
    }
}

char pop() // ���ÿ� ���Ҹ� �����ϴ� ����
{
    if (isEmpty())
    {
        printf("\nstack is empty\n");
        exit(1);
    }

    str* read;
    str* dead;
    read = head;
    dead = tail;
    int data = dead->item;

    if (read == dead)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        while (read->link != dead)
        {
            read = read->link;
        }

        read->link = NULL;
        tail = read;
    }

    free(dead);

    return data;
}

char peek() // ������ top ���Ҹ� �˻��ϴ� ����
{
    if (isEmpty())
    {
        printf("\nstack is empty\n");
        exit(1);
    }

    return tail->item;
}

void printStack() // ������ ���Ҹ� ����ϴ� ����
{
    str* read;
    read = head;

    printf("\nSTACK [ ");
    while (read != NULL)
    {
        if (isEmpty())
        {
            exit(1);
        }

        printf("%c ", read->item);
        read = read->link;
    }
    printf("] ");
}

void rev_printStack() // ������ ���Ҹ� reverse ����ϴ� ����
{
    str* read;
    str* stop;

    printf("\nSTACK [ ");
    read = head;
    stop = tail;

    if (isEmpty() == 0)
    {
        printf("%d ", stop->item);
    }

    while (stop != head)
    {
        while (read->link != stop)
        {
            if (isEmpty())
            {
                exit(1);
            }

            read = read->link;
        }
        printf("%d ", read->item);
        stop = read;
        read = head;
    }

    printf("]\n");
}




/*struct str_unit { int num; struct str* link; };
typedef struct str_unit str;

str* head;
str* list;
str* point;

int isEmpty();
int isFull();
void push(int item);
int pop();
int peek();
void printStack();

int main(void)
{
    head = (str*)malloc(sizeof(str));
    head->link = NULL;

    int item;
    printf("\n** ���� ���� ���� **\n");
    printStack();
    push(1);    printStack();       // 1 ����
    push(2);    printStack();       // 2 ����
    push(3);    printStack();       // 3 ����

    item = peek(); printStack();    // ���� top�� ���� ���
    printf("\t peek => %d", item);

    item = pop();  printStack();    // ����
    printf("\t pop  => %d", item);

    item = pop();  printStack();    // ����
    printf("\t pop  => %d", item);

    item = pop();  printStack();    // ����
    printf("\t pop  => %d", item);
}

int isEmpty() // ����ִ��� ����
{
    return 0;
}

int isFull() // ���� ��ȭ���� ����
{
    return 0;
}

void push(int item) // ���ÿ� ���Ҹ� �����ϴ� ����
{
    list = (str*)malloc(sizeof(str));

    list->num = item;
    list->link = NULL;
    
    if (head->link == NULL)
    {
        head->link = list;
        return;
    }
    
    point = head->link;

    while (point->link != NULL)
    {
        point = point->link;
    }

    point->link = list;
}

int pop() // ���ÿ� ���Ҹ� �����ϴ� ����
{
    if (head->link == NULL)
    {
        return;
    }
    
    str* before = head;
    point = head->link;

    while (point->link != NULL)
    {
        before = point;
        point = point->link;
    }

    int num = point->num;
    before->link = NULL;

    free(point);

    return num;
}

int peek() // ������ top ���Ҹ� �˻��ϴ� ����
{
    point = head->link;

    while (point->link != NULL)
    {
        point = point->link;
    }

    return point->num;
}

void printStack() // ������ ���Ҹ� ����ϴ� ����
{
    point = head->link;

    printf("\n[");
    while (point != NULL)
    {
        printf("%d", point->num);
        point = point->link;
    }
    printf("]");
}*/





/*
int main(void)
{
    head = (str*)malloc(sizeof(str));
    head->link = NULL;

    list = (str*)malloc(sizeof(str)*(LIST_SIZE-1));
    list[0].link = NULL;

    int item;
    printf("\n** ���� ���� ���� **\n");
    printStack();
    push(1);    printStack();       // 1 ����
    push(2);    printStack();       // 2 ����
    push(3);    printStack();       // 3 ����

    item = peek(); printStack();    // ���� top�� ���� ���
    printf("\t peek => %d", item);

    item = pop();  printStack();    // ����
    printf("\t pop  => %d", item);

    item = pop();  printStack();    // ����
    printf("\t pop  => %d", item);

    item = pop();  printStack();    // ����
    printf("\t pop  => %d", item);

    free(head);
    free(list);
}

int isEmpty() // ����ִ��� ����
{
    if ((head->link) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull() // ���� ��ȭ���� ����
{
    
}

void push(int item) // ���ÿ� ���Ҹ� �����ϴ� ����
{
    if (isEmpty() == 1)
    {
        head->link = &list[0];
        list[0].num = item;
    }
    else
    {
        list[top].link = &list[top];
        list[top+1].num = item;
        list[top+1].link = NULL;
        top++;
    }
}

int pop() // ���ÿ� ���Ҹ� �����ϴ� ����
{
    if (isEmpty() == 1)
    {
        printf("\nstack is empty\n");
    }
    else
    {
        int temp = list[top].num;
        list[top].num = NULL;
        top--;

        if (top < 0)
        {
            return temp;
        }

        list[top].link = NULL;

        return temp;
    }
}

int peek() // ������ top ���Ҹ� �˻��ϴ� ����
{
    if (isEmpty())
    {
        printf("\n\nStack is Empty\n\n");
        exit(1);
    }
    else
    {
        return list[top].num;
    }
}

void printStack() // ������ ���Ҹ� ����ϴ� ����
{
    int i = 0;

    printf("\n[");
    for (i; i <= top; i++)
    {
        if (isEmpty() == 1)
        {
            printf("]");
            return;
        }
        printf("%d", list[i].num);
    }
    printf("]");
}*/