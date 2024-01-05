#include "monty.h"
/**
 * main - Execute the morty program
 * @argc: argument counter
 * @argv: argument vector
 * Return: if sucess 0 otherwise 1
*/
char **tokens = NULL;
int main(int argc, char **argv)
{
	char *cmd = NULL;
	size_t n = 0;
	FILE *fd;
	int lines, line_numbers = 0;
	stack_t *stack;

	/*Check if the correct number of command-line arguments is provided*/
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/*Attempt to open the specified file for reading*/
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/*Read lines from the file using getline until the end of file is reached*/
	while ((lines = getline(&cmd, &n, fd)) > -1)
	{
		line_numbers++;
		tokens = getTokens(cmd, " \n");
		if (tokens != NULL && tokens[0] != NULL)
		{
			if (strcmp(tokens[0], "push") == 0)
			{
				push(&stack, line_numbers, fd);
			}
			else if (strcmp(tokens[0], "pint") == 0)
			{
				pint(&stack, line_numbers, fd);
			}
			else if (strcmp(tokens[0], "pall") == 0)
			{
				pall(&stack, line_numbers, fd);
			}
			else if (strcmp(tokens[0], "pop") == 0)
			{
				pop(&stack, line_numbers, fd);
			}
			else if (strcmp(tokens[0], "swap") == 0)
			{
				swap(&stack, line_numbers, fd);
			}
			else if (strcmp(tokens[0], "add") == 0)
			{
				add(&stack, line_numbers, fd);
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_numbers, tokens[0]);
				fclose(fd);
				freeTokens(tokens);
				exit(EXIT_FAILURE);
			}
		}
	}
	/*Close the file after reading all lines*/
	fclose(fd);
	free(cmd);
	freeTokens(tokens);
	exit(EXIT_SUCCESS);
}
