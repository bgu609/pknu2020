/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------
  first created - 2020.02.05
  writer - BGU.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// �����Լ�
int main(void) 
{
    while (1)
    {
        char str1[80];
        char str2[80];

        printf("�Է�1 : ");
        scanf("%s", str1);
        printf("�Է�2 : ");
        scanf("%s", str2);


        if (str1[0]=='X'|| str2[0] == 'X')
        {
            printf("����\n");
            break;
        }

        printf("������ ���� ������ ���� �̸� : ");
        if (strcmp(str1, str2) < 0)
        {
            printf("%s\n", str1);
        }
        else
        {
            printf("%s\n", str2);
        }

        //Sleep(3000);
        //system("cls");
    }
    

    /*
    char str1[80], str2[80];
    char* resp;

    printf("2���� ���� �̸� �Է� : ");
    scanf("%s%s", str1, str2);
    if (strlen(str1) > strlen(str2))
    {
        resp = str1;
    }
    else
    {
        resp = str2;
    }
    printf("�̸��� �� ������ : %s\n", resp);
    */

    /*
    char str[80] = "straw";

    strcat(str, "berry");
    printf("%s\n", str);
    strncat(str, "piece", 3);
    printf("%s\n", str);
    */

    /*
    char str1[80] = "strawberry";
    char str2[80] = "apple";
    char* ps1 = "banana";
    char* ps2 = str2;

    printf("���� ���ڿ� : %s\n", str1);
    strcpy(str1, str2);
    printf("�ٲ� ���ڿ� : %s\n", str1);

    strcpy(str1, ps1);
    printf("�ٲ� ���ڿ� : %s\n", str1);

    strcpy(str1, ps2);
    printf("�ٲ� ���ڿ� : %s\n", str1);

    strcpy(str1, "banana");
    printf("�ٲ� ���ڿ� : %s\n", str1);

    char str[20] = "mango tree";
    strncpy(str, "apple-pie", 5);
    printf("%s\n", str);
    */



    /*
    char str[80];

    printf("������ ���Ե� ���ڿ� �Է� :");
    gets(str);
    printf("�Է��� ���ڿ��� %s�Դϴ�.", str);
    */

    /*
    char str[80];

    printf("���ڿ� �Է� : ");

    scanf("%s", str);
    printf("ù��° �ܾ� : %s\n", str);
    scanf("%s", str);
    printf("���ۿ� �����ִ� �ι�° �ܾ� : %s\n", str);
    */


    /*
    char* dessert = "apple";

    printf("���� �Ľ��� %s�Դϴ�.\n", dessert);
    dessert = "banana";
    printf("���� �Ľ��� %s�Դϴ�.\n", dessert);
    */

	system("pause");
	return EXIT_SUCCESS;
}