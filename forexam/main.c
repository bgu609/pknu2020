/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.13
  writer - BGW.
*/

#include <stdio.h>
#include <stdlib.h>

int multi_03(int limit, int num);

// 메인함수
int main(void) 
{
    int num = 3;
    int limit = 300;
    int result = multi_03(limit, num);

    printf("unit num : %d\n", num);
    printf("limit = %d\n", limit);
    printf("%d\n", result);

	system("pause");
	return EXIT_SUCCESS;
}

int multi_03(int limit, int num)
{
    int i = 1;
    int sum = 0;

    for (i; i < limit; i++)
    {
        int mul = num * i;
        sum += mul;
        // printf("+ %d : sum(%d)\n", mul,sum);

        if (mul == limit)
        {
            break;
        }
    }

    return sum;
}