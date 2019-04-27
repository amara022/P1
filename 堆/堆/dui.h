#include<stdio.h>
#include<stdlib.h>


/*void MyPrintf(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}

void heapify(int arr[], int size,int index)
{
	while (1)
	{
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		if (left >= size)
		{
			return;
		}
		int min = left;
		if (right < size && arr + right < arr + left)
			min = right;
		if (arr[min] >= arr[index])
				return;

		int tmp = arr[min];
		arr[min] = arr[index];
		arr[index] = tmp;
		index = min;
		}
	}
void creatHeap(int a[], int size) {
	for (int i = (size - 2) / 2; i >= 0; i--) 
	{
		heapify(a, size, i);
	}
}
typedef struct Heap {
	int arr[100];
	int size;
}	Heap;
void heapInit(Heap *heap,int arr[],int size)
{
	
	for (int i = 0; i < size; i++)
	{
		heap->arr[i] = arr[i];
	}
	heap->size = size;
	creatHeap(heap->arr, heap->size);
}
*/
// 时间复杂度 O(log(n))
void heapify(int a[], int size, int index) {
	// 先确定 index 是不是叶子结点
	// 先判断 index 有没有孩子
	// index 有没有左孩子
	// index 左孩子下标是否越界
	if (2 * index + 1 >= size) {
		// 是叶子，已经满足堆的性质，可以调整结束
		return;
	}

	// 找左右孩子中较小孩子的下标
	// 先假设较小的孩子是左孩子
	// 右孩子存在并且右孩子的值 小于 左孩子的值
	int min = 2 * index + 1;
	if (2 * index + 2 < size && a[2 * index + 2] < a[2 * index + 1]) {
		min = 2 * index + 2;
	}

	// 比较最小的孩子和 index 的值
	if (a[index] <= a[min]) {
		// 根的值比最小的孩子的值还小，已经满足堆的性质
		// 可以调整结束
		return;
	}

	// 交换最小孩子和根的值
	int t = a[min];
	a[min] = a[index];
	a[index] = t;

	// 继续调整 min 的位置
	heapify(a, size, min);
}

// 时间复杂度 O(n * log(n))
void createHeap(int a[], int size) {
	for (int i=(size - 1 - 1) / 2; i >= 0; i--) {
		heapify(a, size, i);
	}
}

typedef struct Heap {
	int array[100];
	int size;
}	Heap;

void HeapInit(Heap *heap, int a[], int size) {
	for (int i = 0; i < size; i++) {
		heap->array[i] = a[i];
	}
	heap->size = size;

	createHeap(heap->array, heap->size);
}

// 时间复杂度 O(log(n))
void adjustUp(int a[], int index) {
	while (index > 0) {
		if (index == 0) {
			return;
		}

		int parent = (index - 1) / 2;
		if (a[parent] <= a[index]) {
			return;
		}

		int t = a[parent];
		a[parent] = a[index];
		a[index] = t;

		index = parent;
	}
}

void HeapPush(Heap *heap, int val) {
	heap->array[heap->size++] = val;
	adjustUp(heap->array, heap->size - 1);
}

void HeapPop(Heap *heap) {
	assert(heap->size > 0);
	heap->array[0] = heap->array[heap->size - 1];
	heap->size--;

	heapify(heap->array, heap->size, 0);
}

int HeapTop(Heap *heap) {
	assert(heap->size > 0);

	return heap->array[0];
}
void test()
{
	int arr[] = { 8,9,6,5,3,4 };
	Heap *h = NULL;
	heapInit(h,arr, sizeof(arr) / sizeof(arr[0]));
	MyPrintf(arr, sizeof(arr) / sizeof(arr[0]));
	system("pause");
}