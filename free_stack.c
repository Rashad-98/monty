#include "monty.h"

/**
 * free_stack - frees a linked list (stack)
 * @stack: stack to be freed
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	if (!stack)
		return;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
