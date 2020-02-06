/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.06
  writer - BGU.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void score_one();

// 메인함수
int main(void) 
{
    score_one();

    



	system("pause");
	return EXIT_SUCCESS;
}

void score_one(void)
{
    int score[2][3][4] = { {{1,2,3,4},{5,6,7,8},{9,10,11,12}}, {{13,14,15,16},{17,18,19,20},{21,22,23,24}} };

    int i, j, k;

    for (i = 0; i < 2; i++)
    {
        printf("%d반 점수...\n", i + 1);

        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 4; k++)
            {
                printf("%5d", score[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}