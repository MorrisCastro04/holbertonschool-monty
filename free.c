#include "monty.h"
/**
 * freeTokens - frees tokens
 * @tokens: pointer to a pointer char
 * Return: nothing
*/
void freeTokens(char **tokens)
{
	int i;

	if (tokens == NULL)
		return;

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}

	free(tokens);
}
/**
 * 
 * 
 * 
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