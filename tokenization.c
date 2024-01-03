#include "monty.h"
/**
 * 
 * 
 * 
 * 
*/
char **getTokens(char *ptr, char *delim)
{
    char *token = NULL, **tokens;
    int i = 0;

    /*create space for the tokens*/
    tokens = malloc(sizeof(char *) * 10);
    if (tokens == NULL)
    {
        dprintf(STDERR_FILENO, "Error: malloc failed");
        exit(EXIT_FAILURE);
    }
    /*tokenize the input string*/
    token = strtok(ptr, delim);

    while (token)
    {
        /*create space to each token*/
        tokens[i] = malloc(sizeof(char) * strlen(token) + 1);
        if (tokens[i] == NULL)
        {
            dprintf(STDERR_FILENO, "Error: malloc failed");
            exit(EXIT_FAILURE);
        }
        tokens[i] = token;
        i++;
        token = NULL;
        /*go to the next token*/
        token = strtok(NULL, delim);
    }
    tokens[i] = NULL;
    free(token);
    return(tokens);
}