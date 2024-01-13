#include "monty.h"
/**
 * pall - prints all the values of the stack from the top
 * @stack: double pointer to the head of stack
 * @line_number: line number of opcode
 * Return: nothing
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
