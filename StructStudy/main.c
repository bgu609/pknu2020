/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.07
  writer - BGU.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct profile
{
    int age;
    double height;
};

struct student
{
    struct profile pf;
    int id;
    double grade;
};

struct grade
{
    int id;
    char name[20];
    double grade;
};

struct vision
{
    double left;
    double right;
};

struct vision exchange(struct vision robot);
//void strt_grade();
//void strt_student();

// 메인함수
int main(void)
{
    struct vision robot;

    printf("시력 입력 : ");
    scanf("%lf%lf", &(robot.left), &(robot.right));
    printf("\n처음 시력 : %.1lf %.1lf\n", robot.left, robot.right);
    robot = exchange(robot);
    printf("바뀐 시력 : %.1lf %.1lf\n", robot.left, robot.right);

    //strt_grade();
    //strt_student();
    //strt_profile();

    system("pause");
    return EXIT_SUCCESS;
}

struct vision exchange(struct vision robot)
{
    double temp;

    temp = robot.left;
    robot.left = robot.right;
    robot.right = temp;

    return robot;
}

void strt_grade(void)
{
    struct grade s1 = { 315,"홍길동",2.4 }, s2 = { 316,"이순신",3.7 }, s3 = { 317,"세종대왕",4.4 };

    struct grade max;

    max = s1;
    if (s2.grade > max.grade)
    {
        max = s2;
    }
    if (s3.grade > max.grade)
    {
        max = s3;
    }

    printf("학번 : %d\n", max.id);
    printf("이름 : %s\n", max.name);
    printf("학점 : %.1lf\n", max.grade);
}

void strt_student(void)
{
    struct student yuni;

    yuni.pf.age = 17;
    yuni.pf.height = 164.5;
    yuni.id = 315;
    yuni.grade = 4.3;

    printf("     나이\t: %d\n", yuni.pf.age);
    printf("      키\t: %.1lf\n", yuni.pf.height);
    printf("     학번\t: %d\n", yuni.id);
    printf("     학점\t: %.1lf\n", yuni.grade);
}

/*
void strt_profile(void)
{
    struct profile yuni;

    yuni.name = (char*)malloc(20);
    printf("이름 : ");
    gets(yuni.name);

    yuni.age = 17;
    yuni.height = 164.5;

    yuni.intro = (char*)malloc(80);
    printf("자기소개 : ");
    gets(yuni.intro);

    system("cls");

    printf("     이름\t: %s\n", yuni.name);
    printf("     나이\t: %d\n", yuni.age);
    printf("      키\t: %.1lf\n", yuni.height);
    printf("   자기소개\t: %s\n", yuni.intro);
    free(yuni.name);
    free(yuni.intro);
}
*/