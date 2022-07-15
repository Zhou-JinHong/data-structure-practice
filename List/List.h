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
LTNode* ListInit();//��ʼ��

void ListPrint(LTNode* phead);//��ӡ
void ListPushBack(LTNode* phead, LTDataType x);//β��
void ListPushFront(LTNode* phead, LTDataType x);//ͷ��
void ListPopBack(LTNode* phead);//βɾ
void ListPopFront(LTNode* phead);//ͷɾ
void ListFind(LTNode* phead, LTDataType x);//����


//��posλ��ǰ����x
void ListInert(LTNode* pos ,LTDataType x);
//ɾ��posλ�ô��Ľڵ�
void ListErase(LTNode* pos);

//��������
void ListDistory(LTNode* phead);