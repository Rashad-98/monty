#include "monty.h"

/**
 * check_instruction - checks the validity of instructions
 * @insc: instructions count
 * @instructions: array conaiting available instructions
 * @instruction: instruction to check
 *
 * Return: index of instruction in instructions, or -1 for invalid instruction
 */
int check_instruction(int insc, instruction_t *instructions, char *instruction)
{
	int i;

	if (insc == 0 || !instructions || !instruction)
		return (-1);

	for (i = 0; i < insc; i++)
	{
		if (strcmp(instruction, instructions[i].opcode) == 0)
			return (i);
	}

	return (-1);
}
