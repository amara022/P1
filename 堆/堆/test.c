#include"heap.h"
#include<stdlib.h>
void test()
{
	int arr[] = { 12, 36, 52, 61, 32, 85, 54, 16, 92 };
	Heap hp;
	InitHeap(&hp, arr, sizeof(arr) / sizeof(arr[0]));
	TopK(&hp, 3,arr);
	MyPrintf(&hp);
	CreatHeap(&hp, arr, sizeof(arr) / sizeof(arr[0]));
	MyPrintf(&hp);
// 向堆中插入值为data的元素 

	InsertHeap(&hp, 9);
	MyPrintf(&hp);
	// 删除堆顶元素 
	EraseHeap(&hp);
	MyPrintf(&hp);
	// 获取堆中有效元素个数 
	int c = SizeHeap(&hp);
	printf("%个数为%d ", c);
	// 检测堆是否为空 
	EmptyHeap(&hp);

	// 获取堆顶元素 
	TopHeap(&hp);


}
int main()
{
	test();
	system("pause");
}