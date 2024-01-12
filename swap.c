#include "monty.h"

/**
 * swap - swap two elements in the stack
 * @stack: double pointer to head of stack
 * @line_number: line number of opcode
 * Return: return nothing
*/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	top = *stack;
	second = (*stack)->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top->next = second->next;
	second->prev = top->prev;

	if (top->next != NULL)
		top->next->prev = top;

	if (second->prev != NULL)
		second->prev->next = second;

	top->prev = second;
	second->next = top;


	if (*stack == top)
		*stack = second;
}


