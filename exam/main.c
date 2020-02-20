/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------

  writer - GWB.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct str_unit { int item; struct str_unit* link; };
typedef struct str_unit str;


str* head;
str* tail;
str* stack;


int isEmpty();
int isFull();
void push(int item);
int pop();
int peek();
void printStack();
void rev_printStack();

int main(void)
{
    head = NULL;
    tail = NULL;
    
    push(1); push(2); push(3); push(4);

    printStack();
    rev_printStack();
}

int isEmpty() // ����ִ��� ����
{
    if (tail == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull() // ���� ��ȭ���� ����
{
    return 0;
}

void push(int item) // ���ÿ� ���Ҹ� �����ϴ� ����
{
    stack = (str*)malloc(sizeof(str));

    stack->item = item;
    stack->link = NULL;

    if (head == NULL)
    {
        head = stack;
        tail = stack;
    }
    else
    {
        tail->link = stack;
        tail = stack;
    }
}

int pop() // ���ÿ� ���Ҹ� �����ϴ� ����
{
    if (isEmpty())
    {
        printf("\nstack is empty\n");
        exit(1);
    }

    str* read;
    str* dead;
    read = head;
    dead = tail;
    int data = dead->item;

    if (read == dead)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        while (read->link != dead)
        {
            read = read->link;
        }

        read->link = NULL;
        tail = read;
    }

    free(dead);

    return data;
}

int peek() // ������ top ���Ҹ� �˻��ϴ� ����
{
    if (isEmpty())
    {
        printf("\nstack is empty\n");
        exit(1);
    }

    return tail->item;
}

void printStack() // ������ ���Ҹ� ����ϴ� ����
{
    str* read;
    read = head;

    printf("\nSTACK [ ");
    while (read != NULL)
    {
        if (isEmpty())
        {
            exit(1);
        }

        printf("%d ", read->item);
        read = read->link;
    }
    printf("]\n");
}

void rev_printStack() // ������ ���Ҹ� reverse ����ϴ� ����
{
    str* read;
    str* stop;

    printf("\nSTACK [ ");
    read = head;
    stop = tail;

    if (isEmpty()==0)
    {
        printf("%d ", stop->item);
    }

    while (stop != head)
    {
        while (read->link != stop)
        {
            if (isEmpty())
            {
                exit(1);
            }

            read = read->link;
        }
        printf("%d ", read->item);
        stop = read;
        read = head;
    }
    
    printf("]\n");
}

/*save

*/


/*
long long Fibonacci(int input, int obj);

// �����Լ�
int main(void)
{
    int obj = 1234567;

    long long input;
    long long output;
    scanf("%lld", &input);

    output = Fibonacci(input, obj);
    output = obj % output;

    printf("\n������ : %lld\n", output);

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

    printf("�� ���� �Է� : ");

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

    printf("���� ���� �Է� : ");
    scanf("%lf%lf", &w, &h);

    area = w * h / 2;

    printf("���� : %.2lf\n", w, h, area);
    //////////////////////////////

    //////////////////////////////



    int blank = 7;
    int high = blank * 2 + 1;
    int star = 1;
    int swch = 1;

    printf("Ȧ�� �Է� : ");
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

    printf("�Է� : ");
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

    printf("�Է� : ");
    scanf("%Lf", &input);

    sq = sqrt(input);

    if ((input / sq) == sq)
    {
        printf("%.0Lf�� ���� ���� %.0Lf�� �����̹Ƿ�, ", input,sq);
        printf("(%.0Lf+1)�� ������ (%.0Lf)�� �����մϴ�.\n", sq, (sq+1)*(sq+1));

        return (sq + 1) * (sq + 1);
    }
    else
    {
        printf("%.0Lf�� ���� ���� ������ �ƴϹǷ�, ", input);
        printf("-1�� �����մϴ�.\n");

        return -1;
    }



    char num_array[12];
    int input;

    printf("�Է� : ");
    scanf("%d", &input);
    sprintf(num_array, "%d", input);

    printf("[");
    for (int i = (strlen(num_array) - 1); i > 0; i--)
    {
        printf("%c, ", num_array[i]);
    }
    printf("%c]", num_array[0]);

    */

    /* ������ ����
        int input = 0;
        int num = 1;
        int axis = 1;

        printf("�Է� : ");
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

    printf("�Է� : ");
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
    
    /*
    for (int num = 2; num < 101; num++)
    {
        int count = 0;

        for (int div = 2; div <= num; div++)
        {
            if (num % div == 0)
            {
                count++;
            }

            if (count > 1)
            {
                break;
            }
        }

        if (count == 1)
        {
            printf("%d ", num);
        }
    }
    */
    
    /*
    int input = 0;
    int num = 0;
    int matrix[10][10] = { 0, };
    int x = 1, y = 0;
    int temp_x, temp_y;

    printf("�Է� : ");
    scanf("%d", &input);

    while (1)
    {
        temp_x = x;
        temp_y = y;

        x--;
        y++;
        num++;

        if (x < 0)
        {
            x = input - 1;
        }

        if (y > input -1 )
        {
            y = 0;
        }

        if (matrix[x][y] != 0)
        {
            x = temp_x;
            y = temp_y;
            x++;
        }

        matrix[x][y] = num;

        if (num == input*input)
        {
            break;
        }
    }

    for (int i = 0; i < input; i++)
    {
        for (int j = 0; j < input; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    */

    /*
    int array[] = { 69,10,30,2,16,8,31,22 };
    int count = sizeof(array) / sizeof(int);
    

    printf("%d\n", count);

    int read = count;
    int start = 0;
    int min;

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                min = array[j + 1];
                array[j + 1] = array[j];
                array[j] = min;
            }
        }

        printf("%d�ܰ� : ", i + 1);
        for (int k = 0; k < read; k++)
        {
            printf("%d ", array[k]);
        }
        printf("\n");

        count--;
    }
    */

    /*
    int array[] = { 69,10,30,2,16,8,31,22 };
    int count = sizeof(array) / sizeof(int);


    printf("%d\n", count);

    int read = count;
    int start = 0;
    int min;
    int min_num;

    for (int i = start; i < count; i++)
    {
        min_num = start;

        for (int j = start; j < count - 1; j++)
        {
            if (array[min_num] > array[j + 1])
            {
                min = array[j + 1];
                min_num = j + 1;
            }
        }

        if (min_num == i)
        {
            break;
        }
        else
        {
            array[min_num] = array[i];
            array[i] = min;
        }

        printf("%d�ܰ� : ", i + 1);
        for (int k = 0; k < read; k++)
        {
            printf("%d ", array[k]);
        }
        printf("\n");

        start++;
    }
    */

    /*
    int array[] = { 69,10,30,2,16,8,31,22 };
    int count = sizeof(array) / sizeof(int);

    int read = count;
    int start = 0;
    int min;

    printf("������ ���� : ");
    for (int k = 0; k < read; k++)
    {
        printf("%d ", array[k]);
    }
    printf("\n");

    for (int i = 0; i < count; i++)
    {
        printf("%d�ܰ� : ", i + 1);
        printf("\n");
        for (int j = 0; j < count - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                min = array[j + 1];
                array[j + 1] = array[j];
                array[j] = min;
            }
            for (int k = 0; k < read; k++)
            {
                printf("%d ", array[k]);
            }
            printf("\n");
        }

        count--;
    }
    */

    /* (rank)
    int count;
    printf("�Է� �ο� : ");
    scanf("%d", &count);

    int* array = malloc(sizeof(int) * count);

    printf("���� �Է� :\n");
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &array[i]);
    }

    int start = 0;
    int min;
    int read = count;
    
    printf("\n");
    printf("\n");
    
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                min = array[j + 1];
                array[j + 1] = array[j];
                array[j] = min;
            }
        }
        count--;
    }

    int rank = 1;

    printf("��� :\n");
    for (int i = read - 1; i >= 0; i--)
    {
        if (array[i] == array[i + 1])
        {
            printf("%d (%d)\n", array[i], rank - 1);
        }
        else
        {
            printf("%d (%d)\n", array[i], rank);
        }
        rank++;
    }
    */

    /*
    char string[20];
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int str;

    printf("�Է� : ");
    scanf("%s", &string);

    for (int i=0; i < 20; i++)
    {
        if (string[i] == NULL)
        {
            break;
        }

        str = string[i];

        if ((str >= 48) && (str <= 57))
        {
            a++;
        }
        else if((str >= 65) && (str <= 90))
        {
            b++;
        }
        else if ((str >= 97) && (str <= 122))
        {
            c++;
        }
        else
        {
            d++;
        }
    }
    printf("\n");
    printf("�빮�� : %d\n", b);
    printf("�ҹ��� : %d\n", c);
    printf("���� : %d\n", a);
    printf("Ư������ : %d\n", d);
    */
}