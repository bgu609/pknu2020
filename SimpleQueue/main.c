/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------

  writer - GWB.
*/

#define _CRT_SECURE_NO_WARNINGS
#define QUEUE_SIZE 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct { char queue[QUEUE_SIZE]; int front, rear; } QueueType;

//2. 공백 순차 큐를 생성하는 연산
QueueType * createQueue() {
    QueueType* Q;
    Q = (QueueType*)malloc(sizeof(QueueType));
    Q->front = -1;  // front 초깃값 설정
    Q->rear = -1;   // rear 초깃값 설정
    return Q;
}

//3. 순차 큐가 공백 상태인지 검사하는 연산
int isEmpty(QueueType* Q);

//4. 순차 큐가 포화 상태인지 검사하는 연산
int isFull(QueueType* Q);

//5. 순차 큐의 rear에 원소를 삽입하는 연산
void enQueue(QueueType* Q, char item);

//6. 순차 큐의 front에서 원소를 삭제하는 연산
char deQueue(QueueType* Q);

//7. 순차 큐의 가장 앞에 있는 원소를 검색하는 연산
char peek(QueueType* Q);

//8. 순차 큐의 원소를 출력하는 연산
void printQ(QueueType* Q);

int main(void)
{
    QueueType* Q1 = createQueue();  // 큐 생성
    char data;
    printf("\n ***** 순차 큐 연산 ***** \n");
    printf("\n 삽입 A>>");  enQueue(Q1, 'A'); printQ(Q1);
    printf("\n 삽입 B>>");  enQueue(Q1, 'B'); printQ(Q1);
    printf("\n 삽입 C>>");  enQueue(Q1, 'C'); printQ(Q1);
    data = peek(Q1);    printf(" peek item : %c \n", data);
    printf("\n 삭제  >>");  data = deQueue(Q1); printQ(Q1);
    printf("\t삭제 데이터: %c", data);
    printf("\n 삭제  >>");  data = deQueue(Q1); printQ(Q1);
    printf("\t삭제 데이터: %c", data);
    printf("\n 삭제  >>");  data = deQueue(Q1); printQ(Q1);
    printf("\t\t삭제 데이터: %c", data);

    printf("\n 삽입 D>>");  enQueue(Q1, 'D'); printQ(Q1);
    printf("\n 삽입 E>>");  enQueue(Q1, 'E'); printQ(Q1);

    free(Q1);
}

//3. 순차 큐가 공백 상태인지 검사하는 연산
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

//4. 순차 큐가 포화 상태인지 검사하는 연산
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

//5. 순차 큐의 rear에 원소를 삽입하는 연산
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

//6. 순차 큐의 front에서 원소를 삭제하는 연산
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

//7. 순차 큐의 가장 앞에 있는 원소를 검색하는 연산
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

//8. 순차 큐의 원소를 출력하는 연산
void printQ(QueueType* Q)
{
    printf("[ ");
    for (int i = Q->front+1; i <= Q->rear; i++)
    {
        printf("%c ", Q->queue[i]);
    }
    printf("]");
}