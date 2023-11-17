#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: top of the stack
 * @line_number: line number in file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		free(resources.line);
		fclose(resources.file_handle);
		if (*stack)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
