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


typedef struct node { char data; struct node* Left; struct node* Right; } str;

str* node;

str* make_node(char item, str* Left, str* Right);
void preorder(str* node);

int main(void)
{
    str* node07 = make_node('G', NULL, NULL);
    str* node06 = make_node('F', node07, NULL);
    str* node05 = make_node('E', node07, NULL);
    str* node04 = make_node('D', node07, NULL);
    str* node03 = make_node('C', node05, NULL);
    str* node02 = make_node('B', node04, NULL);
    str* node01 = make_node('A', node02, NULL);

    preorder(node01);
}

str* make_node(char item, str* Left, str* Right)
{
    node = (str*)malloc(sizeof(str));
    node->data = item;
    node->Left = Left;
    node->Right = Right;

    return node;
}

void preorder(str* root)
{
    if (root)
    {
        printf("%c ", root->data);
        preorder(root->Left);
        preorder(root->Right);
    }
}