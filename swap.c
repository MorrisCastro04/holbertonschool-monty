#include "monty.h"

/**
 * swap - swap two elements in the stack
 * @stack: double pointer to head of stack
 * @line_number: line number of opcode
 * Return: return nothing
*/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;

	(*stack)->next = temp->next;
	temp->next = *stack;

	temp->prev = NULL;
	(*stack)->prev = temp;

	*stack = temp;
}


