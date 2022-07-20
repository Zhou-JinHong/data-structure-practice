#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

struct QueueNode;//ǰ������
typedef struct QueueNode* QDataType;


typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;


void QueueInit(Queue* pq);//��ʼ��
void QueueDestroy(Queue* pq);//���ٶ���
void QueuePush(Queue* pq, QDataType x);//���
void QueuePop(Queue* pq);//����
QDataType QueueFront(Queue* pq);//ȡ��ͷԪ��
QDataType QueueBack(Queue* pq);//ȡ��βԪ��
bool QueueEmpty(Queue* pq);//�ж϶����Ƿ�Ϊ��
int QueueSize(Queue* pq);//��ö��г���