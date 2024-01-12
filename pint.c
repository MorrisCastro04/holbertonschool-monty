#include "monty.h"

/**
 * pint - prints the top value of the stack
 * @stack: double pointer to the head of stack
 * @line_number: line number of the opcode
 * Return: returns nothing
*/

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
