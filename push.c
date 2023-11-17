#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: top of the stack
 * @line_number: line number in file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int arg_int;
	stack_t *tmp;

	arg = strtok(NULL, "	 \n");
	if (arg == NULL || check_push_arg(arg) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(resources.line);
		fclose(resources.file_handle);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	arg_int = atoi(arg);
	tmp = malloc(sizeof(*tmp));
	if (!tmp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(resources.line);
		fclose(resources.file_handle);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp->n = arg_int;
	tmp->prev = NULL;
	if (!*stack)
	{
		tmp->next = NULL;
		*stack = tmp;
	}
	else
	{
		tmp->next = *stack;
		*stack = tmp;
	}
}
