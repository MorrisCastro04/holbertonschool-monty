#include "monty.h"

/**
 * pop - removes top node from stack
 * @stack: double pointer to head of stack
 * @line_number: line number of opcode
 * Return: nothing
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	top = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top);
}


