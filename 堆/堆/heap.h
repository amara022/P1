#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>



typedef int DataType;
typedef struct Heap
{
	DataType* _array;
	int _capacity;
	int _size;
}Heap;
void MyPrintf(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}
void InitHeap(Heap *hp, int *array, int size)
{
	assert(hp);
	hp->_size = size;
	hp->_capacity = 9;
	hp->_array = (DataType *)malloc(hp->_capacity*sizeof(DataType));
	if (hp->_array == NULL)
	{
		assert(0);
		return;
	}
	//将array中size*sizeof(HDataType)个字节拷贝到hp->data
	memcpy(hp->_array, array, size*sizeof(DataType));
}

void swap(DataType *x, DataType *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
//向下调整
void AdjustDown(Heap *hp, int parent)
{
	//结点i的左孩子为：2*i+1
	int child = (parent << 1) + 1;
	while (child < hp->_size)
	{
		//先保证有右孩子,然后获取左后孩子的最小值
		if (child + 1 < hp->_size && hp->_array[child] > hp->_array[child + 1])
		{
			child = child + 1;
		}
		//左后孩子的最小值和双亲比较，若双亲大，则与左右孩子的最小值交换
		if (hp->_array[parent] > hp->_array[child])
		{
			//交换
			swap(&hp->_array[child], &hp->_array[parent]);
			parent = child;
			child = (parent << 1) + 1;
		}
		else
		{
			return;
		}
	}
}
//创建堆
void CreatHeap(Heap *hp, int *array, int size)
{
	//从第一个非叶子结点开始调整
	//结点i的双亲为： i-1/2；
	int root = (size - 2) >> 1;
	for (root; root >= 0; root--)
	{
		//向下调整
		AdjustDown(hp, root);
	}
}

// 向堆中插入值为data的元素 
void CheakHeap(Heap* hp)
{
	int newcapacity = 0;
	DataType* new = NULL;
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		newcapacity = hp->_capacity * 2;
		new = (DataType*)realloc(hp->_array, newcapacity*sizeof(DataType));
		if (new == NULL)
		{
			assert(0);
			return;
		}
		hp->_capacity = newcapacity;
		hp->_array = new;
	}

}
void AdjustUp(Heap* hp, int index)
{
	while (index > 0)
	{
		if (index == 0)
			return;
		int parent = (index -1)/2;
		if (hp->_array[parent] > hp->_array[index])
			return;
		swap(&hp->_array[parent], &hp->_array[index]);
		index = parent;
	}
}
void InsertHeap(Heap* hp, DataType data)
{
	assert(hp);
	int root = 0;
	CheakHeap(hp);
	hp->_array[hp->_size++] = data;
	root = (hp->_size / 2) - 1;
	AdjustUp(hp, root);
}

// 删除堆顶元素 
void EraseHeap(Heap* hp)
{
	assert(hp);
	swap(&hp->_array[0], &hp->_array[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp, 0);
}

// 获取堆中有效元素个数 
int SizeHeap(Heap* hp)
{
	int count = 0;
	for (int i = 0; i < hp->_size; i++)
		count++;
	return count;
}

// 检测堆是否为空 
int EmptyHeap(Heap* hp)
{
	if (hp->_size == 0)
		return 0;
	else
		return 1;
}

// 获取堆顶元素 
DataType TopHeap(Heap* hp)
{
	assert(hp);
	return hp->_array[0];
}

// 销毁堆 
void DestroyHeap(Heap* hp)
{
	assert(hp);
	free(hp->_array);
	hp->_array = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}

DataType TopK(Heap* hp,int k,int arr[])
{
	for (int i = 0; i < k; i++)
	{
		arr[i] = hp->_array[i];
	}
	CreatHeap(&hp,arr,k);
	for (int i = k; i < hp->_size; i++)
	{
		if (hp->_array[i]>hp->_array[k])
		{
			swap(hp->_array[i], hp->_array[k]);
			AdjustDown(&hp, k);
		}
	}

}