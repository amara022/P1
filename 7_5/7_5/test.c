#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int my_strlen(char* str)
{
	if (*str == '\0')
		return 0;
	else
		return my_strlen(str + 1) + 1;
}
int my_strlen1(char* str)
{
	int n = 0;
	while (*str != '\0')
	{
		str++;
		n++;

	}
	return n;
}

int main()
{
	char str[] = { "abcdef" };
	int ret = my_strlen(str);
	int ret1 = my_strlen1(str);
	printf("%d\n", ret);
	printf("%d\n", ret1);
	system("pause");
	return 0;
}