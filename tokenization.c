#include "monty.h"

/**
 * getTokens - gets tokens from delimeter
 * @ptr: pointer
 * @delim: delimeter of token
 * Return: returns tokens
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
		tokens[i] = malloc(strlen(token) + 1);
		if (tokens[i] == NULL)
		{
			dprintf(STDERR_FILENO, "Error: malloc failed");
			exit(EXIT_FAILURE);
		}
		strcpy(tokens[i], token);
		i++;
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	return (tokens);
}
