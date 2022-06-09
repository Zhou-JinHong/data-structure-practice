#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int SLDataType;

typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SListNode;


SListNode* SLcreat();//创建新节点
void SListPrint(SListNode* phead);//打印链表
void SListPushBack(SListNode** pphead, SLDataType x);//尾插
void SListPushFront(SListNode** pphead, SLDataType x);//头插
void SListPopBack(SListNode** pphead);//尾删
void SListPopFront(SListNode** pphead);//头删
SListNode* SListFind(SListNode* phead, SLDataType x);//查找

//在pos位置前插入
void SListInsert(SListNode** pphead, SListNode* pos, SLDataType x);

// 删除pos位置的值
void SListErase(SListNode** pphead, SListNode* pos);