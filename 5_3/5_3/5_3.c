#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i = 0;
	char password[20] = {0};
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码：");
		scanf("%s", password);
		if (0 == strcmp(password, "123456"))
		{
			printf("输入正确\n");
			break;
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}

	}
	if (3 == i)
		printf("三次密码均错，退出程序");
	system("pause");
	return 0;
}