/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.10
  writer - BGU.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int one_line();
//void buffer();
void fWrRd();

// 메인함수
int main(void)
{
    //int open = one_line();
    //buffer();
    fWrRd();

    system("pause");
    return EXIT_SUCCESS;
}

int one_line(void)
{
    FILE* ifp, * ofp;
    char name[20];
    int kor, eng, math;
    int total;
    double avg;
    int res;

    ifp = fopen("D:\\documents\\aaa.txt", "r");
    if (ifp == NULL)
    {
        printf("입력 파일을 열지 못했습니다.\n");
        return 1;
    }

    ofp = fopen("D:\\documents\\bbb.txt", "w");
    if (ofp == NULL)
    {
        printf("출력 파일을 열지 못했습니다.\n");
        return 1;
    }

    while (1)
    {
        res = fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &math);
        if (res == EOF)
        {
            break;
        }

        total = kor + eng + math;
        avg = total / 3.0;
        fprintf(ofp, "%s%5d%7.1lf\n", name, total, avg);
    }

    /*
    while (1)
    {
        res = fgets(str, sizeof(str), ifp);
        if (res == NULL)
        {
            break;
        }
        str[strlen(str) - 1] = '\0';
        fputs(str, ofp);
        fputs(" ", ofp);
    }
    */
    
    fclose(ifp);
    fclose(ofp);

    return 0;
}

void buffer(void)
{
    FILE* fp;
    int age;
    char name[20];

    fp = fopen("D:\\documents\\ffl.txt", "r");

    fscanf(fp, "%d", &age);

    while (fgetc(fp) != '\n')
    {
        
    }

    fgets(name, sizeof(name), fp);
    printf("나이 : %d, 이름 : %s\n", age, name);
    fclose(fp);
}

void fWrRd(void)
{
    FILE* afp, * bfp;
    int num = 10;
    int res;

    afp = fopen("D:\\documents\\wt.txt", "wt");
    fprintf(afp, "%d", num);

    bfp = fopen("D:\\documents\\wb.txt", "wb");
    fwrite(&num, sizeof(num), 1,bfp);

    fclose(afp);
    fclose(bfp);

    bfp = fopen("D:\\documents\\wb.txt", "rb");
    fread(&res, sizeof(res), 1, bfp);
    printf("%d\n", res);

    fclose(bfp);
}