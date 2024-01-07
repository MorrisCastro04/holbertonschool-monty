#include "monty.h"
/**
 * free_stack - free the stack
 * @stack: the structure to free
 * Return: nothing
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = tmp->next;
		free(tmp);
	}
}
