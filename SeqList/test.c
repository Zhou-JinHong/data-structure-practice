#include"SeqList.h"

void testSeqList1()
{
	SL s;
	SLInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SLprint(&s);

	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SLprint(&s);
}

void testSeqList2()
{
	SL s;
	SLInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SLprint(&s);

	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 0);
	SLprint(&s);

	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SLprint(&s);

	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 10);
	SLprint(&s);
}

void testSeqList3()
{
	SL s;
	SLInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SLprint(&s);

	SeqListPopBack(&s);
	SLprint(&s);
}

void testSeqList4()
{
	SL s;
	SLInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SLprint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SLprint(&s);
}

void testSeqList5()
{
	SL s;
	SLInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SLprint(&s);

	int des = SeqListFind(&s, 2);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SLprint(&s);

}

void testSeqList6()
{
	SL s;
	SLInit(&s);
	SeqListInsert(&s, 0, 0);
	SeqListInsert(&s, 1, 1);
	SLprint(&s);


	int pos = SeqListFind(&s, 1);
	SeqListInsert(&s, pos, 2);
	SLprint(&s);


	SeqListErase(&s, 1);
	SLprint(&s);
}

void testSeqList7()
{
	SL s;
	SLInit(&s);
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 3);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 5);
	SLprint(&s);



	int pos = SeqListFind(&s, 1);
	SeqListInsert(&s, pos, 2);
	SLprint(&s);

	SLModify(&s, 4, 4);
	SLprint(&s);

	SeqListErase(&s, 1);
	SLprint(&s);
}

void menu()
{
	printf("****************************************\n");
	printf("**********1��β��   2��ͷ��*************\n");
	printf("**********3������   4��ɾ��*************\n");
	printf("**********5���޸�   6����ӡ*************\n");
	printf("************* -1���˳� *****************\n");
	printf("****************************************\n");
}


int main(void)
{
	//testSeqList6();
	//�����Է�Ϊһ��һ���ĺ��������У�д�ü�С�ζε���һ�Σ������ҳ�����

	SL sl;
	SLInit(&sl);

	int option = -1;
	do
	{
		menu();//�˵������п��ޣ��ص��ǹ���ʵ��
		if (scanf("%d", &option) == EOF)
		{
			printf("scanf�������\n");
			break;
		}

		int val, pos;
		int y, z;
		switch (option)
		{
		case 1:
			printf("������������Ҫβ������ݣ���0����:>");
			scanf("%d", &val);
			while (val != 0)
			{
				SeqListPushBack(&sl, val);
				printf("������������Ҫβ������ݣ���0����:>");
				scanf("%d", &val);
			}
			break;
		case 2:
			printf("������������Ҫͷ������ݣ���0����:>");
			scanf("%d", &val);
			while (val != 0)
			{
				SeqListPushFront(&sl, val);
				scanf("%d", &val);
			}
			break;
		case 3:
			printf("��������Ҫ���ҵ���:>");
			scanf("%d", &val);
			if (SeqListFind(&sl, val) != -1)
			{
				printf("��Ҫ�ҵ������ǵ�%d��\n", SeqListFind(&sl, val));
			}
			break;
		case 4:
			printf("��������Ҫɾ��������:>");
			scanf("%d", &val);
			SeqListErase(&sl, SeqListFind(&sl, val));
			break;
		case 5:
		printf("��������Ҫ�޸ĵ�ֵ���޸ĺ��ֵ,�Կո����:>");
		scanf("%d %d", &y, &z);
		pos = SeqListFind(&sl, y);
		if (pos != -1)
		{
			SLModify(&sl, pos, z);
		}
		else
		{
			printf("û�ҵ�:%d\n", y);
		}
			break;
		case 6:
			SLprint(&sl);
			break;
		default:
			printf("�������,����������\n");
			break;
		}
	} while (option != -1);

	SLDestory(&sl);

	return EXIT_SUCCESS;
}