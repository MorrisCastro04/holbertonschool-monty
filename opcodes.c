#include "monty.h"
/**
 * 
 * 
 * 
 * 
*/
void push(stack_t **stack, unsigned int line_number, FILE *fd)
{
    stack_t *new_stack;

    if (stack == NULL)
    {
        fclose(fd);
        dprintf(STDERR_FILENO, "L%d: unknown instruction push integer", line_number);
        exit(EXIT_FAILURE);
    }
    /*create space to the new stack*/
    new_stack = malloc(sizeof(stack_t));
    if (new_stack == NULL)
    {
        fclose(fd);
        dprintf(STDERR_FILENO, "L%d: unknown instruction push integer", line_number);
        exit(EXIT_FAILURE);
    }
    /*change the number to a integer*/
    new_stack->n = atoi(tokens[1]);
    /*add pointers to the new stack*/
    new_stack->next = *stack;
    new_stack->prev = NULL;
    if (*stack != NULL)
        (*stack)->prev = new_stack;
    *stack = new_stack;

}
/**
 * 
 * 
 * 
 * 
 * 
*/
void pall(stack_t **stack, unsigned int line_numbers, FILE *fd)
{
    stack_t *current;

    /*check if the stack is empty*/
    if (stack == NULL || *stack == NULL)
    {
        fclose(fd);
        dprintf(STDERR_FILENO, "L%d: unknown instruction pall", line_numbers);
        exit(EXIT_FAILURE);
    }
    current = *stack;
    /*run in the stack to print every integer*/
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
