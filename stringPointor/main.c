/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.01
  writer - Hugo MG Sung.
*/

#include <stdio.h>
#include <stdlib.h>

void animal();
void one_to_two();

// 메인함수
int main(void) 
{
    one_to_two();
	
	system("pause");
	return EXIT_SUCCESS;
}

void animal(void)
{
    char* animal[5];
    int i;

    animal[0] = "dog";
    animal[1] = "cat";
    animal[2] = "elephant";
    animal[3] = "tiger";
    animal[4] = "lion";

    for (i = 0; i < 5; i++)
    {
        printf("%s\n", animal[i]);
    }
}

void one_to_two(void)
{
    int ary1[4] = { 1,2,3,4 };
    int ary2[4] = { 11,12,13,14 };
    int ary3[4] = { 21,22,23,24 };
    int *pary[3] = { ary1,ary2,ary3 };
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", pary[i][j]);
        }
        printf("\n");
    }
}