#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void my_Printf(int n)
{
	if ( n >= 10)
	{
		printf("%d", n / 10);
	}
		printf("%d\n",n%10);
}
int main()
{
	int n = 0;

	scanf("%d", &n);
	my_Printf(n);
	system("pause");
	return 0;
}