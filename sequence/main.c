#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int size, int array[]);

// �����Լ�
int main(void) 
{
	int temp_array[10] = { 3,-2,-4,-9,0,3,7,13,8,-3 };
	int count = sizeof(temp_array) / sizeof(int);

	int* sum_array; int term;
	int sum = 0;
	
	printf("�����ϼ� �Է� : ");
	scanf("%d", &count);

	if ((count < 0) || (count > 10))
	{
		printf("�߸��� �����ϼ� �Է�\n");
		exit(1);
	}

	for (int i = 0; i < count; i++)
	{
		printf("%d\t", temp_array[i]);
	}
	printf("\n");

	printf("�Ⱓ �Է� : ");
	scanf("%d", &term);

	if (term>count)
	{
		printf("�߸��� �Ⱓ �Է�\n");
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
	printf("�ִ� �� : %d\n", array[count - 1]);
}