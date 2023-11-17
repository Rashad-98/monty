#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: top of stack
 * @line_number: line number in file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free(resources.line);
		fclose(resources.file_handle);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
}
