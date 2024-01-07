#include "monty.h"
/**
 * main - Execute the morty program
 * @argc: argument counter
 * @argv: argument vector
 * Return: if sucess 0 otherwise 1
 */

int main(int argc, char **argv)
{
	FILE *fd;
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, fd) > -1)
	{
		line_number++;
		get_opcode(&stack, line, line_number);
	}
	fclose(fd);
	free_stack(stack);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}
