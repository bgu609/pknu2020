#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	/*
	char fruit[20] = "strawberry";

	printf("���� : %s\n", fruit);
	printf("������ : %s %s\n", fruit, "jam");

	strcpy(fruit, "banana");
	printf("�ٳ��� : %s\n", fruit);
	*/

	/*
	int age;
	double height;

	printf("���̿� Ű�� �Է��ϼ��� : ");
	scanf("%d%lf", &age, &height);
	printf("���̴� %d��, Ű�� %.1lfcm�Դϴ�.\n", age, height);
	*/

	char grade;
	char name[20];

	printf("������ �̸��� �Է� : ");
	scanf("%c""%s", &grade, name);
	printf("%s�� ������ %c�Դϴ�.\n", name, grade);

	system("pause");
	
	return 0;
}