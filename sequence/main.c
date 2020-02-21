#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int size, int array[]);

// 메인함수
int main(void) 
{
	int temp_array[10] = { 3,-2,-4,-9,0,3,7,13,8,-3 };
	int count = sizeof(temp_array) / sizeof(int);

	int* sum_array; int term;
	int sum = 0;
	
	printf("측정일수 입력 : ");
	scanf("%d", &count);

	if ((count < 0) || (count > 10))
	{
		printf("잘못된 측정일수 입력\n");
		exit(1);
	}

	for (int i = 0; i < count; i++)
	{
		printf("%d\t", temp_array[i]);
	}
	printf("\n");

	printf("기간 입력 : ");
	scanf("%d", &term);

	if (term>count)
	{
		printf("잘못된 기간 입력\n");
		exit(1);
	}

	int array_count = count - term + 1;

	sum_array = (int*)malloc(sizeof(int) * array_count);

	for (int i = 0; i < array_count; i++)
	{
		for (int j = i; j < i+term; j++)
		{
			sum += temp_array[j];
		}

		sum_array[i] = sum;
		sum = 0;
	}

	sort(array_count, sum_array);

	free(sum_array);
}

void sort(int size, int array[])
{
	int count = size;
	int temp;

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
			}
		}
	}
	printf("최대 합 : %d\n", array[count - 1]);
}