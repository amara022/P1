#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int binary_search(int i, int arr[],int left,int right)
{
	

	
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (i < arr[mid])
		{
			right = mid - 1;
		}
		else if (i>arr[mid])
		{
			left = mid + 1;
		}
		else if (i = arr[mid])

		return mid;
	}
	if (left > right)
	{
		return -1;
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10};
	int i = 0;	
	scanf("%d", &i);
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0])-1;
	int ret = binary_search(i,arr,left,right);
	
	if ('-1' == ret)
		printf("找不到");
	else 
		printf("找到了，下标是：%d\n", ret);
	system("pause");
	return 0;
}