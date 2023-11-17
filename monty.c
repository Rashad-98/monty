#include "monty.h"

void keine_etwas(void);
resources_t resources;

/**
 * main - entry point to monty interpreter
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
	size_t n = 0;
	ssize_t cnt = 0;
	unsigned int line_number = 1;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	resources.file_handle = fopen(*(argv + 1), "r");
	if (resources.file_handle == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", *(argv + 1));
		return (EXIT_FAILURE);
	}

	while (1)
	{
		cnt = getline(&(resources.line), &n, resources.file_handle);
		if (cnt == -1)
		{
			free(resources.line);
			break;
		}
		handle_instruction(resources.line, line_number, &head);
		free(resources.line);
		resources.line = NULL;
		n = 0;
		line_number++;
	}
	free_stack(head);
	fclose(resources.file_handle);
	return (EXIT_SUCCESS);
}
