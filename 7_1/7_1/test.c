#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int Fib1(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	int i = 0;

	for (i = 2; i <= n; i++)
	{
		c = b;
		b = a + b;
		a = c;
	}
	return c;
}
int Fib2(int n)
{
	if (n <= 2)
		return 1;
	else
		return Fib2(n - 1) + Fib2(n - 2);
}
int main()
{
 	int n = 1;
	scanf("%d", &n);
	int c=Fib1(n);
	int ret = Fib2(n);
	printf("%d\n", c);
	printf("%d\n", ret);
	system("pause");
	return 0;
	
}