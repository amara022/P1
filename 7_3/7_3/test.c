#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int Digitsum(int n)
{
	if (n < 10)
		return n;
	else
		return Digitsum(n / 10) + Digitsum(n%10);

}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = Digitsum(n);
	printf("%d\n", ret);
	system("pause");
	return 0;
}