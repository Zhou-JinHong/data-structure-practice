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


SListNode* SLcreat();//�����½ڵ�
void SListPrint(SListNode* phead);//��ӡ����
void SListPushBack(SListNode** pphead, SLDataType x);//β��
void SListPushFront(SListNode** pphead, SLDataType x);//ͷ��
void SListPopBack(SListNode** pphead);//βɾ
void SListPopFront(SListNode** pphead);//ͷɾ
SListNode* SListFind(SListNode* phead, SLDataType x);//����

//��posλ��ǰ����
void SListInsert(SListNode** pphead, SListNode* pos, SLDataType x);

// ɾ��posλ�õ�ֵ
void SListErase(SListNode** pphead, SListNode* pos);