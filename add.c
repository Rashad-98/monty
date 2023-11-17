#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: top of the stack
 * @line_number: line number in file
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		free(resources.line);
		fclose(resources.file_handle);
		if (*stack)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
