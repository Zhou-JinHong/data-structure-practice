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
	printf("**********1、尾插   2、头插*************\n");
	printf("**********3、查找   4、删除*************\n");
	printf("**********5、修改   6、打印*************\n");
	printf("************* -1、退出 *****************\n");
	printf("****************************************\n");
}


int main(void)
{
	//testSeqList6();
	//将测试分为一个一个的函数来进行，写好几小段段调试一次，方便找出错误

	SL sl;
	SLInit(&sl);

	int option = -1;
	do
	{
		menu();//菜单，可有可无，重点是功能实现
		if (scanf("%d", &option) == EOF)
		{
			printf("scanf输入错误\n");
			break;
		}

		int val, pos;
		int y, z;
		switch (option)
		{
		case 1:
			printf("请连续输入你要尾插的数据，以0结束:>");
			scanf("%d", &val);
			while (val != 0)
			{
				SeqListPushBack(&sl, val);
				printf("请连续输入你要尾插的数据，以0结束:>");
				scanf("%d", &val);
			}
			break;
		case 2:
			printf("请连续输入你要头插的数据，以0结束:>");
			scanf("%d", &val);
			while (val != 0)
			{
				SeqListPushFront(&sl, val);
				scanf("%d", &val);
			}
			break;
		case 3:
			printf("请输入你要查找的数:>");
			scanf("%d", &val);
			if (SeqListFind(&sl, val) != -1)
			{
				printf("你要找的数字是第%d个\n", SeqListFind(&sl, val));
			}
			break;
		case 4:
			printf("请输入你要删除的数字:>");
			scanf("%d", &val);
			SeqListErase(&sl, SeqListFind(&sl, val));
			break;
		case 5:
		printf("请输入你要修改的值和修改后的值,以空格隔开:>");
		scanf("%d %d", &y, &z);
		pos = SeqListFind(&sl, y);
		if (pos != -1)
		{
			SLModify(&sl, pos, z);
		}
		else
		{
			printf("没找到:%d\n", y);
		}
			break;
		case 6:
			SLprint(&sl);
			break;
		default:
			printf("输入错误,请重新输入\n");
			break;
		}
	} while (option != -1);

	SLDestory(&sl);

	return EXIT_SUCCESS;
}