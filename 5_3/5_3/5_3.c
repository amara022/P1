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
		printf("���������룺");
		scanf("%s", password);
		if (0 == strcmp(password, "123456"))
		{
			printf("������ȷ\n");
			break;
		}
		else
		{
			printf("�����������������\n");
		}

	}
	if (3 == i)
		printf("������������˳�����");
	system("pause");
	return 0;
}