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


//ͳ�ƶ������ڵ����
//��һ�����߳�ʱ�޷�ʹ�ã���
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



//���������ţ��������������Ľڵ�������������Ľڵ�������
int TreeSize2(BTNode* root)
{
	return root == NULL ?
		0 : TreeSize2(root->left) + TreeSize2(root->right) + 1;
}


//��k��ڵ����:������������k-1�����������k-1��ڵ�������
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

//��������ȣ�����������Ⱥ���������ȴ���Ǹ���һ
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

//����ֵΪx�Ľڵ㣺�������˼�����жϸ��ڵ㣬Ȼ�����β�����������������
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

//����������������������ȳ������ԣ��ø��ڵ���ӽڵ����
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
