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
	int verification, line_number = 0;
	char *cmd = NULL;
	size_t buffer = 0;
	FILE *fd;
	void (*valid_fun)(stack_t **, unsigned int, FILE *);
	stack_t *stack = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((verification = getline(&cmd, &buffer, fd)) > -1)
	{
		line_number++;
		if (strcmp(cmd, "\n") == 0)
			continue;
		tokens = getTokens(cmd, " \n");
		if (tokens == NULL)
		{
			free(tokens);
			continue;
		}
		valid_fun = get_opcode(tokens[0]);
		valid_fun(&stack, line_number, fd);
		free(cmd);
		freeTokens(tokens);
		cmd = NULL;
		tokens = NULL;
	}
	free(cmd);
	free_stack(stack);
	fclose(fd);
	exit(EXIT_SUCCESS);
}
