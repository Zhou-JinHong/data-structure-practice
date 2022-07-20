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
void TreeSize1(BTNode* root);//节点个数
int TreeSize2(BTNode* root);
int TreeKLevel(BTNode* root, int k);//第k层节点个数
int TreeDepth(BTNode* root);// 求二叉树深度
BTNode* TreeFind(BTNode* root, BTDataType x);//查找值为x的节点
void LevelOrder(BTNode* root);//层序遍历
void TreeDstory(BTNode* root);//销毁