#include "monty.h"
/**
 * main - Execute the morty program
 * @argc: argument counter
 * @argv: argument vector
 * Return: if sucess 0 otherwise 1
*/
int main(int argc, char **argv)
{
    char *cmd = NULL;
    size_t n = 0;
    FILE *fd;
    int lines, line_numbers = 0;

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
    }
    /*Close the file after reading all lines*/
    fclose(fd);
    exit(EXIT_SUCCESS);
}