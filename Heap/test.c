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

int main(void)
{
	//Test();
	HeapSortTest();

	return 0;
}