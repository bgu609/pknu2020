/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.10
  writer - BGU.
*/

#define _CRT_SECURE_NO_WARNINGS

#define PI 3.14159
#define LIMIT 10.0
#define MSG "Passed!"
#define ERR_PRN printf("허용 범위를 벗어났습니다!\n")

#include <stdio.h>
#include <stdlib.h>
#include "student.h"


// 메인함수
int main(void)
{
    Student a = { 315,"홍길동" };

    printf("학번 : %d, 이름 : %s\n", a.num, a.name);

    double radius, area;

    while (1)
    {
        printf("반지름을 입력하세요 (10 이하) : ");
        scanf("%lf", &radius);
        

        if (radius > LIMIT)
        {
            ERR_PRN;
            return 0;
        }
        else
        {
            area = PI * radius * radius;
            printf("원의 면적 : %.2lf (%s)\n", area, MSG);
        }
    }
    
    system("pause");
    return EXIT_SUCCESS;
}