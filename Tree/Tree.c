#include"Tree.h"
#include"Queue.h"


BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	assert(node);

	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;

	return node1;
}

void PreOrder(BTNode* root)
{

	if (root == NULL)
	{
		printf("# ");
		return;
	}

	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BTNode* root)
{
	assert(root);

	if (root == NULL)
	{
		printf("# ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	assert(root);

	if (root == NULL)
	{
		printf("# ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}


//统计二叉树节点个数
//法一（多线程时无法使用）：
int count = 0;
void TreeSize1(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	count++;
	TreeSize1(root->left);
	TreeSize1(root->right);
}



//法二（最优）：看成左子树的节点个数和右子树的节点个数相加
int TreeSize2(BTNode* root)
{
	return root == NULL ?
		0 : TreeSize2(root->left) + TreeSize2(root->right) + 1;
}


//第k层节点个数:看成左子树的k-1层和右子树的k-1层节点个数相加
int TreeKLevel(BTNode* root, int k)
{
	assert(k >= 1);

	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}

	return TreeKLevel(root->left, k - 1) + TreeKLevel(root->right, k - 1);
}

//二叉树深度：左子树的深度和右子树深度大的那个加一
int TreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int leftdepth = TreeDepth(root->left) + 1;
	int rightdepth = TreeDepth(root->right) + 1;

	return leftdepth > rightdepth ? leftdepth : rightdepth;
}

//查找值为x的节点：用先序的思想先判断根节点，然后依次查找左子树和右子树
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->data == x)
	{
		return root;
	}

	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1)
		return ret1;

	BTNode* ret2 = TreeFind(root->right, x);
	if (ret2)
		return ret2;

	return NULL;
}

//层序遍历：借助队列先入先出的特性，用根节点把子节点入队
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%d ", front->data);

		if (front->left)
		{
			QueuePush(&q, front->left);
		}

		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	printf("\n");

	QueueDestroy(&q);
}

void TreeDstory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	TreeDstory(root->left);
	TreeDstory(root->right);
	free(root);
}
