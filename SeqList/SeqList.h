#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//静态顺序表
/*#define  N  10
typedef int SLDataType;

typedef struct seqlist
{
	SLDataType a[N];
	int size;
}SL;
*/
//缺点：N的值写死了，不方便修改，如果N大了浪费内存，N小了会导致越界访问，所以我们需要动态顺序表

//动态顺序表
typedef int SLDataType;//为方便改动顺序表存储的数据类型，将数组的类型重新命名

//动态顺序表类型实现
typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capicity;
}SL;

//动态顺序表初始化
void SLInit(SL* psl);//注意：由于要改动数组，要使用传址传递
void SLchackcapicity(SL* psl);//检查数组容量，满了就扩容
//打印顺序表，便于测试
void SLprint(SL* psl);

//对顺序表我们要实现的功能有增删查改，增删包括头插头删尾插尾删

//尾插
void SeqListPushBack(SL* psl, SLDataType x);

//尾删
void SeqListPopBack(SL* psl);

//头插 
void SeqListPushFront(SL* psl, SLDataType x);

//头删
void SeqListPopFront(SL* psl);

//查找
int SeqListFind(SL* psl, SLDataType x);

//插入
void SeqListInsert(SL* psl, int pos, SLDataType x);

//删除
void SeqListErase(SL* psl, int pos);

//修改
void SLModify(SL* psl, int pos, SLDataType x);

//销毁
void SLDestory(SL* ps);