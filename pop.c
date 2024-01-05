#include "monty.h"

/**
 * pop - removes top node from stack
 * @stack: double pointer to head of stack
 * @line_number: line number of opcode
 * @fd: file descriptor
 * Return: nothing
*/

void pop(stack_t **stack, unsigned int line_number, FILE *fd)
{
	stack_t *top;

	top = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(fd);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;

	free(top);
}


