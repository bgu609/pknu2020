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


// �����Լ�
int main(int argc, char** argv)
{
    if (argc <= 1)
    {
        printf("��ɱ����� �ùٸ��� �ʽ��ϴ�.\n");
        exit(1);
    }

    char* intarg[2];
    int j = 0;

    for (int i = 0; i < argc; i++)
    {
        if (i == 0)
        {
            continue;
        }
        intarg[j] = (char*)malloc(strlen(argv[i]));
        strcpy(intarg[j], argv[i]);
        j++;
    }

    printf("%s\n", intarg[0]);
    printf("%s\n", intarg[1]);

    system("pause");
    return EXIT_SUCCESS;
}