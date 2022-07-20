#include"Tree.h"

int main(void)
{
	BTNode* root = CreatBinaryTree();
	PreOrder(root);
	printf("\n");

	int size = TreeSize2(root);
	printf("TreeSize is :%d\n", size);

	printf("TreeKLevel is:%d\n", TreeKLevel(root, 2));
	printf("TreeKLevel is:%d\n", TreeKLevel(root, 3));
	printf("TreeKLevel is:%d\n", TreeKLevel(root, 4));

	printf("TreeDepth is:%d\n", TreeDepth(root));

	BTNode* ret = TreeFind(root, 6);
	if(ret)
		printf("%d \n", ret->data);

	LevelOrder(root);

	TreeDstory(root);
	root = NULL;

	return 0;
}