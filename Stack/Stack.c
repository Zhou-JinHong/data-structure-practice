#include"Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->top = 0;
	ps->capcity = 0;
}

void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->capcity == ps->top)
	{
		int newcapcity = ps->capcity == 0 ? 4 : 2 * ps->capcity;
		STDataType* new = (STDataType*)realloc(ps->a,newcapcity*sizeof(STDataType*));
		ps->capcity = newcapcity;
		if (new == NULL)
		{
			perror("realloc fail:");
			exit(-1);
		}
		else
		{
			ps->a = new;
		}
	}

	*(ps->a + ps->top) = data;
	//»òÕßÐ´³Éps->a[ps->top] = data;
	ps->top++;
}

void StackPop(Stack* ps)
{
	assert(ps);

	ps->a[ps->top - 1] = 0;
	ps->top--;
}

STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];
}

int StackSize(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->top;
}

int StackEmpty(Stack* ps)
{
	if (ps->a == NULL)
	{
		return 1;
	}
	if (ps->a != NULL)
	{
		return 0;
	}
}

void StackDestroy(Stack* ps)
{
	assert(ps);

	free(ps->a);
	ps->capcity = 0;
}