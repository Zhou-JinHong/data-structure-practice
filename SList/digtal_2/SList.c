#include"SList.h"



SListNode* SLcreat()
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	assert(newnode);
	return newnode;
}


//��ӡ����
void SListPrint(SListNode* phead)
{
	assert(phead);
	
	SListNode* cur = NULL;
	cur = phead;

	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");

}

//β��
void SListPushBack(SListNode** pphead, SLDataType x)
{
	if (pphead == NULL)
	{
		SListNode* newnode = SLcreat();
		pphead = &newnode;
		(*pphead)->data = x;
		(*pphead)->next = NULL;
	}

	SListNode* tail = *pphead;

	SListNode* newnode = SLcreat();
	newnode->data = x;

	while ((tail->next) != NULL)
	{
		tail = tail->next;
	}
	tail->next = newnode;
	newnode->next = NULL;
}

//ͷ��
void SListPushFront(SListNode** pphead, SLDataType x)
{

	if (pphead == NULL)
	{
		SListNode* newnode = SLcreat();
		pphead = &newnode;
		(*pphead)->data = x;
		(*pphead)->next = NULL;
	}

	SListNode** cur = pphead;
	SListNode* newnode = SLcreat();

	newnode->data = x;
	newnode->next = *pphead;
	*pphead = newnode;
}

//βɾ
void SListPopBack(SListNode** pphead)
{
	assert(pphead);

	SListNode* tail = *pphead;
	while ((tail->next)->next != NULL)
	{
		tail = tail->next;
	}
	free(tail->next);
	tail->next = NULL;
}

//ͷɾ
void SListPopFront(SListNode** pphead)
{
	assert(pphead);
	SListNode* head = *pphead;
	*pphead = (*pphead)->next;
	free(head);

}


//����
SListNode* SListFind(SListNode* phead,SLDataType x)
{
	while (phead != NULL)
	{
		if (phead->data == x)
		{
			return phead;
		}
		phead = phead->next;
	}
	return NULL;
}

//��posλ��֮ǰ����
void SListInsert(SListNode** pphead, SListNode* pos, SLDataType x)
{
	SListNode* newnode = SLcreat();
	newnode->data = x;
	newnode->next = pos;
	SListNode* cur = *pphead;
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	cur->next = newnode;
}

//ɾ��posλ�õ�ֵ
void SListErase(SListNode** pphead, SListNode* pos)
{
	SListNode* cur = *pphead;

	while (cur->next != pos)
	{
		cur = cur->next;
	}
	cur->next = pos->next;
	free(pos);
}