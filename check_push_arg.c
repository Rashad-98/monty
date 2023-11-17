#include "monty.h"

/**
 * check_push_arg - checks argument of push instruction
 * @arg: argument to be checked
 *
 * Return: 1 if valid, 0 otherwise
 */
int check_push_arg(char *arg)
{
	int i;

	for (i = 0; *(arg + i) != '\0'; i++)
	{
		if (i == 0 && *arg == '-')
			continue;
		if (!isdigit(*(arg + i)))
			return (0);
	}

	return (1);
}
