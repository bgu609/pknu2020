/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------
  first created - 2020.02.07
  writer - BGU.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_mem();

// �����Լ�
int main(void)
{
    string_mem();


    system("pause");
    return EXIT_SUCCESS;
}

void string_mem(void)
{
    char temp[80];
    char* str[21] = { 0 };
    int i = 0;

    while (i < 20)
    {
        printf("���ڿ��� �Է��ϼ��� : ");
        gets(temp);

        if (strcmp(temp, "end") == 0)
        {
            break;
        }

        str[i] = (char*)malloc(strlen(temp) + 1);
        strcpy(str[i], temp);
        i++;
    }

    i = 0;
    while (str[i] != NULL)
    {
        printf("%s\n", str[i]);
        i++;
    }

    for (i = 0; str[i]!=NULL; i++)
    {
        free(str[i]);
    }
}