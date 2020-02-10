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
//int std_inout();
//int binary();
int open_plus();

// �����Լ�
int main(void)
{
    int open = open_plus();

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

int binary(void)
{
    FILE* fp;
    int ary[10] = { 13,10,13,13,10,26,13,10,13,10 };
    int i, res;

    fp = fopen("D:\\documents\\a.txt", "wb");
    for (i = 0; i < 10; i++)
    {
        fputc(ary[i], fp);
    }
    fclose(fp);

    fp = fopen("D:\\documents\\a.txt", "rt");
    while (1)
    {
        res = fgetc(fp);
        if (res == EOF)
        {
            break;
        }
        printf("%4d", res);
    }
    fclose(fp);

    return 0;
}

int open_plus(void)
{
    FILE* fp;
    char str[20];

    fp = fopen("D:\\documents\\a.txt", "a+");
    if (fp == NULL)
    {
        printf("������ ������ ���߽��ϴ�.\n");
        return 1;
    }

    while (1)
    {
        printf("���� �̸� : ");
        scanf("%s", str);
        if (strcmp(str, "end") == 0)
        {
            break;
        }
        else if (strcmp(str, "list") == 0)
        {
            fseek(fp, 0, SEEK_SET);
            while (1)
            {
                fgets(str, sizeof(str), fp);
                if (feof(fp))
                {
                    break;
                }
                printf("%s", str);
            }
        }
        else
        {
            fprintf(fp, "%s\n", str);
        }
    }
    fclose(fp);

    return 0;
}