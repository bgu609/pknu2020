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
    printf("\n** 순차 스택 연산 **\n");
    printStack();
    push(1);    printStack();       // 1 삽입
    push(2);    printStack();       // 2 삽입
    push(3);    printStack();       // 3 삽입

    item = peek(); printStack();    // 현재 top의 원소 출력
    printf("\t peek => %d", item);

    item = pop();  printStack();    // 삭제
    printf("\t pop  => %d", item);

    item = pop();  printStack();    // 삭제
    printf("\t pop  => %d", item);

    item = pop();  printStack();    // 삭제
    printf("\t pop  => %d", item);
}

int isEmpty() // 비어있는지 여부
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

int isFull() // 스택 포화상태 여부
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

void push(element item) // 스택에 원소를 삽입하는 연산
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

element pop() // 스택에 원소를 삭제하는 연산
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

element peek() // 스택의 top 원소를 검색하는 연산
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

void printStack() // 스택의 원소를 출력하는 연산
{
    printf("\nSTACK [");
    for (int i = 0; i <= top; i++)
    {
        printf("%d", stack[i]);
    }
    printf("]");
}