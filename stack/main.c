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
#define STACK_SIZE 100

typedef int element;

element stack[STACK_SIZE];
int top = -1;

int isEmpty();
int isFull();
void push(element item);
element pop();
int peek();
void printStack();

int main(void)
{
    element item;
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
    if (top == -1)
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
    if (top == STACK_SIZE - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(element item) // ���ÿ� ���Ҹ� �����ϴ� ����
{
    if (isFull())
    {
        printf("\n\nStack is Full\n\n");
        return;
    }
    else
    {
        stack[++top] = item;
    }
}

element pop() // ���ÿ� ���Ҹ� �����ϴ� ����
{
    if (isEmpty())
    {
        printf("\n\nStack is Empty\n\n");
        return 0;
    }
    else
    {
        return stack[top--];
    }
}

element peek() // ������ top ���Ҹ� �˻��ϴ� ����
{
    if (isEmpty())
    {
        printf("\n\nStack is Empty\n\n");
        exit(1);
    }
    else
    {
        return stack[top];
    }
}

void printStack() // ������ ���Ҹ� ����ϴ� ����
{
    printf("\nSTACK [");
    for (int i = 0; i <= top; i++)
    {
        printf("%d", stack[i]);
    }
    printf("]");
}