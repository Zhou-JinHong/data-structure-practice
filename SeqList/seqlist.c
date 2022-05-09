#include"SeqList.h"

//动态顺序表初始化函数实现
void SLInit(SL* psl)
{
	assert(psl);

	psl->a = NULL;
	psl->size = psl->capicity = 0;
}


//检查数组容量
void SLchackcapicity(SL* psl)
{
	assert(psl);

	int newcapicity = 0;
	if (psl->size == psl->capicity)
	{
		newcapicity = psl->capicity == 0 ? 4 : psl->capicity * 2;
		SLDataType* news = (SLDataType*)realloc(psl->a, newcapicity* sizeof(SLDataType));
		if (news == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		psl->a = news;
		psl->capicity = newcapicity;
	}


}

//打印顺序表
void SLprint(SL* psl)
{
	assert(psl);
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}


//尾插
void SeqListPushBack(SL* psl, SLDataType x)
{
#if 0
	assert(psl);

	SLchackcapicity(psl);//检查空间，防止越界问题

	psl->a[psl->size] = x;
	psl->size++;
#endif // 0

//调用插入函数
	SeqListInsert(psl, psl->size, x);
}

//尾删
void SeqListPopBack(SL* psl)
{
	assert(psl);

	SLchackcapicity(psl);

	//暴力检查
	assert(psl->size > 0);

	//温柔检查
	//if (psl->size == 0)
	//{
	//	printf("No digtal to be delete.");
	//	return;
	//}

	psl->size --;
}


//头插
void SeqListPushFront(SL* psl, SLDataType x)
{
#if 0
	assert(psl);

	SLchackcapicity(psl);

	int end = psl->size;
	while (end >= 0)
	{
		psl->a[end] = psl->a[end - 1];
		end--;
	}

	psl->a[0] = x;
	psl->size++;
#endif 


//由于插入函数的存在，头插函数可以直接调用
	SeqListInsert(psl, 0, x);

}


//头删
void SeqListPopFront(SL* psl)
{
#if 0
	assert(psl);
	assert(psl->size > 0);

	int begin = 0;
	while (begin < psl->size - 1)
	{

		psl->a[begin] = psl->a[begin + 1];
		begin++;
	}
	psl->size--;
#endif

//由于删除函数的存在，头删函数可以直接调用
	

}

//查找
int SeqListFind(SL* psl, SLDataType x)
{
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

//插入
void SeqListInsert(SL* psl, int pos, SLDataType x)
{
	assert(psl);
	
	SLchackcapicity(psl);


	int end = psl->size;
	while (pos < end)
	{
		psl->a[end] = psl->a[end - 1];
		end--;
	}
	psl->a[pos] = x;
	psl->size++;
}


//删除
void SeqListErase(SL* psl, int pos)
{
	assert(psl);

	SLchackcapicity(psl);

	int start = pos;
	while (start < psl->size - 1)
	{
		psl->a[start] = psl->a[start + 1];
		start++;
	}
	psl->size--;
}

//修改
void SLModify(SL* psl, int pos, SLDataType x)
{
	assert(psl);
	assert(pos > 0 && pos < psl->size);

	SLchackcapicity(psl);

	psl->a[pos] = x;
}

//销毁
void SLDestory(SL* ps)
{
	assert(ps != NULL);

	if (ps->a)
	{
		free(ps->a);
		ps->a = NULL;
		ps->capicity = ps->size = 0;
	}
}