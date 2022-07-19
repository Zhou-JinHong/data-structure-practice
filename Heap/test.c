#include"heap.h"


void Test()//堆
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	HP hp;
	HeapInit(&hp);

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		HeapPush(&hp, a[i]);
	}

	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);
}


void HeapSortTest()//堆排序
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int n = sizeof(a) / sizeof(a[0]);

	//建堆
	//法1：向上调整建堆  
	//for (int i = 0; i < n; i++)
	//{
	//	AdjustUp(a, i);
	//}

	//法二：向下调整建堆 
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}

	//排序
	//升序建大栈
	//降序建小栈
	int end = n - 1;
	int i = 0;
	while (end > 0)
	{
		Swap(&a[i], &a[end]);
		AdjustDwon(a, end, i);
		end--;
	}

}

void PrintTopK(HPDataType* a,int size,int k)
{
	//方法一：整体建堆
	//这种方法，大数建大堆，小数建小堆
	for (int i = (size - 1 - 1) / 2; i > 0; i--)
	{
		AdjustDwon(a, size, i);
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ",a[i]);
		HeapPop(a);
	}

	//方法二：对前k个建堆
	HPDataType* KMinHeap = (HPDataType*)malloc(sizeof(HPDataType) * k);
	assert(KMinHeap);
	//取出前k个数
	for (int i = 0; i < k; i++)
	{
		KMinHeap[i] = a[i];
	}
	//建堆
	for (int i = (k - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(KMinHeap, k, i);
	}
	//用剩下的size-k个数比较，大于就入堆
	for (int i = k; i < size; i++)
	{
		if (a[i] > KMinHeap[0])
		{
			KMinHeap[0] = a[i];
			AdjustDwon(KMinHeap, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", KMinHeap[i]);
	}
}

//topk问题
void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	assert(a);
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[120] = 1000000 + 5;
	a[99] = 1000000 + 6;
	a[0] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;
	PrintTopK(a, n, 10);
}

int main(void)
{
	//Test();
	/*HeapSortTest();*/
	TestTopk();

	return 0;
}