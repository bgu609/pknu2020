/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  
  writer - GWB.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>




int main(void)
{
    for (int num = 2; num < 101; num++)
    {
        int count = 0;

        for (int div = 2; div <= num; div++)
        {
            if (num % div == 0)
            {
                count++;
            }
        }

        if (count == 1)
        {
            printf("%d ", num);
        }
    }
}



/*
long long Fibonacci(int input, int obj);

// 메인함수
int main(void)
{
    int obj = 1234567;

    long long input;
    long long output;
    scanf("%lld", &input);

    output = Fibonacci(input, obj);
    output = obj % output;

    printf("\n나머지 : %lld\n", output);

    return output;
}


long long Fibonacci(int input, int obj)
{
    long long F_p = 0;
    long long F_f = 1;
    long long F_s = 0;

    for (int i = 1; i < input; i++)
    {
        F_s = F_f + F_p;

        printf("%lld ", F_s);

        F_p = F_f;
        F_f = F_s;

        if (F_s > obj)
        {
            return F_s;
        }
    }

    return F_s;
}
*/

void exam(void)
{
    /*
    //////////////////////////////
    int a = 10;
    int b = 20;
    int temp;

    printf("두 정수 입력 : ");

    scanf("%d%d", &a, &b);

    printf("%d << >> %d\n", a, b);

    temp = a;
    a = b;
    b = temp;

    printf(": %d , %d\n", a, b);
    //////////////////////////////

    //////////////////////////////



    double w = 2, h = 3;
    double area;

    printf("가로 세로 입력 : ");
    scanf("%lf%lf", &w, &h);

    area = w * h / 2;

    printf("넓이 : %.2lf\n", w, h, area);
    //////////////////////////////

    //////////////////////////////



    int blank = 7;
    int high = blank * 2 + 1;
    int star = 1;
    int swch = 1;

    printf("홀수 입력 : ");
    scanf("%d", &blank);

    for (int i = 0; i < high; i++)
    {
        for (int j = 0; j < blank; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < star; k++)
        {
            printf("*");
        }

        if (blank == 0)
        {
            swch = 0;
        }

        if (swch == 0)
        {
            blank += 1;
            star -= 2;
        }
        else
        {
            blank -= 1;
            star += 2;
        }




        printf("\n");
    }


    //////////////////////////////

    int start = 1; int end = 100;

    int sum = (start + end) * (end - start + 1) / 2;

    printf("sum = %d\n", sum);


    ////////////

    char array[20];
    int num = 0;
    int summ = 0;

    printf("입력 : ");
    scanf("%d", &num);

    sprintf(array, "%d", num);

    for (int i = 0; i < strlen(array); i++)
    {
        summ += array[i] - '0';
    }

    printf(" = %d\n", summ);

    return summ;

    /////////////////////////////

    long double input = 1;
    long double sq = 1;

    printf("입력 : ");
    scanf("%Lf", &input);

    sq = sqrt(input);

    if ((input / sq) == sq)
    {
        printf("%.0Lf은 양의 정수 %.0Lf의 제곱이므로, ", input,sq);
        printf("(%.0Lf+1)를 제곱한 (%.0Lf)를 리턴합니다.\n", sq, (sq+1)*(sq+1));

        return (sq + 1) * (sq + 1);
    }
    else
    {
        printf("%.0Lf은 양의 정수 제곱이 아니므로, ", input);
        printf("-1을 리턴합니다.\n");

        return -1;
    }



    char num_array[12];
    int input;

    printf("입력 : ");
    scanf("%d", &input);
    sprintf(num_array, "%d", input);

    printf("[");
    for (int i = (strlen(num_array) - 1); i > 0; i--)
    {
        printf("%c, ", num_array[i]);
    }
    printf("%c]", num_array[0]);

    */

    /* 달팽이 나선
        int input = 0;
        int num = 1;
        int axis = 1;

        printf("입력 : ");
        scanf("%d", &input);

        int matrix[20][20];
        int x=0, y=-1;
        int count = input;

        while (1)
        {

            for (int i = 0; i < input; i++)
            {
                y += axis;
                matrix[x][y] = num;
                num += 1;
            }

            input--;

            if (input < 0)
            {
                break;
            }

            for (int i = 0; i < input; i++)
            {
                x += axis;
                matrix[x][y] = num;
                num += 1;
            }
            axis = -axis;
        }


        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count; j++)
            {
                printf("%d\t", matrix[i][j]);
            }
            printf("\n");
        }
     */
    
    /*
    int input = 0;
    int num = 1;
    int matrix[20][20];
    int x = 0, y = 0;
    int axis = 1;

    printf("입력 : ");
    scanf("%d", &input);

    int count = input;

    while (1)
    {
        for (int i = 0; i < input; i++)
        {
            matrix[x][y] = num;
            y += axis;
            num++;
        }

        y -= axis;
        x += axis;

        input--;

        for (int i = 0; i < input; i++)
        {
            matrix[x][y] = num;
            x += axis;
            num++;
        }

        y -= axis;
        x -= axis;

        axis = -axis;

        if (input == 0)
        {
            break;
        }
    }

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    */
}