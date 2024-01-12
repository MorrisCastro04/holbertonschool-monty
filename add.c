#include "monty.h"

/**
 * add - adds two elemnents of the stack
 * @stack: double pointer to the head of stack
 * @line_number: line number of opcode
 * Return: nothing
*/

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;
	int sum;

	top = *stack;
	second = (*stack)->next;
	sum = top->n + second->n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	second->n = sum;
	*stack = second;
	free(top);
}
