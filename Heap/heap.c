#include"heap.h"



void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDwon(HPDataType* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)//小堆的情况
	{
		if (child + 1 < size && a[child + 1] < a[child])
		{
			child++;
		}

		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}

		else
		{
			break;
		}

	}
}

void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)//小堆的情况
	{
		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}


void HeapPrint(HP* php)
{
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}

void HeapInit(HP* php)
{
	assert(php);

	php->a = NULL;
	php->capcity = php->size = 0;
}

void HeapDestroy(HP* php)
{
	assert(php);

	free(php->a);
	php->size = php->capcity = 0;
}

void HeapPush(HP* php, HPDataType x)
{
	assert(php);

	if (php->size == php->capcity)
	{
		int newcapcity = php->capcity = 0 ? 4 : 2 * php->capcity;
		HPDataType* tmp = (HPDataType*)realloc(php->a, newcapcity * sizeof(HPDataType));

		if (tmp == NULL)
		{
			printf("realloc fail!");
			exit(-1);
		}

		php->capcity = newcapcity;
		php->a = tmp;
	}

	php->a[php->size] = x;
	php->size++;

	AdjustUp(php->a, php->size - 1);
}

void HeapPop(HP* php)
{
	assert(php);

	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	AdjustDwon(php->a, php->size, 0);
}


HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->a);

	return php->a[0];
}


bool HeapEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}

int HeapSize(HP* php)
{
	assert(php);

	return php->size;
}