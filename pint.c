#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: top of stack
 * @line_number: line number in file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free(resources.line);
		fclose(resources.file_handle);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
