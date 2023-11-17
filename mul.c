#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with
 * the top element of the stack
 * @stack: top of the stack
 * @line_number: line number of the file
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",
			line_number);
		free(resources.line);
		fclose(resources.file_handle);
		if (*stack)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
