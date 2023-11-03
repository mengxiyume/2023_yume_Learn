#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void Test_01()
{
	printf("TEST_01\n");
	int a = 0, b = 0;
	for (a = 1, b = 1; a <= 100; a++)
	{
		if (b >= 20) break;
		if (b % 3 == 1)
		{
			b = b + 3;
			continue;
		}
		b = b - 5;
	}
	printf("%d\n", a);
}

int main()
{
	Test_01();
	return 0;
}