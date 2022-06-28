#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

//void ListInit(LTNode** pphead);
LTNode* ListInit();//初始化

void ListPrint(LTNode* phead);//打印
void ListPushBack(LTNode* phead, LTDataType x);//尾插
void ListPushFront(LTNode* phead, LTDataType x);//头插
void ListPopBack(LTNode* phead);//尾删
void ListPopFront(LTNode* phead);//头删
void ListFind(LTNode* phead, LTDataType x);//查找


//在pos位置前插入x
void ListInert(LTNode* pos ,LTDataType x);
//删除pos位置处的节点
void ListErase(LTNode* pos);

//销毁链表
void ListDistory(LTNode* phead);