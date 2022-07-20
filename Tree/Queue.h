#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

struct QueueNode;//前置声明
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


void QueueInit(Queue* pq);//初始化
void QueueDestroy(Queue* pq);//销毁队列
void QueuePush(Queue* pq, QDataType x);//入队
void QueuePop(Queue* pq);//出队
QDataType QueueFront(Queue* pq);//取队头元素
QDataType QueueBack(Queue* pq);//取队尾元素
bool QueueEmpty(Queue* pq);//判断队列是否为空
int QueueSize(Queue* pq);//获得队列长度