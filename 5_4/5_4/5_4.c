#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char a;
	while (1)
	{
		scanf("%c", &a);
		if (a <= 'z' && a >= 'a')

		{
			a = a - 32;
			printf("%c\n", a);
		}
		else if (a <= 'Z' && a >= 'A')
		{
			a = a + 32;
			printf("%c\n", a);
		}
		else
			printf("\n");
	}
	system("pause");
	return 0;
}