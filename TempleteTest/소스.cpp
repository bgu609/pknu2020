#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Be happy\n");
	printf("12345678901234567890\n");
	printf("My\tfriend\n"); //		My		friend
	printf("Goot\bd\tchance\n"); //	Good	chance
	printf("Cow\rW\a\n"); //		Wow
	
	system("pause");
	
	return 0;
}