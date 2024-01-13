#include "monty.h"

/**
 * add - adds two elemnents of the stack
 * @stack: double pointer to the head of stack
 * @line_number: line number of opcode
 * Return: nothing
*/

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	(*stack)->n = sum;
	free(temp);
}
