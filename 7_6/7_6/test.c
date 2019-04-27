#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int Fab(int n)
{
	int sum = 1;
	int i = 1;
	if (n == 0 || n == 1)
		return 1;
	else
	{
		for (i = 2; i <= n; i++)
		{
			sum *= i;
		}
		return sum;
	}
}
int Fab2(int n)
{
	if (n == 0)
		return 1;
	else
		return Fab2(n - 1)*n;

}
int main()
{
	int n = 0;
	int ret1 = Fab(n);
	int ret2 = Fab2(n);
	scanf("%d", &n);
	ret1 = Fab(n);
	ret2 = Fab(n);
	printf("%d\n", ret1);
	printf("%d\n", ret2);
	system("pause");
	return 0;
}