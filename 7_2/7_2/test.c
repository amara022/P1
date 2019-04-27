#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int Fact(int n, int k)
{
	if (n == 1 || k == 0)
		return 1;
	else
		return Fact(n, k - 1)*n;

}
int main()
{
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);
	int ret = Fact(n, k);
	printf("%d", ret);
	system("pause");
	return 0;
}