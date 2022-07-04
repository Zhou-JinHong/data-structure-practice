#include"Stack.h"

void test()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	for (int i = 0; i < s.top; i++)
	{
		printf("%d ", s.a[i]);
	}
	printf("\n");

	StackPop(&s);
	StackPop(&s);
	for (int i = 0; i < s.top; i++)
	{
		printf("%d ", s.a[i]);
	}
	printf("\n");

}

int main(void)
{
	test();
	return 0;
}