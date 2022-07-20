#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int BTDataType;

typedef struct BTNode
{
	struct BTNode* left;
	struct BTNode* right;
	BTDataType data;
}BTNode;

BTNode* BuyNode(BTDataType x);
BTNode* CreatBinaryTree();
void PreOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);
void TreeSize1(BTNode* root);//�ڵ����
int TreeSize2(BTNode* root);
int TreeKLevel(BTNode* root, int k);//��k��ڵ����
int TreeDepth(BTNode* root);// ����������
BTNode* TreeFind(BTNode* root, BTDataType x);//����ֵΪx�Ľڵ�
void LevelOrder(BTNode* root);//�������
void TreeDstory(BTNode* root);//����