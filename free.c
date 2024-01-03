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

    for (i = 0; tokens[i] != NULL; i++)
        free(tokens[i]);
    free(tokens);
}