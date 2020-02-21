#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 메인함수
int main(void)
{
	int x = 0; int y = 0;
	int width; int count;
	int num = 1;
	int axis = 1;

	int array[10][10] = { 0, };

	printf("width 입력 : ");
	scanf("%d", &width);

	count = width;

	while (1)
	{
		for (int i = 0; i < width; i++)
		{
			array[x][y] = num;
			y += axis;
			num++;
		}

		x += axis;
		y -= axis;
		width--;

		for (int i = 0; i < width; i++)
		{
			array[x][y] = num;
			x += axis;
			num++;
		}

		x -= axis;
		y -= axis;
		axis = -axis;

		if (width == 0)
		{
			break;
		}
	}

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}
}