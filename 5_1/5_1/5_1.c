#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("***********************\n");
	printf("*******1.��ʼ��Ϸ******\n");
	printf("*******0.������Ϸ******\n");
	printf("***********************\n");
}
void play_game()
{
	int guess = 0;
	int n = rand() % 100 + 1;
	while (1)
	{
		printf("��������µ�����\n");
		scanf("%d", &guess);
		if (guess < n)
		{
			printf("��С�ˣ����ز�");
		}
		else if (guess>n)
		{
			printf("�´��ˣ����ز�");
		}
		else
		{
			printf("��ϲ�㣬�¶���\n");
			break;
		}
	}
}
int main()
{
	int a = 0;
	srand((unsigned int)time(NULL));
	do{
		menu();
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			//��ʼ��Ϸ
			play_game();
			break;
		case 0:
			//������Ϸ
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����������\n");
			break;
		}
		}while (a);

		system("pause");
		return 0;
}
