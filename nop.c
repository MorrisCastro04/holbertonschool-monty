#include "monty.h"
/**
 *nop - don't do anything
 *@stack: double pointer to head of stack
 *@line_number: line number of opcode
 *@fd: file descriptor
 *Return: return nothing
 */
void nop(stack_t **stack, unsigned int line_number, FILE *fd)
{
	(void)stack;
	(void)line_number;
	(void)fd;
}
