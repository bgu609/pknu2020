/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------
  first created - 2020.02.10
  writer - BGU.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int file_open();
//int file_write();
int std_inout();

// �����Լ�
int main(void)
{
    int open= std_inout();

    system("pause");
    return EXIT_SUCCESS;
}

int file_open(void)
{
    FILE* fp;
    int ch;

    fp = fopen("D:\\documents\\target1.txt", "r");

    if (fp == NULL)
    {
        printf("������ ������ �ʾҽ��ϴ�.\n\n");
        return 1;
    }

    printf("������ ���Ƚ��ϴ�.\n\n");
    
    while (1)
    {
        ch = fgetc(fp);
        if (ch == EOF)
        {
            printf("\n\n");
            break;
        }
        putchar(ch);
    }
    fclose(fp);

    return 0;
}

int file_write(void)
{
    FILE* fp;
    char str[] = "banana";
    int i;

    fp = fopen("D:\\documents\\banana.txt", "w");

    if (fp == NULL)
    {
        printf("������ ������ ���߽��ϴ�.\n\n");
        return 1;
    }

    i = 0;

    while (str[i]!='\0')
    {
        fputc(str[i], fp);
        i++;
    }
    fputc('\n', fp);
    fclose(fp);

    return 0;
}

int std_inout(void)
{
    int ch;

    while (1)
    {
        //ch = getchar();
        ch = fgetc(stdin);

        if (ch == EOF)
        {
            break;
        }

        //putchar(ch);
        fputc(ch, stdout);
    }
    return 0;
}