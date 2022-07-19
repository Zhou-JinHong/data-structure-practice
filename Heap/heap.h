#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<time.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capcity;
}HP;

void Swap(HPDataType* p1, HPDataType* p2);

void AdjustDwon(HPDataType* a, int size, int parent);
void AdjustUp(HPDataType* a, int child);

void HeapPrint(HP* php);
void HeapInit(HP* php);
void HeapDestroy(HP* php);
void HeapPush(HP* php, HPDataType x);
void HeapPop(HP* php);
HPDataType HeapTop(HP* php);
bool HeapEmpty(HP* php);
int HeapSize(HP* php);