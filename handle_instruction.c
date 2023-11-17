#include "monty.h"

/**
 * handle_instruction - handles instructions
 * @line: line containing instruction and its arguments
 * @line_number: line number in file
 * @head: top of stack
 */
void handle_instruction(char *line, unsigned int line_number, stack_t **head)
{
	char *token;
	int i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod}
	};

	if (line == NULL || *line == '\n')
		return;
	token = strtok(line, "	 \n");
	if (token == NULL)
		return;
	i = check_instruction(11, instructions, token);
	if (i == -1)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
		free(line);
		fclose(resources.file_handle);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	instructions[i].f(head, line_number);

}
