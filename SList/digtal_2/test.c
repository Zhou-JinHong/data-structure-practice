#include"SList.h"


void TestList1()
{
	//创建链表
	SListNode* n1 = SLcreat();
	SListNode* n2 = SLcreat();
	SListNode* n3 = SLcreat();
	SListNode* n4 = SLcreat();


	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;
	
	SListPrint(n1);

	SListPushBack(&n1, 5);
	SListPushBack(&n1, 6);
	SListPushBack(&n1, 7);
	SListPrint(n1);

	SListPushFront(&n1, 0);
	SListPrint(n1);

	SListPopBack(&n1);
	SListPrint(n1);

	SListPopFront(&n1);
	SListPrint(n1);

	SListNode*ret = SListFind(n1, 2);
	if (ret != NULL)
	{
		printf("找到了\n");
	}
	else
	{
		printf("not found");
	}

	SListInsert(&n1, n3, 9);
	SListPrint(n1);

	SListErase(&n1, n2);
	SListPrint(n1);
}




int main()
{

	TestList1();
	return EXIT_SUCCESS;
}