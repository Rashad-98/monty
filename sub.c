#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the
 * second top element of the stack
 * @stack: top of the stack
 * @line_number: line number of file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
			line_number);
		free(resources.line);
		fclose(resources.file_handle);
		if (*stack)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	(*stack)->next->n -= tmp->n;
	*stack = (*stack)->next;
	free(tmp);
}
