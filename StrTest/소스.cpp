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

	printf("딸기 : %s\n", fruit);
	printf("딸기잼 : %s %s\n", fruit, "jam");

	strcpy(fruit, "banana");
	printf("바나나 : %s\n", fruit);
	*/

	/*
	int age;
	double height;

	printf("나이와 키를 입력하세요 : ");
	scanf("%d%lf", &age, &height);
	printf("나이는 %d살, 키는 %.1lfcm입니다.\n", age, height);
	*/

	char grade;
	char name[20];

	printf("학점과 이름을 입력 : ");
	scanf("%c""%s", &grade, name);
	printf("%s의 학점은 %c입니다.\n", name, grade);

	system("pause");
	
	return 0;
}