#include "monty.h"

/**
 * divide - divides the second top element of the stack by the top
 * element of the stack
 * @stack: top of the stack
 * @line_number: line number of file
 */
void divide(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",
			line_number);
		free(resources.line);
		fclose(resources.file_handle);
		if (*stack)
			free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(resources.line);
		fclose(resources.file_handle);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}
