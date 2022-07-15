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

int main(void)
{
	//Test();
	HeapSortTest();

	return 0;
}