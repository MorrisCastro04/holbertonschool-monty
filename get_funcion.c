#include "monty.h"
/**
 * get_opcode - funcion pointer to know what opcode use
 * @stack: structure that is getting the push number
 * @line: command to compare with the opcodes
 * @line_number: the number of the line where is the opcode
 * Return: the funcion to be execute
 */
void get_opcode(stack_t **stack, char *line, unsigned int line_number)
{
	char *cmd = strtok(line, " \t\n");
	int i;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"pint", pint},
		{"nop", nop},
		{NULL, NULL}};

	for (i = 0; op[i].opcode; i++)
	{
		if (!strcmp(cmd, op[i].opcode))
		{
			if (!strcmp(cmd, "push"))
			{
				char *arg = strtok(NULL, " \t\n");

				if (!Integer_check(arg))
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				op[i].f(stack, atoi(arg));
			}
			else
				op[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, cmd);
	exit(EXIT_FAILURE);
}
