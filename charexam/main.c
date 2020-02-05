/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.05
  writer - BGU.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// 메인함수
int main(void) 
{
    while (1)
    {
        char str1[80];
        char str2[80];

        printf("입력1 : ");
        scanf("%s", str1);
        printf("입력2 : ");
        scanf("%s", str2);


        if (str1[0]=='X'|| str2[0] == 'X')
        {
            printf("종료\n");
            break;
        }

        printf("사전에 먼저 나오는 과일 이름 : ");
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

    printf("2개의 과일 이름 입력 : ");
    scanf("%s%s", str1, str2);
    if (strlen(str1) > strlen(str2))
    {
        resp = str1;
    }
    else
    {
        resp = str2;
    }
    printf("이름이 긴 과일은 : %s\n", resp);
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

    printf("최초 문자열 : %s\n", str1);
    strcpy(str1, str2);
    printf("바뀐 문자열 : %s\n", str1);

    strcpy(str1, ps1);
    printf("바뀐 문자열 : %s\n", str1);

    strcpy(str1, ps2);
    printf("바뀐 문자열 : %s\n", str1);

    strcpy(str1, "banana");
    printf("바뀐 문자열 : %s\n", str1);

    char str[20] = "mango tree";
    strncpy(str, "apple-pie", 5);
    printf("%s\n", str);
    */



    /*
    char str[80];

    printf("공백이 포함된 문자열 입력 :");
    gets(str);
    printf("입력한 문자열은 %s입니다.", str);
    */

    /*
    char str[80];

    printf("문자열 입력 : ");

    scanf("%s", str);
    printf("첫번째 단어 : %s\n", str);
    scanf("%s", str);
    printf("버퍼에 남아있는 두번째 단어 : %s\n", str);
    */


    /*
    char* dessert = "apple";

    printf("오늘 후식은 %s입니다.\n", dessert);
    dessert = "banana";
    printf("내일 후식은 %s입니다.\n", dessert);
    */

	system("pause");
	return EXIT_SUCCESS;
}