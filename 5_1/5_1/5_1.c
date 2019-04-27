#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("***********************\n");
	printf("*******1.开始游戏******\n");
	printf("*******0.结束游戏******\n");
	printf("***********************\n");
}
void play_game()
{
	int guess = 0;
	int n = rand() % 100 + 1;
	while (1)
	{
		printf("请输入你猜的数字\n");
		scanf("%d", &guess);
		if (guess < n)
		{
			printf("猜小了，请重猜");
		}
		else if (guess>n)
		{
			printf("猜大了，请重猜");
		}
		else
		{
			printf("恭喜你，猜对了\n");
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
			//开始游戏
			play_game();
			break;
		case 0:
			//结束游戏
			printf("退出游戏\n");
			break;
		default:
			printf("请重新输入\n");
			break;
		}
		}while (a);

		system("pause");
		return 0;
}
