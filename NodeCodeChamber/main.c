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

struct Node { int num; double double_data; struct Node* next; };


// �����Լ�
int main(void)
{
    struct Node node = { 1, 1.0, 0 };
    struct Node* head=&node;

    printf("[%d, %lf, %p]\n", node.num, node.double_data, node.next);
    printf("head : %d\n", head->num);

    system("pause");
    return EXIT_SUCCESS;
}

void insertNode()
{

}

void deleteNode()
{

}

void printNode()
{

}