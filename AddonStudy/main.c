/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------
  first created - 2020.02.10
  writer - BGU.
*/

#define _CRT_SECURE_NO_WARNINGS

#define PI 3.14159
#define LIMIT 10.0
#define MSG "Passed!"
#define ERR_PRN printf("��� ������ ������ϴ�!\n")

#include <stdio.h>
#include <stdlib.h>
#include "student.h"


// �����Լ�
int main(void)
{
    Student a = { 315,"ȫ�浿" };

    printf("�й� : %d, �̸� : %s\n", a.num, a.name);

    double radius, area;

    while (1)
    {
        printf("�������� �Է��ϼ��� (10 ����) : ");
        scanf("%lf", &radius);
        

        if (radius > LIMIT)
        {
            ERR_PRN;
            return 0;
        }
        else
        {
            area = PI * radius * radius;
            printf("���� ���� : %.2lf (%s)\n", area, MSG);
        }
    }
    
    system("pause");
    return EXIT_SUCCESS;
}