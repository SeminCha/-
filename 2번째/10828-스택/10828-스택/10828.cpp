#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define STACK_LEN 10000

typedef int Data;

typedef struct _arrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
}ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);
void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

void StackInit(Stack * pstack)
{
	pstack->topIndex = -1;
}

int SIsEmpty(Stack * pstack)
{
	if (pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)
{
	(pstack->topIndex)++;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack * pstack)
{
	int rIndex;

	if (SIsEmpty(pstack))
	{
		return -1;
	}

	rIndex = pstack->topIndex;
	(pstack->topIndex)--;

	return pstack->stackArr[rIndex];
}

Data SPeek(Stack * pstack)
{
	if (SIsEmpty(pstack))
	{
		return -1;
	}

	return pstack->stackArr[pstack->topIndex];
}

int main(void)
{
	Stack stack;
	StackInit(&stack);

	int num, pushNum;
	char input[10];
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%s", input);

		if (!strcmp(input, "push"))
		{
			scanf("%d", &pushNum);
			SPush(&stack, pushNum);
		}
		else if (!strcmp(input, "pop"))
		{
			printf("%d\n", SPop(&stack));
		}
		else if (!strcmp(input, "size"))
		{
			printf("%d\n", stack.topIndex + 1);
		}
		else if (!strcmp(input, "empty"))
		{
			printf("%d\n", SIsEmpty(&stack));
		}
		else if (!strcmp(input, "top"))
		{
			printf("%d\n", SPeek(&stack));
		}		
	}

	return 0;
}