#include"heap.h"


void Test()//��
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


void HeapSortTest()//������
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int n = sizeof(a) / sizeof(a[0]);

	//����
	//��1�����ϵ�������  
	//for (int i = 0; i < n; i++)
	//{
	//	AdjustUp(a, i);
	//}

	//���������µ������� 
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}

	//����
	//���򽨴�ջ
	//����Сջ
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
	//����һ�����彨��
	//���ַ�������������ѣ�С����С��
	for (int i = (size - 1 - 1) / 2; i > 0; i--)
	{
		AdjustDwon(a, size, i);
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ",a[i]);
		HeapPop(a);
	}

	//����������ǰk������
	HPDataType* KMinHeap = (HPDataType*)malloc(sizeof(HPDataType) * k);
	assert(KMinHeap);
	//ȡ��ǰk����
	for (int i = 0; i < k; i++)
	{
		KMinHeap[i] = a[i];
	}
	//����
	for (int i = (k - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(KMinHeap, k, i);
	}
	//��ʣ�µ�size-k�����Ƚϣ����ھ����
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

//topk����
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