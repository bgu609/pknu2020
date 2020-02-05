/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.05
  writer - BGU.
*/

#include <stdio.h>
#include <stdlib.h>

// 메인함수
int main(void) 
{
    char* dessert = "apple";

    printf("오늘 후식은 %s입니다.\n", dessert);
    dessert = "banana";
    printf("내일 후식은 %s입니다.\n", dessert);
    
	system("pause");
	return EXIT_SUCCESS;
}