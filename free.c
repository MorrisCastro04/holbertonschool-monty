#include "monty.h"
/**
 * 
 * 
 * 
 * 
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
