#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void reverse_string(char* string)
{
	int n = 0;
	char *p = string;
	while (*p++ != '\0')
	{
		n++;
	}
	if (n > 1)
	{
		int tmp = string[0];
		string[0] = string[n-1];
		string[n - 1] = '\0';
		reverse_string(string + 1);
		string[n - 1] = tmp;
	}
}
int main()
{
	char string[] = {0};
	scanf("%s", &string);
	reverse_string(string);
	printf("%s\n", string);
	system("pause");
	return 0;
}