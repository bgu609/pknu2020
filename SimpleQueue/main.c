/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------

  writer - GWB.
*/

#define _CRT_SECURE_NO_WARNINGS
#define QUEUE_SIZE 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct { char queue[QUEUE_SIZE]; int front, rear; } QueueType;

//2. ���� ���� ť�� �����ϴ� ����
QueueType * createQueue() {
    QueueType* Q;
    Q = (QueueType*)malloc(sizeof(QueueType));
    Q->front = -1;  // front �ʱ갪 ����
    Q->rear = -1;   // rear �ʱ갪 ����
    return Q;
}

//3. ���� ť�� ���� �������� �˻��ϴ� ����
int isEmpty(QueueType* Q);

//4. ���� ť�� ��ȭ �������� �˻��ϴ� ����
int isFull(QueueType* Q);

//5. ���� ť�� rear�� ���Ҹ� �����ϴ� ����
void enQueue(QueueType* Q, char item);

//6. ���� ť�� front���� ���Ҹ� �����ϴ� ����
char deQueue(QueueType* Q);

//7. ���� ť�� ���� �տ� �ִ� ���Ҹ� �˻��ϴ� ����
char peek(QueueType* Q);

//8. ���� ť�� ���Ҹ� ����ϴ� ����
void printQ(QueueType* Q);

int main(void)
{
    QueueType* Q1 = createQueue();  // ť ����
    char data;
    printf("\n ***** ���� ť ���� ***** \n");
    printf("\n ���� A>>");  enQueue(Q1, 'A'); printQ(Q1);
    printf("\n ���� B>>");  enQueue(Q1, 'B'); printQ(Q1);
    printf("\n ���� C>>");  enQueue(Q1, 'C'); printQ(Q1);
    data = peek(Q1);    printf(" peek item : %c \n", data);
    printf("\n ����  >>");  data = deQueue(Q1); printQ(Q1);
    printf("\t���� ������: %c", data);
    printf("\n ����  >>");  data = deQueue(Q1); printQ(Q1);
    printf("\t���� ������: %c", data);
    printf("\n ����  >>");  data = deQueue(Q1); printQ(Q1);
    printf("\t\t���� ������: %c", data);

    printf("\n ���� D>>");  enQueue(Q1, 'D'); printQ(Q1);
    printf("\n ���� E>>");  enQueue(Q1, 'E'); printQ(Q1);

    free(Q1);
}

//3. ���� ť�� ���� �������� �˻��ϴ� ����
int isEmpty(QueueType* Q)
{
    if (Q->front == Q->rear)
    {
        printf("Queue is empty : ");
        return 1;
    }
    else
    {
        return 0;
    }
}

//4. ���� ť�� ��ȭ �������� �˻��ϴ� ����
int isFull(QueueType* Q)
{
    if (Q->rear == QUEUE_SIZE-1)
    {
        printf("Queue is full : ");
        return 1;
    }
    else
    {
        return 0;
    }
}

//5. ���� ť�� rear�� ���Ҹ� �����ϴ� ����
void enQueue(QueueType* Q, char item)
{
    if (isFull(Q))
    {
        return;
    }
    else
    {
        Q->rear++;
        Q->queue[Q->rear] = item;
    }
}

//6. ���� ť�� front���� ���Ҹ� �����ϴ� ����
char deQueue(QueueType* Q)
{
    if (isEmpty(Q))
    {
        return;
    }
    else
    {
        Q->front++;
        return Q->queue[Q->front];
    }
}

//7. ���� ť�� ���� �տ� �ִ� ���Ҹ� �˻��ϴ� ����
char peek(QueueType* Q)
{
    if (isEmpty(Q))
    {
        exit(1);
    }
    else
    {
        return Q->queue[Q->front+1];
    }
}

//8. ���� ť�� ���Ҹ� ����ϴ� ����
void printQ(QueueType* Q)
{
    printf("[ ");
    for (int i = Q->front+1; i <= Q->rear; i++)
    {
        printf("%c ", Q->queue[i]);
    }
    printf("]");
}