#include "List.h"

LTNode* BuyListNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

//void ListInit(LTNode** pphead)
//{
//	*pphead = BuyListNode(-1);
//	(*pphead)->next = *pphead;
//	(*pphead)->prev = *pphead;
//}

LTNode* ListInit()
{
	LTNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void ListPrint(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* newnode = BuyListNode(x);
	LTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;

}

void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* newnode = BuyListNode(x);
	LTNode* next = phead->next;

	// phead newnode next
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = next;
	next->prev = newnode;
}

//void ListPushFront(LTNode* phead, LTDataType x)
//{
//	assert(phead);
//
//	LTNode* newnode = BuyListNode(x);
//
//	phead->next->prev = newnode;
//	newnode->next = phead->next;
//
//	phead->next = newnode;
//	newnode->prev = phead;
//}

void ListPopBack(LTNode* phead)
{
	assert(phead);

	assert(phead->next != phead);
	//assert(!ListEmpty(phead));

	LTNode* tail = phead->prev;
	LTNode* tailPrev = tail->prev;

	free(tail);

	tailPrev->next = phead;
	phead->prev = tailPrev;
}

void ListPopFront(LTNode* phead)
{
	assert(phead);

	LTNode* newhead = phead->next->next;

	free(phead->next);

	phead->next = newhead;
	newhead->prev = phead;
}

void ListInert(LTNode* pos, LTDataType x)
{
	LTNode* newprev = pos->prev;
	LTNode* newnode = BuyListNode(x);

	newprev->next = newnode;
	newnode->next = pos;
	newnode->prev = newprev;
	pos->prev = newnode;
}

void ListErase(LTNode* pos)
{
	assert(pos);
	assert(pos->next != pos);

	LTNode* next = pos->next;
	LTNode* prev = pos->prev;

	next->prev = prev;
	prev->next = next;
	free(pos);
}

void ListFind(LTNode* phead, LTDataType x)
{
	LTNode* cur = phead->next;
	while (cur != cur->next)
	{
		if (cur->data = x)
		{
			return cur;
		}
	}
	return NULL;
}


void ListDistory(LTNode* phead)
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		ListErase(cur);
		cur = next;
		next = next->next;
	}

	free(phead);
}