#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//��̬˳���
/*#define  N  10
typedef int SLDataType;

typedef struct seqlist
{
	SLDataType a[N];
	int size;
}SL;
*/
//ȱ�㣺N��ֵд���ˣ��������޸ģ����N�����˷��ڴ棬NС�˻ᵼ��Խ����ʣ�����������Ҫ��̬˳���

//��̬˳���
typedef int SLDataType;//Ϊ����Ķ�˳���洢���������ͣ��������������������

//��̬˳�������ʵ��
typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capicity;
}SL;

//��̬˳����ʼ��
void SLInit(SL* psl);//ע�⣺����Ҫ�Ķ����飬Ҫʹ�ô�ַ����
void SLchackcapicity(SL* psl);//����������������˾�����
//��ӡ˳������ڲ���
void SLprint(SL* psl);

//��˳�������Ҫʵ�ֵĹ�������ɾ��ģ���ɾ����ͷ��ͷɾβ��βɾ

//β��
void SeqListPushBack(SL* psl, SLDataType x);

//βɾ
void SeqListPopBack(SL* psl);

//ͷ�� 
void SeqListPushFront(SL* psl, SLDataType x);

//ͷɾ
void SeqListPopFront(SL* psl);

//����
int SeqListFind(SL* psl, SLDataType x);

//����
void SeqListInsert(SL* psl, int pos, SLDataType x);

//ɾ��
void SeqListErase(SL* psl, int pos);

//�޸�
void SLModify(SL* psl, int pos, SLDataType x);

//����
void SLDestory(SL* ps);