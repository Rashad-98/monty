#include "monty.h"

/**
 * pall - prints all the values on the stack
 * @stack: top of stack
 * @line_number: line number
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!*stack)
		return;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
