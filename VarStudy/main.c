/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------
  first created - 2020.02.05
  writer - BGU.
*/

#include <stdio.h>
#include <stdlib.h>

/*
void auto_func(void);
void static_func(void);
*/
// void add_ten(int* pa);
int* sum(int a, int b);

// �����Լ�
int main(void) 
{
    int* resp;

    resp = sum(10, 20);
    printf("�� ������ �� : %d\n", *resp);


    /*

    int a = 10;

    add_ten(&a);
    printf("a : %d\n", a);

    */

    /*
    register int i;
    int sum = 0;

    for (i = 1; i <= 10000; i++)
    {
        sum += i;
    }

    printf("%d\n", sum);
    */

    /*
    int i;

    printf("�Ϲ� ���������� ����� �Լ�\n");
    for (i = 0; i < 3; i++)
    {
        auto_func();
    }

    printf("���� ���������� ����� �Լ�\n");
    for (i = 0; i < 3; i++)
    {
        static_func();
    }
    */

    /*
    auto int a = 10, b=20;

    assign(a,b);
    printf("main�Լ� a: %d, b: %d\n", a,b);
    */

	system("pause");
	return EXIT_SUCCESS;
}

void auto_func(void)
{
    int a = 0;
    a++;
    printf("%d\n", a);
}

void static_func(void)
{
    static int a;
    a++;
    printf("%d\n", a);
}

void add_ten(int* pa)
{
    *pa = *pa + 10;
}

int* sum(int a, int b)
{
    static int res;

    res = a + b;

    return &res;
}

/*
int assign(int a,int b)
{
    int y=a;
    int x=b;

    a = 10;
    printf("assign�Լ� a: %d, b: %d\n", x,y);

    return a;
}
*/