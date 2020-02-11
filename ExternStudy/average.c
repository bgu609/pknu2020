#define _CRT_SECURE_NO_WARNINGS

extern int count;
extern int total;

double average(void)
{
	return total / (double)count;
}