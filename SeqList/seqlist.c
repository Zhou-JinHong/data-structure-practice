#include"SeqList.h"

//��̬˳����ʼ������ʵ��
void SLInit(SL* psl)
{
	assert(psl);

	psl->a = NULL;
	psl->size = psl->capicity = 0;
}


//�����������
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

//��ӡ˳���
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


//β��
void SeqListPushBack(SL* psl, SLDataType x)
{
#if 0
	assert(psl);

	SLchackcapicity(psl);//���ռ䣬��ֹԽ������

	psl->a[psl->size] = x;
	psl->size++;
#endif // 0

//���ò��뺯��
	SeqListInsert(psl, psl->size, x);
}

//βɾ
void SeqListPopBack(SL* psl)
{
	assert(psl);

	SLchackcapicity(psl);

	//�������
	assert(psl->size > 0);

	//������
	//if (psl->size == 0)
	//{
	//	printf("No digtal to be delete.");
	//	return;
	//}

	psl->size --;
}


//ͷ��
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


//���ڲ��뺯���Ĵ��ڣ�ͷ�庯������ֱ�ӵ���
	SeqListInsert(psl, 0, x);

}


//ͷɾ
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

//����ɾ�������Ĵ��ڣ�ͷɾ��������ֱ�ӵ���
	

}

//����
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

//����
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


//ɾ��
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

//�޸�
void SLModify(SL* psl, int pos, SLDataType x)
{
	assert(psl);
	assert(pos > 0 && pos < psl->size);

	SLchackcapicity(psl);

	psl->a[pos] = x;
}

//����
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